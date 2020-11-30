#define prog2

#ifdef prog2

#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len) {
	size_t i;
	for (i = 0; i < len; i++)
		printf(" %.2x",start[i]);
	printf("\n");
}

void show_int(int x) {
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
	show_bytes((byte_pointer) &x,sizeof(float));
}

void show_double(double x) {
	show_bytes((byte_pointer) &x,sizeof(double));
}

void show_pointer(void *x) {
	show_bytes((byte_pointer) &x,sizeof(void *));
}

int main() {
	int a[10];
	memset(a,-1,sizeof(a));

	for (int i = 0; i < 10; i++) {
		printf("%d\t",a[i]);
	}
	printf("\n");

	show_int(a[1]);
	
	double num1=0.5;
	show_double(num1);
	printf("Hello VS 2017 \n");
	return 0;
}
#endif

