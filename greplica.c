#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char *pattern;
    char *filename;
    int count_only = 0;
    // Check argument count
    if (argc == 3)
    {
        pattern = argv[1];
        filename = argv[2];
    }
    else if (argc == 4 && strcmp(argv[1], "-c") == 0)
    {
        count_only = 1;
        pattern = argv[2];
        filename = argv[3];
    }
    else
    {
        printf("Usage: ./greplica [-c] <pattern> <filename>\n");
        exit(1);
    }

    // Open file
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("fopen");
        exit(1);
    }

    char line[1024];
    int match_count = 0;
    while (fgets(line, sizeof(line), file) != NULL)
    {
        // Strip the newline using strchr
        char *newline = strchr(line, '\n');
        if (newline)
            *newline = '\0';

        // Check if pattern is in the line using strstr
        if (strstr(line, pattern))
        {
            if (count_only)
            {
                match_count++; // Incrememt counter
            }
            else
            {
                printf("%s\n", line);
            }
        }
    }
    if (count_only)
    {
        printf("%d\n", match_count);
    }

    // Close and exit
    fclose(file);
    return 0;
}