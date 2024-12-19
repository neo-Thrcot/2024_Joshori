#include <stdio.h>

#define NUMBER  5

/*int min_of(int v[], int n);と同等*/
int min_of(int* v, int n);

int main(void)
{
    int ary[NUMBER];

    printf("%d個の整数を入力してください。\n", NUMBER);
    for (int i = 0; i < NUMBER; i++) {
        printf("ary[%d] = ", i);
        scanf("%d", &ary[i]);
    }

    printf("最小値は%dです。\n", min_of(ary, NUMBER));

    return 0;
}

int min_of(int* v, int n)
{
    int min = v[0];

    for (int i = 1; i < NUMBER; i++) {
        if (v[i] < min) {
            min = v[i];
        }
    }

    return min;
}