#include <stdio.h>
#define swap(t, x, y) {t temp; temp = x; x = y; y = temp;}

int main(void) {
    int a = 1;
    int b = 2;
    swap(int, a, b);
    printf("%d %d\n", a, b);
    double x = 1;
    double y = 2;
    swap(double, x, y);
    printf("%lf %lf\n", x, y);
}
