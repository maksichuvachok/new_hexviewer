#include <assert.h>
#include <stdio.h>

#include "errors.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

void print_error(int err_code) {
    static const char *errors[] = {
        "Success",
        "", // E_BPL
    } ;

    assert(0 <= err_code && err_code < ARRAY_SIZE(errors));
    fputs(errors[err_code], stderr);
}