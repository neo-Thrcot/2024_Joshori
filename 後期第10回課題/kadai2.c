#include <stdio.h>

#define NUMBER 5

/*void rev_intary(int v[], int n);と同等*/
void rev_intary(int* v, int n);

int main(void)
{
    int ary[NUMBER];

    printf("%d個の整数を入力してください。\n", NUMBER);
    for (int i = 0; i < NUMBER; i++) {
        printf("ary[%d] = ", i);
        scanf("%d", &ary[i]);
    }

    rev_intary(ary, NUMBER);
    
    puts("反転しました。");
    for (int i = 0; i < NUMBER; i++) {
        printf("ary[%d] = %d\n", i, ary[i]);
    }

    return 0;
}

void rev_intary(int* v, int n)
{
    for (int i = 0; i < n / 2; i++) {
        int num = v[i];
        v[i] = v[n - 1 - i];
        v[n - 1 - i] = num;
    }
}