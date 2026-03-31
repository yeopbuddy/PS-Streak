#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdint.h>

int main() {

    int32_t s32_Works;
    int32_t s32_Days;
    int32_t s32_NewDays;
    int32_t s32_WorkIndex;
    int32_t s32_WeekIndex;

    int32_t as32_Week[7] = { 0 };
    int32_t as32_SubWeek[7] = { 0 };

    scanf("%d", &s32_Works);

    for (s32_WorkIndex = 0; s32_WorkIndex < s32_Works; s32_WorkIndex++)
    {
        scanf("%d", &s32_Days);

        s32_Days = s32_Days % 7;

        if (as32_Week[s32_Days] == 0)
        {
            as32_Week[s32_Days] = 1;

            for (s32_WeekIndex = 0; s32_WeekIndex < 7; s32_WeekIndex++)
            {
                if (s32_WeekIndex == s32_Days)
                {
                    continue;
                }
                s32_NewDays = (s32_WeekIndex + s32_Days) % 7;
                if (as32_Week[s32_WeekIndex] == 1 && as32_Week[s32_NewDays] == 0)
                {
                    as32_SubWeek[s32_NewDays] = 1;
                }
            }
            for (s32_WeekIndex = 0; s32_WeekIndex < 7; s32_WeekIndex++)
            {
                as32_Week[s32_WeekIndex] = as32_Week[s32_WeekIndex] + as32_SubWeek[s32_WeekIndex];
                as32_SubWeek[s32_WeekIndex] = 0;
            }
        }
        else
        {
            for (s32_WeekIndex = 0; s32_WeekIndex < 7; s32_WeekIndex++)
            {
                s32_NewDays = (s32_WeekIndex + s32_Days) % 7;
                if (as32_Week[s32_WeekIndex] == 1 && as32_Week[s32_NewDays] == 0)
                {
                    as32_SubWeek[s32_NewDays] = 1;
                }
            }
            for (s32_WeekIndex = 0; s32_WeekIndex < 7; s32_WeekIndex++)
            {
                as32_Week[s32_WeekIndex] = as32_Week[s32_WeekIndex] + as32_SubWeek[s32_WeekIndex];
                as32_SubWeek[s32_WeekIndex] = 0;
            }
        }
    }

    if (as32_Week[4] == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}
