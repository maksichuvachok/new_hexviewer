#include <stdio.h>

#include "hexv.h"

void offset(int i, struct s_config *config) {
    if (i == 0 && config->off_f == 1)
    {   
        fprintf(config->output,"%06lX| ", config->start_offset);
        config->start_offset += config->bytes_per_line;
    }

}

char *p_ascii(char buffer_ascii[], struct s_config *config) {

    if (config->ascii_f == 1)
    {                
        fprintf(config->output," |%s", buffer_ascii);   
    }
    fprintf(config->output,"\n");

    return buffer_ascii;
}

void p_numeration(struct s_config *config) {
    fprintf(config->output,"\n");
    if (config->off_f == 1)
    {
        fprintf(config->output,"        ");
    }
    for (int i = 0; i <= config->bytes_per_line * 2; i++)
    {   
        if (i < config->bytes_per_line)
        {
            fprintf(config->output,"%02X ", i);
        }
        else if (i == config->bytes_per_line)
        {
            fprintf(config->output,"\n");
            if (config->off_f == 1)
            {
                fprintf(config->output,"ADRLIN  ");
            }
        }
        
        else
        {
            fprintf(config->output,"-- ");
        }
    }
    if (config->ascii_f == 1)
    {  
        fprintf(config->output,"  ASCII");
    }
    fprintf(config->output,"\n");
}

void autocomplete(struct s_config *config) {
    if (config->base == 16)
    {
        fprintf(config->output, "** ");
    }
    else if (config->base == 2)
    {
        fprintf(config->output,"******** ");
    }
    else if (config->base == 8)
    {
        fprintf(config->output, "*** ");
    }    
}

void pbyte(char s, struct s_config *config) {
    if (config->base == 16)
    {
        fprintf(config->output,"%s ", dec2hex(s, 3));
    }
    else if (config->base == 2)
    {
        fprintf(config->output,"%s ", dec2bin(s, 9));
    }
    else if (config->base == 8)
    {
        fprintf(config->output,"%s ", dec2oct(s, 4));
    }
}
