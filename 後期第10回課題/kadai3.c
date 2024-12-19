#include <stdio.h>

#define NUMBER 10

int search_idx(const int* v, int* idx, int key, int n);

int main(void)
{
    int ary[NUMBER], idx[NUMBER];
    int key, key_num;

    for (int i = 0; i < NUMBER; i++) {
        printf("ary[%d] = ", i);
        scanf("%d", &ary[i]);
    }

    printf("key = ");       
    scanf("%d", &key);

    key_num = search_idx(ary, idx, key, NUMBER);

    printf("keyと等しい要素の数 : %d\n", key_num);

    puts("keyと等しい要素の添字");
    for (int i = 0; i < key_num; i++) {
        printf("%d ", idx[i]);
    }
    putchar('\n');

    return 0;
}

int search_idx(const int* v, int* idx, int key, int n)
{
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] == key) {
            idx[count] = i;
            count++;
        }
    }

    return count;
}