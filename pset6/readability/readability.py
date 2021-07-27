# Import get_string from cs50 library
from cs50 import get_string

# Our main function


def main():
    text = get_string("Text: ")

    letters = get_letters(text)
    sentences = get_sentences(text)
    words = get_words(text)

    # Get l and s
    l = (letters * 100) / words
    s = (sentences * 100) / words

    # Calculate index
    index = 0.0588 * l - 0.296 * s - 15.8

    # Check if index is above 1 and below 16
    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print(f"Grade {round(index)}")

# Check if character is alphabet


def is_letter(char):
    return char.isalpha()

# Get letters in a text


def get_letters(text):
    letters = 0

    for i in text:
        if not is_letter(i):
            continue

        letters += 1

    return letters

# Get sentences in a text


def get_sentences(text):
    sentences = 0

    for i in text:
        if i == "." or i == "?" or i == "!":
            sentences += 1

    return sentences

# Get words


def get_words(text):
    return len(text.split())


main()
