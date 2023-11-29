// ARCHITECTURE
// console app without config file
// getopt
// default output to stdout
// interfaces:
//      struct s_config
//      {
//          size_t bytes_per_line; // = 16
//          size_t bytes_per_out;  // = MAX_SIZE_T
//          size_t start_offset;   // = 0
//          FILE* output;          // = stdout
//          int base;              // 16
//          int ascii_f;           // 1
//          int off_f;             // 1
//      }
//      define LOW_HALF 0
//      define UP_HALF 1
//      global char byte[8]
//      get_byte(unsigned char byte) // base?
//      print_file(input)
//          print(addr)
//          print_row() // output, 
//          print_ascii()


// 0011 0101
// 3    5

// possible arguments: file help
// usage: hexview [OPTIONS] file
// OPTIONS:
//     -h       show help
//     -c       bytes count in line
//     -n       bytes count for output
//     -s       start address
//     -o       output file
//     -a       no ascii
//     -f       no offset
//     -b       base (2, 8, 16 - default)

// 0000000:    DE AD BE AF    | ..C.
// 0000000:    021 032 111 543    | ..C.


// interactive: apt update - y
// arguments
// config file