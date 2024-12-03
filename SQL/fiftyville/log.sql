-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Display crime_scene_report table to get acquainted with the table
SELECT * FROM crime_scene_reports;

-- Display reports from 28th of July
SELECT street, description FROM crime_scene_reports WHERE month = 7 AND day = 28;

-- Display report from 28th of July which mentions CS50
SELECT street, description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND description LIKE '%CS50%';

-- Display interviews table to get acquainted with the table
SELECT * FROM interviews;

-- Limit above result to 10 to see the column titles
SELECT * FROM interviews LIMIT 10;

-- Display interviews from July 27
SELECT * FROM interviews WHERE month = 7 AND day = 28;

-- Display rows where "bakery" is mentioned (as specififed in the crime scene report)
SELECT name, transcript FROM interviews WHERE month = 7 AND day = 28 AND transcript LIKE '%bakery%';

-- Display all transactions on July 28
SELECT * FROM atm_transactions WHERE month = 7 AND day = 28;

-- Display withdrawal transactions from ATM on Leggett Street on July 28
SELECT * FROM atm_transactions WHERE month = 7 AND day = 28 AND transaction_type = 'withdraw' AND atm_location = 'Leggett Street';

-- Dispay bank_accounts and filtered above atm_transactions tables joined on account number
SELECT *
FROM
(
  SELECT *
  FROM atm_transactions
  WHERE month = 7 AND day = 28 AND transaction_type = 'withdraw' AND atm_location = 'Leggett Street'
) AS atmt
  JOIN bank_accounts AS ba ON ba.account_number = atmt.account_number;

-- Display above table joined with people table on person id
SELECT *
FROM
(
  SELECT *
  FROM atm_transactions
  WHERE month = 7 AND day = 28 AND transaction_type = 'withdraw' AND atm_location = 'Leggett Street'
) AS atmt
  JOIN bank_accounts AS ba ON ba.account_number = atmt.account_number
  JOIN people AS p ON p.id = ba.person_id;

-- Display info from bakery_security_logs from July 28, 10 a.m.
SELECT * FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10;

-- Display info from July 28 from bakery_security_logs about people leaving the bakery up to 10 min after the theft
SELECT * FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25 AND activity = 'exit';

-- Dispay useful columns from people and filtered above bakery_security_logs tables joined on license plate
SELECT p.name, p.phone_number, p.passport_number, p.license_plate, bsl.minute
FROM
(
  SELECT *
  FROM bakery_security_logs
  WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25 AND activity = 'exit'
) AS bsl
  JOIN people AS p ON bsl.license_plate = p.license_plate;

-- Display info about people who were on bakery's security camera and were withdrawing money from ATM
SELECT p.name, p.phone_number, p.passport_number, p.id, p.license_plate, bsl.minute
FROM
(
  SELECT *
  FROM bakery_security_logs
  WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25 AND activity = 'exit'
) AS bsl
  JOIN people AS p ON bsl.license_plate = p.license_plate
  JOIN
(
  SELECT *
  FROM
  (
    SELECT *
    FROM atm_transactions
    WHERE month = 7 AND day = 28 AND transaction_type = 'withdraw' AND atm_location = 'Leggett Street'
  ) AS atmt
    JOIN bank_accounts AS ba ON ba.account_number = atmt.account_number
    JOIN people AS p ON p.id = ba.person_id
) AS bank ON bank.passport_number = p.passport_number;

-- Display all phone calls from July 28
SELECT * FROM phone_calls WHERE month = 7 AND day = 28;

-- Display all short calls from people who exited bakery on July 28 after 10 a.m. and made short calls within 10 min after theft
SELECT p.name, p.passport_number, ph.caller, ph.receiver
FROM
(
  (
    SELECT *
    FROM bakery_security_logs
    WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25 AND activity = 'exit'
  ) AS bsl
    JOIN people AS p ON bsl.license_plate = p.license_plate
) AS p
  JOIN
  (
    SELECT *
    FROM phone_calls
    WHERE month = 7 AND day = 28
  ) AS ph ON ph.caller = p.phone_number AND ph.duration <= 60;


-- Display consolidated results
SELECT p.name AS thief, pas.passport_number, p.id, air.city AS escaped_to, p2.name AS accomplice, f.hour
  FROM
       (SELECT *
          FROM bakery_security_logs AS bsl
         WHERE bsl.month = 7
           AND bsl.day = 28
           AND bsl.hour = 10
           AND bsl.minute >= 15
           AND bsl.minute <= 25
           AND activity = 'exit') AS bsl
  JOIN people AS p
    ON bsl.license_plate = p.license_plate
  JOIN
        (SELECT *
          FROM phone_calls AS pc
          WHERE pc.month = 7
            AND pc.day = 28) AS pc
    ON pc.caller = p.phone_number
   AND pc.duration <= 60
  JOIN passengers AS pas ON pas.passport_number = p.passport_number
  JOIN flights AS f ON f.id = pas.flight_id AND f.day = 29
  JOIN airports AS air ON air.id = f.destination_airport_id
  JOIN people AS p2 ON p2.phone_number = pc.receiver
  JOIN
       (SELECT *
          FROM atm_transactions AS atmt
         WHERE atmt.month = 7
           AND atmt.day = 28
           AND transaction_type = 'withdraw'
           AND atm_location = 'Leggett Street') AS atmt
  JOIN bank_accounts AS ba
    ON ba.account_number = atmt.account_number
   AND ba.person_id = p.id;

-- According to witness, the thief wanted to leave the city with the first flight next day, which means that Bruce is a thief.