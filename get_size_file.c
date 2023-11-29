#include <stdio.h>

int get_size_file(FILE *f){
    unsigned int fsize = 0;
    unsigned int now = 0;

    if (ftell(f) == -1)
    {   
        perror("ftell: ");
        return -1;
    }
    else
    {
        now = ftell(f);
        fseek(f, 0, SEEK_END);
        fsize = ftell(f);
        fseek(f, now, SEEK_SET);   
    }

    return fsize;
}