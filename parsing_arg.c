#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>

#include "hexview.h"
#include "errors.h"

int parse_and_valid_args(int argc, char **argv, struct s_config *config)
{
    int opt = 0;
    int fail = 0;
    char *endp = NULL;
    FILE *fp = NULL;

    while ((opt = getopt(argc, argv, "hc:ns:o:afb:")) != -1 && !fail)
    {
        switch (opt)
        {
            case 'h':
                usage(argv[0]);
                return 0;

            case 'c':
                config->bytes_per_line = strtoul(optarg, &endp, 10);
                fail = (config->bytes_per_line == 0 || *endp) ? E_BPL : 0;
                break;

            case 'n':
                config->bytes_per_out = strtoul(optarg, &endp, 10);
                fail = (config->bytes_per_out == 0 || *endp) ? E_BPO : 0;
                break;

            case 's':
                config->start_offset = strtoul(optarg, &endp, 10);
                fail = (*endp != '\0') ? E_SO : 0;
                break;

            case 'o':
                if (config->output != stdout || !(fp = fopen(optarg, "wt")))
                    fail = -1 ? E_OUT : 0;
                else
                    config->output = fp;
                break;

            case 'a':
                config->ascii_f = 0;
                break;

            case 'f':
                config->off_f = 0;
                break;

            case 'b':
                config->base = strtoul(optarg, &endp, 10);
                fail = (config->base != 2 && config->base != 8 && config->base != 16) ? E_BAS : 0;
                break;

            default:
                fputs("Key is not found.", stderr);
                usage(argv[0]);
                return -1;
        }
    };
    if (optind >= argc)
        fail = -1;
    return fail;
}
