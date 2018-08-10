#include <stdio.h>
#include <assert.h>
#include <limits.h>

int threefourths(int x)
{

    // 为了保证 threefourths = x - fourth 向零舍入
    // fourth 必须与 向零舍入 相反
    int fourth = x >> 2;

    // 正数不能整除 4 的时候， fourth++
    int x_is_pos = (~x & INT_MIN) && (x != 0);
    int has_remainder = x & 3;
    x_is_pos &&has_remainder && (fourth++);

    // 负数右移 2 位自带 fourth-- 效果

    // x = 0 时， x - forth = 0

    return x - fourth;
}

int main(int argc, char const *argv[])
{

    int x;

    for (x = -20; x < 20; x++)
    {
        printf("threefourths(% 4d) = % 4d\n", x, threefourths(x));
        assert(threefourths(x) == (int)(x * 0.75));
    }

    x = INT_MIN;
    printf("threefourths(% 4d) = % 4d\n", x, threefourths(x));
    assert(threefourths(x) == (int)(x * 0.75));

    x = INT_MAX;
    printf("threefourths(% 4d) = % 4d\n", x, threefourths(x));
    assert(threefourths(x) == (int)(x * 0.75));

    return 0;
}