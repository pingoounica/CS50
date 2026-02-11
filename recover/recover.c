#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //checks for one command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    //opens and reads file
    FILE *input_file = fopen(argv[1], "r");

    //checks if input is valid
    if (input_file == NULL)
    {
        printf("Could not open file");
        return 2;
    }

    //stores blocks of 512 into an array
    unsigned char buffer[512];

    //counts number of images created
    int count_image = 0;

    //pointer for recovered images
    FILE *output_file = NULL;

    //char filename[8]
    char *filename = malloc(8 * sizeof(char));

    //reads blocks of 512 bytes
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        //checks if bytes indicates JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //writes JPEG file names
            sprintf(filename, "%03i.jpg", count_image);

            //open output file to write
            output_file = fopen(filename, "w");

            //counts images found
            count_image++;
        }
        //checks if output has been used as valid input
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    free(filename);
    fclose(output_file);
    fclose(input_file);

    return 0;
}