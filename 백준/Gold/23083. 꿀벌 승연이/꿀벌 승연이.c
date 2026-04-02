#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#define DIV (1000000000LL + 7LL)

int main()
{
    int32_t s32_N;
    int32_t s32_M;
    int32_t s32_K;
    int32_t s32_I1;
    int32_t s32_I2;
    int32_t s32_X;
    int32_t s32_Y;

    int64_t as64_BeeHouse[1024][1024];

    scanf("%d %d %d", &s32_N, &s32_M, &s32_K);
    for (s32_I1 = 0; s32_I1 < s32_K; s32_I1++)
    {
        scanf("%d %d", &s32_X, &s32_Y);
        as64_BeeHouse[s32_X - 1][s32_Y - 1] = -1;
    }

    for (s32_I1 = 0; s32_I1 < s32_M; s32_I1++)         
    {
        for (s32_I2 = 0; s32_I2 < s32_N; s32_I2++)     
        {
            if (as64_BeeHouse[s32_I2][s32_I1] == -1)
            {
                as64_BeeHouse[s32_I2][s32_I1] = 0;
                continue;
            }

            if (s32_I1 == 0 && s32_I2 == 0)
            {
                as64_BeeHouse[s32_I2][s32_I1] = 1;
            }
            else
            {
                int64_t s64_Val = 0;

                if (s32_I2 > 0)
                {
                    s64_Val = (s64_Val + as64_BeeHouse[s32_I2 - 1][s32_I1]) % DIV;
                }

                if (s32_I1 > 0)
                {
                    if (s32_I1 % 2 == 1)
                    {
                        if (as64_BeeHouse[s32_I2][s32_I1 - 1] >= 0)
                        {
                            s64_Val = (s64_Val + as64_BeeHouse[s32_I2][s32_I1 - 1]) % DIV;
                        }
                        if (s32_I2 < s32_N - 1 && as64_BeeHouse[s32_I2 + 1][s32_I1 - 1] >= 0)
                        {
                            s64_Val = (s64_Val + as64_BeeHouse[s32_I2 + 1][s32_I1 - 1]) % DIV;
                        }
                    }
                    else
                    {
                        if (s32_I2 > 0 && as64_BeeHouse[s32_I2 - 1][s32_I1 - 1] >= 0)
                        {
                            s64_Val = (s64_Val + as64_BeeHouse[s32_I2 - 1][s32_I1 - 1]) % DIV;
                        }
                        if (as64_BeeHouse[s32_I2][s32_I1 - 1] >= 0)
                        {
                            s64_Val = (s64_Val + as64_BeeHouse[s32_I2][s32_I1 - 1]) % DIV;
                        }
                    }
                }

                as64_BeeHouse[s32_I2][s32_I1] = s64_Val;
            }
        }
    }

    printf("%lld\n", as64_BeeHouse[s32_N - 1][s32_M - 1]);
    return 0;
}