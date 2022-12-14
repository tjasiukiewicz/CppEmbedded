#include <stdio.h>
#include "../foo.c" /* !!!  */
#include "foo.h"

void __wrap_foo(void) {
    printf("Wrap foo(), value = %d.\n", value);
    printf("  ");
    __real_foo();
}
