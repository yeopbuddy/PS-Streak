#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T, N, K;
    cin >> T;
    
    for(int t = 0; t < T; t++){
        
        cin >> N >> K;
        
        vector<int> numbers(N);
        
        for(int n = 0; n < N; n++) cin >> numbers[n];
        
        sort(numbers.begin(), numbers.end());
        
        int lp = 0;
        int rp = N - 1;
        int cd = 1e9;
        int cp = 0;
        
        while(lp < rp){
            int ccd; // abs diff
            int cs = numbers[lp] + numbers[rp];
            if(cs <= K){
                ccd = K - cs;
                ++lp;
            }else{
                ccd = cs - K;
                --rp;
            }
            if(ccd < cd){
                cd = ccd;
                cp = 1;
            }else if(ccd == cd) ++cp;
        }
        
        cout << cp << "\n";
    }

    return 0;
}