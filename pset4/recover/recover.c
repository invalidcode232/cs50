#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check if user inputs the correct number of arguments
    if (argc != 2)
    {
        printf("Usage: ./recover filename\n");
        return 1;
    }

    // Try to open the file
    FILE *source = fopen(argv[1], "r");

    // If file not found, return
    if (source == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    BYTE buffer[512];
    FILE *output;
    int count = 0;
    while (fread(&buffer, sizeof(BYTE), 512, source) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count > 0)
            {
                fclose(output);
            }

            // Get file name
            char filename[8];
            sprintf(filename, "%03i.jpg", count);

            // Create new JPEG with the file name
            output = fopen(filename, "w");
            fwrite(&buffer, sizeof(BYTE), 512, output);

            // Increment file counter;
            count++;
        }
        else
        {
            // Check if we've found the first jpeg file already
            // If not yet, ignore rest of the code
            if (count == 0)
            {
                continue;
            }

            // Write block
            fwrite(&buffer, sizeof(BYTE), 512, output);
        }
    }

    fclose(source);
}