import csv
import sys


def main():
    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: CSV TXT")

    # TODO: Read database file into a variable
    people = []
    with open(sys.argv[1]) as people_file:
        people_filereader = csv.DictReader(people_file)

        str_list = people_filereader.fieldnames[1:]
        str_count = len(str_list)

        for row in people_filereader:
            people.append(row)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as sequence_file:
        sequence = sequence_file.read()

    # TODO: Find longest match of each STR in DNA sequence
    sequence_by_str = {}
    for str in str_list:
        sequence_by_str[str] = longest_match(sequence, str)

    # TODO: Check database for matching profiles
    for person in people:
        count = 0
        for s in str_list:
            if sequence_by_str[s] != int(person[s]):
                break

            count += 1
            if count == str_count:
                print(person["name"])
                return

    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
