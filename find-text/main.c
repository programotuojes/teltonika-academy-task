#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <ftw.h>
#include "main.h"

int main(int argc, char *argv[]) {
    char *dir = NULL;
    char *text = NULL;

    parse_args(argc, argv, &dir, &text);
    check_if_directory(dir);

    if (nftw(dir, nftw_func, 20, 0) != 0) {
        perror("nftw()");
    }

    return 0;
}
