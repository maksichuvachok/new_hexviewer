#ifndef HEXV_H
#define HEXV_H

// Config
struct s_config
{
    size_t bytes_per_line;      // = 16
    size_t bytes_per_out;       // = MAX_SIZE_T
    size_t start_offset;        // = 0
    FILE* input;                // = ""
    FILE* output;               // = stdout
    int base;                   // 16
    int ascii_f;                // 1
    int off_f;                  // 1
    char fill_space;            // ' '
    char fill_non_printable;    // '.'
};
char *buffer_ascii;

void usage(char* prog_name);
int parse_and_valid_args(int argc, char **argv, struct s_config *config);
void clean(char *buffer_ascii, struct s_config *config);

char *dec2hex(char s, size_t size);
char *dec2bin(char s, size_t size);
char *dec2oct(char s, size_t size);
int get_size_file(FILE *f);

void offset(int i, struct s_config *config);
char *p_ascii(char buffer_ascii[], struct s_config *config);
void p_numeration(struct s_config *config);
void autocomplete(struct s_config *config);
void pbyte(char s, struct s_config *config);
void print_bytes(struct s_config *config, int file_size);

#endif
