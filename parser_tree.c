#include "parser_tree.h"

int main(int argc, char *argv[])
{
    struct stat buffer;
    int exists, max_length;
    DIR *d;
    struct dirent *de;
    Dllist files, tmp;

    if (argc != 2)
    {
        fprintf(stderr, "usage: ./parse_tree :PATH\n");
        exit(1);
    }

    d = opendir(argv[1]);

    if (file_exists(d)) {
        fprintf(stderr, "file not exists!\n");
        exit(1);
    }

    max_length = 0;
    files = new_dllist();

    for (de = readdir(d); de != NULL; de = readdir(d)) {
        dll_append(files, new_jval_s(strdup(de->d_name)));
        if (strlen(de->d_name) > max_length){
            max_length = strlen(de->d_name);
        }
    }
    closedir(d);

    dll_traverse(tmp, files) {
        exists = stat(tmp->val.s, &buffer);
        if (exists < 0) {
            fprintf(stderr, "%s not found\n", tmp->val.s);
        } else {
            printf("%*s %10ld\n", -max_length, tmp->val.s, buffer.st_size);
        }
    }

    return 0;
}

int file_exists(DIR *d) {
    if (d == NULL) {
        return TRUE;
    }

    return FALSE;
}