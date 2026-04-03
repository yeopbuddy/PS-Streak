#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <uchar.h>

int main()
{
    int32_t s32_N;
    int32_t s32_M;

    int32_t s32_Nidx1;
    int32_t s32_Midx1;

    int32_t s32_Nidx2;
    int32_t s32_Midx2;

    char16_t u16_C;

    int32_t as32_Array[1024][1024] = { 0 };

    int32_t s32_Len;
    int32_t s32_LenMax;

    int32_t s32_find;
    int32_t s32_Sum;

    int32_t s32_Ans = 0;

    scanf("%d %d", &s32_N, &s32_M);

    for (s32_Nidx1 = 0; s32_Nidx1 < s32_N; s32_Nidx1++)
    {
        for (s32_Midx1 = 0; s32_Midx1 < s32_M; s32_Midx1++)
        {
            scanf(" %c", &u16_C);
            as32_Array[s32_Nidx1][s32_Midx1] = u16_C - '0';
        }
    }

    for (s32_Nidx1 = 1; s32_Nidx1 < s32_N; s32_Nidx1++)
    {
        as32_Array[s32_Nidx1][0] += as32_Array[s32_Nidx1 - 1][0];
    }

    for (s32_Midx1 = 1; s32_Midx1 < s32_M; s32_Midx1++)
    {
        as32_Array[0][s32_Midx1] += as32_Array[0][s32_Midx1 - 1];
    }

    for (s32_Nidx1 = 1; s32_Nidx1 < s32_N; s32_Nidx1++)
    {
        for (s32_Midx1 = 1; s32_Midx1 < s32_M; s32_Midx1++)
        {
            as32_Array[s32_Nidx1][s32_Midx1] += (as32_Array[s32_Nidx1 - 1][s32_Midx1] + as32_Array[s32_Nidx1][s32_Midx1 - 1] - as32_Array[s32_Nidx1 - 1][s32_Midx1 - 1]);
        }
    }

    if (s32_N < s32_M)
    {
        s32_LenMax = s32_N;
    }
    else
    {
        s32_LenMax = s32_M;
    }

    for (s32_Len = 1; s32_Len <= s32_LenMax; s32_Len++)
    {
        s32_find = 0;

        for (s32_Nidx1 = 0; s32_Nidx1 < s32_N; s32_Nidx1++)
        {
            for (s32_Midx1 = 0; s32_Midx1 < s32_M; s32_Midx1++)
            {
                s32_Nidx2 = s32_Nidx1 + s32_Len - 1;
                s32_Midx2 = s32_Midx1 + s32_Len - 1;

                if (s32_Nidx2 < s32_N && s32_Midx2 < s32_M)
                {
                    s32_Sum = as32_Array[s32_Nidx2][s32_Midx2];

                    if (s32_Nidx1 > 0)
                    {
                        s32_Sum -= as32_Array[s32_Nidx1 - 1][s32_Midx2];
                    }
                    if (s32_Midx1 > 0)
                    {
                        s32_Sum -= as32_Array[s32_Nidx2][s32_Midx1 - 1];
                    }
                    if (s32_Nidx1 > 0 && s32_Midx1 > 0)
                    {
                        s32_Sum += as32_Array[s32_Nidx1 - 1][s32_Midx1 - 1];
                    }

                    if (s32_Sum == s32_Len * s32_Len)
                    {
                        s32_find = 1;
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (s32_find == 1)
            {
                break;
            }
        }

        if (s32_find == 1)
        {
            s32_Ans = s32_Len;
        }
        else
        {
            break;
        }
    }

    printf("%d", s32_Ans * s32_Ans);

    return 0;
}