#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int32_t s32_white;
    int32_t s32_black;
    int32_t s32_xindex;
    int32_t s32_yindex;
    int32_t s32_zindex;
    
    int32_t s32_dp[1024][16][16] = {0};
    
    cin >> s32_white >> s32_black;
    
    s32_dp[1][1][0] = s32_white;
    s32_dp[1][0][1] = s32_black;
    s32_dp[1][0][0] = 0;
    
    s32_xindex = 2;
    
    int32_t s32_max = 0;
    
    while(cin >> s32_white >> s32_black)
    {
        for(s32_yindex = 0; s32_yindex < 16; s32_yindex++)
        {
            for(s32_zindex = 0; s32_zindex < 16; s32_zindex++)
            {
                int32_t s32_val1 = (s32_yindex >= 1 ? s32_dp[s32_xindex - 1][s32_yindex - 1][s32_zindex] + s32_white : 0);
                int32_t s32_val2 = (s32_zindex >= 1 ? s32_dp[s32_xindex - 1][s32_yindex][s32_zindex - 1] + s32_black : 0);
                int32_t s32_val3 = s32_dp[s32_xindex - 1][s32_yindex][s32_zindex];
                
                s32_dp[s32_xindex][s32_yindex][s32_zindex] = max(s32_val1, max(s32_val2, s32_val3));
            }
        }
        s32_max = max(s32_dp[s32_xindex][15][15], s32_max);
        ++s32_xindex;
    }

    cout << s32_max;

    return 0;
}