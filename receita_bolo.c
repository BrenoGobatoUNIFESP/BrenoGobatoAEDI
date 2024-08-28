#include <stdio.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);

    n /= 2;
    m /= 3;
    k /= 5;

    printf("%d\n", min(min(n, m), k));

    return 0;
}
