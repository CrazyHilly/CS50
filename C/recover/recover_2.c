#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    char *input_name = "card.raw";
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL)
    {
        printf("Could not open %s file.\n", argv[1]);
        return 1;
    }

    uint8_t buffer[512];
    int output_count = 0, output_written = 0;
    char output_name[8] = "000.jpg";
    FILE *output_file = fopen(output_name, "wb");
    int input_length = 0, file_count = 0, location = 0;

    while(1)
    {
        size_t input_read = fread(buffer, sizeof(uint8_t), sizeof(buffer), input_file);

    if (input_read == 0) {
        // No more data to read
        break;
    }

    // Check if we've found a new jpg
    if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0)) {
        // Close current file if it exists
        if (output_file != NULL) {
            fclose(output_file);
        }

        // Open a new file
        sprintf(output_name, "%03d.jpg", output_count++);
        output_file = fopen(output_name, "wb");
        if (output_file == NULL) {
            printf("Could not open file: %s\n", output_name);
            return 1;
        }
    }

    // If we have an open file, write to it
    if (output_file != NULL) {
        fwrite(buffer, sizeof(uint8_t), input_read, output_file);
    }
}

// Close the last file
if (output_file != NULL) {
    fclose(output_file);
}

    fclose(input_file);
}