#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "libfdr/dllist.h"
#define TRUE 1
#define FALSE 0

int file_exists(DIR *d);