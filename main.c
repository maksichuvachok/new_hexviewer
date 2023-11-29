#include <ctype.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "hexview.h" // "hexv.h" // -I .
#include "errors.h"


int main(int argc, char **argv)
{
    struct s_config config = { 16, (size_t)-1, 0, 0, stdout, 16, 1, 1 };
    int rc = E_SUCCESS;
    unsigned int file_size = 0;
    
    // если задан оффсет, что делать, когда файлов больше 1?
    // Если указано больше одного файла, то опции не применимы
    // Следовательно нужно выводить соответствующее сообщение об ошибке 
    if ((rc = parse_and_valid_args(argc, argv, &config)) != E_SUCCESS)
    {
        print_error(rc); //fputs("Incorrect options.", stderr);
        return -1;
    }
    
    for (int i = optind; i < argc; ++i)
    {
        if ((config.input = fopen(argv[i], "rb")) == NULL)
        {
            perror("file"); // argv[i]
            continue;
        }
        file_size = get_size_file(config.input);

        // если задано смещение - проверить не вываливаемся ли
        // за границу файла. Если да, то надо подумать...
        
        fseek(config.input, config.start_offset, SEEK_SET);
        print_bytes(&config, file_size);

        fclose(config.input);
    }

    clean(buffer_ascii, &config);

    return rc;
}