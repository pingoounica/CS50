# TODO

from cs50 import get_float

# Use get_float from the CS50 Library to get the user’s input and print to output your answer. Assume that the only
# coins available are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).

count = 0
while True:
    change = get_float("Change owed: ")
    if change > 0:
        break
cent = round(change * 100)
# calculates quarters
while cent >= 25:
    cent = cent - 25
    count += 1
# calculates dimes
while cent >= 10:
    cent = cent - 10
    count += 1
# calculates nickels
while cent >= 5:
    cent = cent - 5
    count += 1
# calculates pennies
while cent >= 1:
    cent = cent - 1
    count += 1

print(count)
