// https://www.acmicpc.net/problem/17609
#include <iostream>
#include <string>

using namespace std;

int main(){

    int T; cin >> T;
    
    for(int t = 0; t < T; t++){
        string S; cin >> S;
        int lp = 0; int rp = S.size() - 1; int cnt = 0;
        while(lp < rp){
            if(S[lp] == S[rp]){
                ++lp; --rp;
            }else if(cnt == 0 || cnt == 1){
                ++cnt;
                if(S[lp + 1] == S[rp]) ++lp;
                else if(S[lp] == S[rp - 1]) --rp;
                else ++cnt;
            }
            if(cnt >= 2) break;
        }
        if(cnt >= 2){
            lp = 0; rp = S.size() - 1; cnt = 0;
            while(lp < rp){
                if(S[lp] == S[rp]){
                    ++lp; --rp;
                }else if(cnt == 0 || cnt == 1){
                    ++cnt;
                    if(S[lp] == S[rp - 1]) --rp;
                    else if(S[lp + 1] == S[rp]) ++lp;
                    else ++cnt;
                }
                if(cnt >= 2) break;
            }
        }
        cnt = (cnt > 2 ? 2 : cnt);
        cout << cnt << "\n";
    }

    return 0;
}