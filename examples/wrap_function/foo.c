#include <stdio.h>
#include "foo.h"

static int value = 42;

void foo() {
    printf("Original foo(), value = %d.\n", value);
}
