#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t s32_n;
    int32_t s32_k;

    int32_t s32_xindex;
    int32_t s32_yindex;

    int64_t as64_alive[64][64] = { 0 };

    int64_t s64_lastnum = 1;

    for (s32_yindex = 1; s32_yindex < 64; s32_yindex++)
    {
        s64_lastnum = s64_lastnum * 2;

        for (s32_xindex = 1; s32_xindex < 64; s32_xindex++)
        {
            if (s32_xindex > s32_yindex)
            {
                break;
            }
            if (s32_xindex == s32_yindex)
            {
                as64_alive[s32_xindex][s32_yindex] = s64_lastnum - 1;
            }
            else if (s32_xindex == s32_yindex - 1)
            {
                as64_alive[s32_xindex][s32_yindex] = s64_lastnum - 2;
            }
            else
            {
                as64_alive[s32_xindex][s32_yindex] = as64_alive[s32_xindex - 1][s32_yindex - 1] + as64_alive[s32_xindex + 1][s32_yindex - 1];
            }
        }
    }

    scanf("%d %d", &s32_n, &s32_k);

    printf("%lld", as64_alive[s32_n][s32_k]);

    return 0;
}