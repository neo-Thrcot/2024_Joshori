#include <stdio.h>

void print_bits(unsigned x);
unsigned rrotate(unsigned x, int n);
unsigned lrotate(unsigned x, int n);

int main(void)
{
    unsigned a;
    int shift;

    puts("非負の整数を入力してください。");
    printf("a : ");                                     
    scanf("%d", &a);

    printf("回転する桁数を入力してください(32以下) : ");    
    scanf("%d", &shift);

    printf("a       : ");
    print_bits(a);
    putchar('\n');

    printf("右へ%dビット回転した値は\n", shift);
    printf("a >> %2d : ", shift);
    print_bits(rrotate(a, shift));
    putchar('\n');

    printf("左へ%dビット回転した値は\n", shift);
    printf("a << %2d : ", shift);
    print_bits(lrotate(a, shift));
    putchar('\n');

    return 0;
}

void print_bits(unsigned x)
{
    unsigned unit = 1U << (sizeof(unsigned) * 8 - 1);
    
    for (int i = 0; i < sizeof(unsigned) * 8; i++) {
        putchar((x & unit) ? '1' : '0');
        unit >>= 1; 
    }
}

unsigned rrotate(unsigned x, int n)
{
    unsigned msk_bits = ~0U;

    for (int i = 0; i < 32 - n; i++) {
        msk_bits &= (~(1U << (31 - n)));
    }

    return (x >> n) | ((x & msk_bits) << 32 - n);
}

unsigned lrotate(unsigned x, int n)
{
    unsigned msk_bits = ~0U;

    for (int i = 0; i < 32 - n; i++) {
        msk_bits &= (~(1U << i));
    }

    return (x << n) | ((x & msk_bits) >> 32 - n);
}