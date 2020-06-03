#ifndef FIND_TEXT_MAIN_H
#define FIND_TEXT_MAIN_H

void parse_args(int argc, char *argv[], char **dir, char **text);

void check_if_directory(char *dir);

int nftw_func(const char *path, const struct stat *sb, int flag, struct FTW *ftwbuf);

#endif
