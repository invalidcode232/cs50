from cs50 import get_int


def main():
    # Loop until valid input
    while True:
        # Get height
        height = get_int("Height: ")

        # Check for valid input
        if height < 1 or height > 8:
            pass
        else:
            break

    generate_pyramid(height)


def generate_pyramid(height):
    # Loop
    for i in range(height):
        # Skip
        i += 1

        for j in range(height - i):
            print(" ", end="")

        for k in range(i):
            print("#", end="")

        print("")


main()
