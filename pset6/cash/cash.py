# Import get_float from cs50
from cs50 import get_float

# Loop until user provides valid input
while True:
    cash = get_float("Change owed: ")

    if cash > 0:
        break

coins = 0

# Convert decimals to round numbers
cash = round(cash * 100)

# Loop until coins = 0 while incrementing coins on the way
while cash >= 25:
    cash -= 25
    coins += 1

while cash >= 10:
    cash -= 10
    coins += 1

while cash >= 5:
    cash -= 5
    coins += 1

while cash >= 1:
    cash -= 1
    coins += 1

print(coins)