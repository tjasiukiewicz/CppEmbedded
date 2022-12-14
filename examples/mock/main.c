#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand(time(0));
	printf("%d\n", rand());
	return 0;
}
