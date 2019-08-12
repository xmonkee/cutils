#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMS 5
#define show_dbl() for(int i=0; i<ELEMS; i++) printf("%3.2lf ", dbl_arr[i]); printf("\n")
#define show_str() for(int i=0; i<ELEMS; i++) printf("\"%s\" ", str_arr[i]); printf("\n")

char *str_arr[ELEMS];
double dbl_arr[ELEMS];

void swap(void *a, void *b, int width) {
    // Generic swap function, uses width to know how many bytes to swap
    char *x = (char *)a;
    char *y = (char *)b;
    char temp;

    while(width-- > 0) {
        temp = *x;
        *x++ = *y;
        *y++ = temp;
    }
}

void mqsort_(
        char *loaddr,
        char *hiaddr,
        int width,
        int (*comp)(const void *a, const void *b))
{
    if (loaddr >= hiaddr) return;
    char *iaddr, *jaddr;
    iaddr = loaddr;
    for (jaddr = iaddr; jaddr < hiaddr; jaddr += width) {
        if(comp((const void *)jaddr, (const void *)hiaddr) <= 0) {
            swap(iaddr, jaddr, width);
            iaddr += width;
        }
    }
    swap(iaddr, jaddr, width);
    mqsort_(loaddr, iaddr-width, width, comp);
    mqsort_(iaddr, hiaddr, width, comp);
}


void mqsort(
        void *arr,
        int len,
        int width,
        int (*comp)(const void *a, const void *b))
/*
* arr -> Array to sort
* len -> Length of array
* width -> sizeof elements
* comp -> function that takes pointers to two elements and returns
*  -ve the first is less than the second,
*  0 if they are equal
*  +ve if first is greater than the second
*/
{
    char *a = (char *)arr;
    mqsort_(a, a + (len-1)*width, width, comp);
}

/* Tests */

int comp_dbl(const void *a, const void *b) {
    const double *x = (const double *)a;
    const double *y = (const double *)b;
    if (*x < *y) return -1;
    if (*x > *y) return 1;
    return 0;
}

int comp_str(const void *a, const void *b) {
    const char **x = (const char **)a;
    const char **y = (const char **)b;
    return strcmp(*x, *y);
}

void gen_rand_nums(double arr[]) {
    for(int i = 0; i < ELEMS; i++)
        arr[i] = 1.0 / 10000000 * rand();
}

void gen_rand_strs(char *arr[]) {
    for(int i = 0; i < ELEMS; i++){
        arr[i] = malloc(sizeof(char) * 5);
        for(int j = 0; j < 5; j++){
            arr[i][j] = 'a' + (rand() % 26);
        }
    }

}


int main(void) {
    srand(time(NULL));

    /* Array of doubles */
    gen_rand_nums(dbl_arr);
    show_dbl();
    mqsort(dbl_arr, ELEMS, sizeof(double), &comp_dbl);
    show_dbl();

    /* Array of strings */
    gen_rand_strs(str_arr);
    show_str();
    mqsort(str_arr, ELEMS, sizeof(char *), &comp_str);
    show_str();
}
