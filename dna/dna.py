import csv
import sys
# The program should require as its first command-line argument the name of a CSV file containing the STR counts for a list of
# individuals and should require as its second command-line argument the name of a text file containing the DNA sequence to identify.

if len(sys.argv) != 3:
    sys.exit("Usage: python dna.py data.csv sequente.txt")
check = True
strlist = []
people = []
# Your program should open the CSV file and read its contents into memory.
with open(sys.argv[1], "r") as STR:
    readstr = csv.reader(STR)
    for row in readstr:
        if check:
            strlist.append(row)
            check = False
        else:
            people.append(row)
slist = strlist[0]
slist.remove("name")
sequence = []
# Your program should open the DNA sequence and read its contents into memory.
with open(sys.argv[2], "r") as text:
    readtext = csv.reader(text)
    for i in readtext:
        sequence = i
text = sequence[0]
strdict = {}

for STR in slist:
    index = 0
    max     = 0
    while index < len(text):
        num_repeats = 0
        while STR == text[index:index+len(STR)]:
            num_repeats += 1
            index += len(STR)
        if num_repeats > max:
            max = num_repeats

        index += 1
    strdict[STR] = max
# If the STR counts match exactly with any of the individuals in the CSV file, your program should print out the name of the matching individual.
# You may assume that the STR counts will not match more than one individual.
# If the STR counts do not match exactly with any of the individuals in the CSV file, your program should print No match

check = False
for person in range(len(people)):
    for STR in range(len(slist)):
        if str(strdict[slist[STR]]) == str(people[person][STR+1]):
            check = True
        else:
            check = False
            break
    if check:
        print(people[person][0])
        break
if not check:
    print("no match")