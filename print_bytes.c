#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "hexview.h"

void print_bytes(struct s_config *config, int file_size){
    char s = 0;
    int iteration = 0;
    buffer_ascii = (char*)malloc(sizeof(char) * config->bytes_per_line + 1);

    if (config->start_offset != 0)
    {
    }

    //if (config.bytes_per_out != 0)
    //{
    //    iteration = config.bytes_per_out;
    //}
    if (file_size  != 0 && config->bytes_per_line != 0)
    {
        iteration = (file_size / config->bytes_per_line + 1) * config->bytes_per_line;
    }
    else
    {
        iteration = file_size;
    }

    fprintf(config->output, "Volum of file: %d\n", file_size);
    fprintf(config->output, "Iteration: %d\n", iteration);
    p_numeration(iteration, config);
    
    for (int i = 0; config->start_offset < iteration; config->start_offset++)
    {
        // ret!!!! = fread(buffer_ascii, config.bytes_per_line, 1, fin);
        if ((s = fgetc(config->input)) != EOF)
        {    
            offset(i, config);
            pbyte(s, config);

            if (!isgraph(s)) { 
                s = '.';
            }

            buffer_ascii[i] = s;

            if (i == config->bytes_per_line - 1) {
                buffer_ascii[i + 1] = '\0';
                p_ascii(buffer_ascii, config);
                i = 0;
            }
            else
            {
                i++;
            }
        }
        else
        {
            buffer_ascii[i] = '\0';
            if (i == config->bytes_per_line - 1) {
                autocomplete(config);
                p_ascii(buffer_ascii, config);
                break;           
            }
            else
            {
                autocomplete(config);
                i++;
            }   
        }

    }
}
