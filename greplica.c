#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char *pattern;
    char *filename;
    // Step 1: Check argument count
    if (argc == 3)
    {
        pattern = argv[1];
        filename = argv[2];
    }
    else
    {
        printf("Usage: ./greplica <pattern> <filename>\n");
        exit(1);
    }

    // Step 2: Store pattern and filename from argv

    // Step 3: Open file
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("fopen");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        // Step 4a: Strip the newline using strchr
        char *newline = strchr(line, '\n');
        if (newline)
            *newline = '\0';

        // Step 4b: Check if pattern is in the line using strstr
        if (strstr(line, pattern))
        {
            printf("%s\n", line);
        }

        // Step 4c: If match, print the line
    }

    // Step 5: Close and exit
    fclose(file);
    return 0;
}