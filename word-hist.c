/* Print a historgram of word lengths */

#include <stdbool.h>
#include <stdio.h>

#define MAXLEN 100

int main(void) {
	bool inword = false;
	char c;
	int word_len = 0;
	int word_dist[MAXLEN+1];
	float nstars;

	for(int i = 1; i <= MAXLEN; ++i) word_dist[i] = 0;
	while(true) {
		c = getchar();
		if(c == ' ' || c == '\n' || c == '\t' || c == EOF) {
			if(inword) {
				word_dist[word_len]	+= 1;
				word_len = 0;
				inword = false;	
			}
			if (c == EOF) break;
		} else {
			if (!inword) {
				inword = true;
			}
			word_len++;	
		}
	}

	for(int i = 1; i < MAXLEN+1; ++i) {
		if (word_dist[i] > 0) {
			printf("%3.d: ", i);
			nstars = 1.0 * word_dist[i]/200.0;
			for(int i = 0; i < nstars; i++){
				putchar('*');
			}
			putchar('\n');
		}
	}
}
