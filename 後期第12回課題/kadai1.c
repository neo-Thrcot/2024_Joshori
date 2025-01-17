#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int retry;
    int count = 1;
    int bingo[75] = {0};

    srand(time(NULL));

    do {
        int n = rand() % 75;

        while (bingo[n] == 1) {
            n = rand() % 75;
        }
        bingo[n] = 1;

        printf("%d回目 : %d\n", count++, n);

        printf("ビンゴ？ (0:Yes, 1:No) : ");
        scanf("%d", &retry);
    } while (retry != 0);

    printf("おめでとう!\n");

    return 0;
}