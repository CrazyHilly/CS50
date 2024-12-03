import csv
import requests
import datetime
import math


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    reader_list = list(reader)
    last_record = reader_list[-1]

    last_date = last_record["date"].split("-")
    last_date = [int(x) for x in last_date]
    last_date = datetime.date(last_date[0], last_date[1], last_date[2])

    first_date = last_date - datetime.timedelta(days=15)

    new_cases = {}

    for row in reader_list[::-1]:
        if row["date"] == str(first_date):
            break

        state = row["state"]
        current_cases = int(row["cases"])

        if state in new_cases:
            previous_index = len(new_cases[state]) - 1
            previous_cases = new_cases[state][previous_index]
            new_cases[state][previous_index] = previous_cases - current_cases
            if len(new_cases[state]) == 14:
                continue
            new_cases[state].append(current_cases)
        else:
            new_cases[state] = [current_cases]

    return new_cases


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    print("Seven-Day Averages")

    for state in states:
        average_last = math.ceil(sum(new_cases[state][:7]) / 7)
        average_previous = math.ceil(sum(new_cases[state][7:]) / 7)

        if average_previous != 0:
            percentage = round((average_last - average_previous) / average_previous * 100)

        if percentage > 0:
            print(f"{state} had a 7-day average of {average_last} and an increase of {percentage}%.")
        else:
            print(f"{state} had a 7-day average of {average_last} and a decrease of {abs(percentage)}%.")

main()
