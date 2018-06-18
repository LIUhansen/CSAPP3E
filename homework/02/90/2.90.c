#include <stdio.h>
#include <assert.h>
#include <math.h>

float u2f(unsigned x)
{
    return *(float *)&x;
}

/* 2^x */
float fpwr2(int x)
{
    /* Result exponent and fraction */
    unsigned exp, frac;
    unsigned u;

    if (x < -149)
    {
        /* Too small, Return 0.0 */
        exp = 0;
        frac = 0;
    }
    else if (x < -126)
    {
        /* Denormalized result */
        exp = 0;
        frac = 1 << (149 + x);
    }
    else if (x < 128)
    {
        /* Normalized result */
        exp = x + 127;
        frac = 0;
    }
    else
    {
        /* Too big, return +∞ */
        exp = 0xFF;
        frac = 0;
    }

    /* pack exp and frac into 32 bits */
    u = exp << 23 | frac;
    /* Result as float */
    return u2f(u);
}

int main(int argc, char const *argv[])
{

    int x = -150;
    printf("  fpwr2(%d) = %.100f \n", x, fpwr2(x));
    printf("powf(2, %d) = %.100f \n", x, fpwr2(x));

    x = -149;
    printf("  fpwr2(%d) = %.100f \n", x, fpwr2(x));
    printf("powf(2, %d) = %.100f \n", x, fpwr2(x));

    x = -100;
    printf("  fpwr2(%d) = %.100f \n", x, fpwr2(x));
    printf("powf(2, %d) = %.100f \n", x, fpwr2(x));

    x = -10;
    printf("  fpwr2(%d) = %.10f \n", x, fpwr2(x));
    printf("powf(2, %d) = %.10f \n", x, fpwr2(x));

    x = 0;
    printf("  fpwr2(%d) = %f \n", x, fpwr2(x));
    printf("powf(2, %d) = %f \n", x, fpwr2(x));

    x = 10;
    printf("  fpwr2(%d) = %f \n", x, fpwr2(x));
    printf("powf(2, %d) = %f \n", x, fpwr2(x));

    x = 100;
    printf("  fpwr2(%d) = %f \n", x, fpwr2(x));
    printf("powf(2, %d) = %f \n", x, fpwr2(x));

    x = 127;
    printf("  fpwr2(%d) = %f \n", x, fpwr2(x));
    printf("powf(2, %d) = %f \n", x, fpwr2(x));

    x = 128;
    printf("  fpwr2(%d) = %f \n", x, fpwr2(x));
    printf("powf(2, %d) = %f \n", x, fpwr2(x));

    return 0;
}
