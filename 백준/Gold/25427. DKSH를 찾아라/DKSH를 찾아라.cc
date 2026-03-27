#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    
    int N;
    string S;
    
    cin >> N >> S;
    
    vector<vector<long long>> DKSH(4, vector<long long>(N, 0));
    
    if(S[0] == 'D') DKSH[0][0] = 1;
    
    for(int i = 1; i < N; i++){
        for(int j = 0; j < 4; j++){
            DKSH[j][i] += DKSH[j][i - 1];
        }
        if(S[i] == 'D'){
            DKSH[0][i] = 1 + DKSH[0][i - 1];
        }else if(S[i] == 'K' && DKSH[0][i - 1] > 0){
            DKSH[1][i] = DKSH[1][i - 1] + DKSH[0][i - 1];
        }else if(S[i] == 'S' && DKSH[1][i - 1] > 0){
            DKSH[2][i] = DKSH[2][i - 1] + DKSH[1][i - 1];
        }else if(S[i] == 'H' && DKSH[2][i - 1] > 0){
            DKSH[3][i] = DKSH[3][i - 1] + DKSH[2][i - 1];
        }
    }

    cout << DKSH[3][N - 1];

    return 0;
}