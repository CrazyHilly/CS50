
-- Display the earliest flight on July 29 from Fiftyville
SELECT * FROM flights WHERE month = 7 AND day = 29 AND origin_airport_id IN (SELECT id FROM airports WHERE city = 'Fiftyville') ORDER BY hour, minute;

-- Display all passengers from the flight above
SELECT *
FROM passengers
WHERE flight_id IN
  (
    SELECT id
    FROM flights
    WHERE month = 7 AND day = 29 AND origin_airport_id IN
      (
        SELECT id
        FROM airports
        WHERE city = 'Fiftyville'
      )
  );

-- Display info about the thief and the flight they took
SELECT th.name, th.id, th.phone_number, th.passport_number, th.receiver, pas.flight_id
FROM
(
  SELECT *
  FROM
  (
    (
      (
        SELECT *
        FROM bakery_security_logs
        WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND activity = 'exit'
      ) AS bsl
        JOIN people AS p ON bsl.license_plate = p.license_plate
    ) AS p
      JOIN
      (
        SELECT *
        FROM phone_calls
        WHERE month = 7 AND day = 28
      ) AS ph ON ph.caller = p.phone_number AND ph.duration <= 120
  ) AS phc
  JOIN
  (
    SELECT *
    FROM phone_calls
    WHERE month = 7 AND day = 28
  ) AS phr ON phr.caller = phc.receiver
) AS th
  JOIN passengers AS pas ON pas.passport_number = th.passport_number AND flight_id IN
    (
      SELECT id
      FROM flights
      WHERE month = 7 AND day = 29 AND origin_airport_id IN
        (
          SELECT id
          FROM airports
          WHERE city = 'Fiftyville'
        )
    );



p.name, p.passport_number, phc.caller AS possible_thief, phc.receiver AS possible_accomplice

SELECT res.name AS thief, air.city AS escaped_to, p.name AS accomplice, res.receiver
FROM
(
SELECT *
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
) AS bank ON bank.passport_number = p.passport_number
  JOIN
  (
    SELECT *
    FROM
    (
      (
        SELECT *
        FROM bakery_security_logs
        WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND activity = 'exit'
      ) AS bsl
        JOIN people AS p ON bsl.license_plate = p.license_plate
    ) AS p
      JOIN
      (
        SELECT *
        FROM phone_calls
        WHERE month = 7 AND day = 28
      ) AS ph ON ph.caller = p.phone_number
  ) AS phc ON phc.passport_number = bank.passport_number
) AS res
    JOIN passengers AS pas ON pas.passport_number = res.passport_number
    JOIN flights AS f ON f.id = pas.flight_id AND f.day = 29
    JOIN airports AS air ON air.id = f.destination_airport_id
    JOIN people AS p ON p.phone_number = res.receiver;


res.name AS thief, air.city AS escaped_to, pres.name AS accomplice



SELECT p.name AS thief, pas.passport_number, p.id, air.city AS escaped_to, p2.name AS accomplice, f.hour
FROM (
  SELECT *
  FROM bakery_security_logs
  WHERE month = 7
  AND day = 28
  AND hour = 10
  AND minute >= 15
  AND minute <= 25 AND activity = 'exit'
  ) AS bsl
  JOIN people AS p ON bsl.license_plate = p.license_plate
  JOIN (
    SELECT *
    FROM phone_calls
    WHERE month = 7 AND day = 28
  ) AS ph ON ph.caller = p.phone_number AND ph.duration <= 60
  JOIN passengers AS pas ON pas.passport_number = p.passport_number
  JOIN flights AS f ON f.id = pas.flight_id AND f.day = 29
  JOIN airports AS air ON air.id = f.destination_airport_id
  JOIN people AS p2 ON p2.phone_number = ph.receiver
  JOIN (
    SELECT *
    FROM atm_transactions
    WHERE month = 7 AND day = 28 AND transaction_type = 'withdraw' AND atm_location = 'Leggett Street'
  ) AS atmt
  JOIN bank_accounts AS ba ON ba.account_number = atmt.account_number AND ba.person_id = p.id;