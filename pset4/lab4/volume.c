// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Define bytes
typedef uint8_t BYTE;
typedef int16_t BYTE16;

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    int count1 = 0;
    int count2 = 0;

    // Copy header from input file to output file
    BYTE bytes[HEADER_SIZE];
    fread(bytes, HEADER_SIZE, 1, input);
    fwrite(bytes, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file
    BYTE16 buffer2;
    while (fread(&buffer2, sizeof(BYTE16), 1, input))
    {
        buffer2 *= factor;
        fwrite(&buffer2, sizeof(BYTE16), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
