#include <stdio.h>

#define TABSTOP 4

int main(void) {
	char c;
	int i;
	while((c=getchar()) != EOF) {
		if(c=='\t') {
			for(i=0; i < TABSTOP; i++) {
				putchar(' ');
			}
		} else {
			putchar(c);
		}
	}
}

