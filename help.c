#include <stdio.h>
#include <stdlib.h>

void usage(char *prog_name)
{
    printf("usage: %s [-h] [[OPTIONS] file]\n"
                "\t-h\t\tshow help\n"
                "\t-c\t\tbytes count in line\n"
                "\t-n\t\tbytes count for output\n"
                "\t-s\t\tstart address\n"
                "\t-o\t\toutput file\n"
                "\t-a\t\tno ascii\n"
                "\t-f\t\tno offset\n"
                "\t-b\t\tbase (2, 8, 16 - default)\n", prog_name);
}