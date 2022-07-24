#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint>

typedef uint8_t BYTE;

bool is_jpeg(BYTE * array);

int main(int argc, char *argv[])
{
    // Ensure only one command-line argument is given
    if (argc != 2)
    {
        printf("Usage: recover <filename>\n");
        return 1;
    }

    // Open the file
    FILE * mem_card = fopen(argv[1], "r");

    if (mem_card == NULL)
    {
        printf("Error: File could not be opened.\n");
        return 2;
    }

    BYTE *buffer = malloc(512); // Buffer is an array of bytes
    while (true)
    {
        // Read 512-byte blocks of the data
        if ((fread(buffer, 512, 1, mem_card)) < 1) // fread returns a number less then one if EOF is reached or an error occurs
        {
            break;
        }

        // Check whether the buffer is a JPEG
        if (is_jpeg(buffer))
    }

    // Free the buffer
    free(buffer);

    // Close the file
    fclose(mem_card);
}

bool is_jpeg(BYTE * array) // Take in an array of bytes
{
    // Return true if the buffer is JPEG
    if (
        array[0] == 0xff &&
        array[1] == 0xd8 &&
        array[2] == 0xff &&
        array[3] ==
    )
}