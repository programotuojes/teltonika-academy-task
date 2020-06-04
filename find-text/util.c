#define _XOPEN_SOURCE 500
#define _GNU_SOURCE

#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdbool.h>
#include "main.h"

char *text_to_find;
size_t text_to_find_length;
bool first_file = true;     // To print a newline after file path

void show_usage(char *program_name) {
    fprintf(stderr, "Usage: %s -f DIRECTORY -t TEXT\n", program_name);
    exit(EXIT_FAILURE);
}

void parse_args(int argc, char *argv[], char **dir, char **text) {
    if (argc != 5)
        show_usage(argv[0]);

    if (strcmp(argv[1], "-f") == 0 && strcmp(argv[3], "-t") == 0) {
        *dir = argv[2];
        *text = argv[4];
    } else if (strcmp(argv[1], "-t") == 0 && strcmp(argv[3], "-f") == 0) {
        *dir = argv[4];
        *text = argv[2];
    } else
        show_usage(argv[0]);

    text_to_find = *text;
    text_to_find_length = strlen(text_to_find);
}

void check_if_directory(char *dir) {
    struct stat sb;

    if (stat(dir, &sb) == -1) {
        perror(dir);
        exit(EXIT_FAILURE);
    }

    if (!S_ISDIR(sb.st_mode)) {
        fprintf(stderr, "%s: Not a directory\n", dir);
        exit(EXIT_FAILURE);
    }
}

void find_in_file(const char *path) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;

    if ((file = fopen(path, "r")) == NULL) {
        perror(path);
        return;
    }

    bool found = false;

    for (int line_num = 1; getline(&line, &len, file) != -1; line_num++) {
        char *substring = strstr(line, text_to_find);

        if (substring != NULL) {
            if (!found) {
                if (!first_file)
                    printf("\n");

                first_file = false;

                printf("File: %s\n", path);
            }

            found = true;
            long foundIndex = substring - line;

            printf("%3i | ", line_num);
            printf("%.*s", (int) foundIndex, line);
            printf("\033[0;31m");
            printf("%.*s", (int) text_to_find_length, text_to_find);
            printf("\033[0m");
            printf("%s", substring + text_to_find_length);
        }
    }

    free(line);

    if (fclose(file) != 0) {
        perror(path);
    }
}


int nftw_func(const char *path, const struct stat *sb, int flag, struct FTW *ftwbuf) {
    if (flag == FTW_F && (sb->st_mode & S_IRUSR)) {
        find_in_file(path);
    }

    return 0;
}
