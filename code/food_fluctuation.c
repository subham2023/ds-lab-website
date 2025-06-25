#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    printf("Food price fluctuation for 7 days:\n");
    for (int i = 1; i <= 7; i++) {
        int price = 50 + rand() % 51; // Price between 50 and 100
        printf("Day %d: Rs %d\n", i, price);
    }
    return 0;
} 