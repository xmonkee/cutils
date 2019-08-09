#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum op {
    Num,
    Pls,
    Mns,
    Mlt,
    Div,
    Nln
} op;

op getop(char s[]);
void push(double n);
double pop(void);

int main(void) {
    char s[10];
    while(1) {
        switch(getop(s)) {
            case Num: push(atof(s)); break;
            case Pls: push(pop() + pop()); break;
            case Mlt: push(pop() * pop()); break;
            case Mns: push(-(pop() - pop())); break;
            case Div: push(1.0/(pop() / pop())); break;
            case Nln: printf("\n%lf\n", pop()); break;
        }
    }
}

op getop(char s[]) {
    char c;
    int i;

    // get spaces out the way
    while(isspace(c = getch()))
        ;
    // put the extra char back
    putch(c);

    //is it a number?
    i = 0;
    if (isdigit(c = getch())) {
        s[i++] = c;
        while (isdigit(c = getch())) s[i++] = c;
        putch(c);
        if (c == '.') {
            s[i++] = c;
            while (isdigit(c = getch())) s[i++] = c;
            // put the extra char back
            putch(c);
        }
        s[i] = '\0';
        return Num;
    }

    //op
    switch(c=getch()) {
        case '+': return Pls;
        case '-': return Mns;
        case '*': return Mlt;
        case '/': return Div;
        case '\n': return Nln;
    }

}

