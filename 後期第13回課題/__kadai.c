#include <stdio.h>
#include <stdint.h>

typedef enum {
    RIGHT,
    LEFT
} rotate_t;

void print_bits(uint32_t x);
uint32_t rotate(uint32_t x, rotate_t way, uint8_t n);

int main(void)
{
    uint32_t a;
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
    print_bits(rotate(a, RIGHT, (uint8_t)shift));
    putchar('\n');

    printf("左へ%dビット回転した値は\n", shift);
    printf("a << %2d : ", shift);
    print_bits(rotate(a, LEFT, (uint8_t)shift));
    putchar('\n');

    return 0;
}

void print_bits(uint32_t x)
{
    uint32_t unit = 1U << (sizeof(uint32_t) * 8 - 1);
    
    for (int i = 0; i < sizeof(uint32_t) * 8; i++) {
        putchar((x & unit) ? '1' : '0');
        unit >>= 1; 
    }
}

uint32_t rotate(uint32_t x, rotate_t way, uint8_t n)
{
    uint32_t msk_bits = ~0U;
    uint32_t return_bits;

    switch (way)
    {
        case RIGHT:
            for (uint8_t i = 0; i < 32 - n; i++) {
                msk_bits &= (~(1U << (31 - n)));
            }
            return_bits = (x >> n) | ((x & msk_bits) << 32 - n);

            break;

        case LEFT:
            for (uint8_t i = 0; i < 32 - n; i++) {
                msk_bits &= (~(1U << i));
            }
            return_bits = (x << n) | ((x & msk_bits) >> 32 - n);

            break;
    }

    return return_bits;
}