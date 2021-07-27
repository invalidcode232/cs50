# Import libraries
from cs50 import get_string


def main():
    # Get name
    name = get_string("What's your name?\n")

    # Print name
    print(f"hello, {name}")


main()