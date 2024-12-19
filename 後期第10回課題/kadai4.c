#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fortune(int n);

int main(void)
{
    srand(time(NULL));

    puts("おみくじを10回引きます。");
    for (int i = 0; i < 10; i++) {
        printf("%2d回目 : ", i + 1);
        fortune(rand() % 15);
    }

    return 0;
}

void fortune(int n)
{
    if(n == 0) {
        puts("大吉");
    } else if (n >= 1 && n <= 3) {
        puts("中吉");
    } else if (n >= 4 && n <= 6) {
        puts("小吉");
    } else if (n >= 7 && n <= 9) {
        puts("吉");
    } else if (n >= 10 && n <= 12) {
        puts("末吉");
    } else if (n == 13) {
        puts("凶");
    } else if (n == 14) {
        puts("大凶");
    }
}