#include <stdio.h>

int main() {
    int E, S, M, year = 1;
    scanf("%d %d %d", &E, &S, &M);
    while(true) {
        if((year - E) % 15 == 0 && (year - S) % 28 == 0 && (year - M) % 19 == 0)
            break;
        year++;
    }
    printf("%d", year);
    return 0;
}