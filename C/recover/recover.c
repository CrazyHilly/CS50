#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    char *input_name = "test.raw";
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
    int output_count = 0, input_read = 0;
    char output_name[8];

    sprintf(output_name, "%03d.jpg", output_count);
    FILE *output_file = NULL;

    while (1)
    {
        input_read = fread(buffer, 1, 512, input_file);
        if (input_read == 0)
        {
            break;
        }

        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            if (output_file != NULL)
            {
                fclose(output_file);
            }

            if (output_count != 0)
            {
                sprintf(output_name, "%03d.jpg", output_count);
            }

            output_file = fopen(output_name, "wb");
            output_count++;
            if (output_count >= 1000)
            {
                printf("Too many files\n");
                return 1;
            }
        } 

        if (output_file != NULL)
        {
            fwrite(buffer, 1, input_read, output_file);
        }

        if (input_read < 512)
        {
            break;
        }
    }

    if (output_file != NULL)
    {
        fclose(output_file);
    }

    fclose(input_file);
}