#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define DZERO 0.00001;

/* Reverse polish calculator with variables(a-z) */

typedef enum Op {
    Num, // Number
    Pls, // Plus (+)
    Mns, // Minus (-)
    Mlt, // Multiply (*)
    Div, // Divide (/)
    Mod, // Mod (%)
    Nln, // Newline (\n)
    Eof, // EOF (EOF)
    Prn, // Print top of stack (p)
    Pop, // Pop top of stack (o)
    Dup, // Duplicate top of stack (d)
    Swp, // Swap top two elements (s)
    Clr, // Clear the stack (c)
    Sav, // Save top of stack to variable (sa, sb etc)
    Rtr, // Retreive a variable and push to stack (ra, rb etc)
    Err // Error: exit
} Op;

Op getop(char s[]);
void push(double n);
double pop(void);
double peek(void);
void clear(void);
bool dequal(double, double);

int main(void) {
    Op op;
    char s[10];
    double first, second;
    char varname;
    double vars[26];

    while(1) {
        op = getop(s);
        switch(op) {
            case Num: push(atof(s)); break;
            case Pls: push(pop() + pop()); break;
            case Mlt: push(pop() * pop()); break;
            case Mns: push(-(pop() - pop())); break;
            case Div:
                      second = pop();
                      first = pop();
                      if(dequal(second, 0.00)) {
                          printf("Division by zero \n");
                          push(first); push(second);
                          break;
                      }
                      push(first / second);
                      break;
            case Mod:
                      second = pop();
                      first = pop();
                      if(dequal(second, 0.00)) {
                          printf("Division by zero \n");
                          push(first); push(second);
                          break;
                      }
                      push((int)first % (int)second);
                      break;
            case Nln: break;
            case Prn: printf("%.2lf\n", peek()); break;
            case Pop: printf("%.2lf\n", pop()); break;
            case Dup: push(peek()); break;
            case Swp:
                      second = pop(); first = pop();
                      push(second); push(first);
                      break;
            case Clr: clear(); break;
            case Sav:
                      varname = s[0];
                      vars[varname - 'a'] = peek();
                      break;
            case Rtr:
                      varname = s[0];
                      push(vars[varname - 'a']);
                      break;
            case Eof: return 0;
            case Err: printf("Error\n"); return 1;
        }
    }
}

bool dequal(double q1, double q2) {
    return abs(q1 - q2) < DZERO;
}

char getch(void);
char peekch(void);
void putch(char c);

Op getop(char s[]) {
    char c;
    int i= 0;

    // get spaces out the way
    while((c=getch()) == ' ' || c == '\t')
        ;

    // is it a number?
    if (isdigit(c) || (c=='-' && isdigit(peekch()))) {
        s[i++] = c;
        // Get all the digits before the decimal
        while (isdigit(c = getch())) s[i++] = c;
        // Get the decimal and the digits afer it
        if (c == '.') {
            s[i++] = c;
            while (isdigit(c = getch())) s[i++] = c;
        }
        // put the extra char back
        putch(c);
        s[i] = '\0';
        return Num;

    } else if(c == 's' || c == 'r') { // Variables
        s[i++] = getch();
        s[i] = '\0';
        if(!isspace(peekch()))
            return Err;
        if (c == 's')
            return Sav;
        else
            return Rtr;
    } else {
        //Op
        switch(c) {
            case '+': return Pls;
            case '-': return Mns;
            case '*': return Mlt;
            case '/': return Div;
            case '%': return Mod;
            case '\n': return Nln;
            case 'p': return Prn;
            case 'o': return Pop;
            case 'd': return Dup;
            case 's': return Swp;
            case 'c': return Clr;
            case EOF: return Eof;
            default: return Err;
        }
    }

}

char charbuf[100];
int charptr;

char getch() {
    if (charptr) {
        return charbuf[--charptr];
    }
    return getchar();
}

void putch(char c) {
    charbuf[charptr++] = c;
}

char peekch() {
    char c = getch();
    putch(c);
    return c;
}

double stck[100];
int stckptr;

void push(double i) {
    if (stckptr == 100) {
        printf("Error: stack is full\n");
        return;
    }
    stck[stckptr++] = i;
}

double pop() {
    if (stckptr == 0) {
        printf("Error: stack is empty\n");
        return 0.0;
    }
    return stck[--stckptr];
}
double peek() {
    if (stckptr == 0) {
        printf("Error: stack is empty\n");
        return 0.0;
    }
    return stck[stckptr - 1];
}
void clear() {
    stckptr = 0;
}
