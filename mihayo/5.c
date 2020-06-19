#include <stdio.h>
int f(int n) {
    int count = 0;
    while(n) {
        ++count;
        n = (n-1)&n;
    }
    return count;
}

int main() {
    printf("%d", f(63));
}