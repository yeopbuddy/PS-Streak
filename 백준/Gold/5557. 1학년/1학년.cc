// 260103 백준
// https://www.acmicpc.net/problem/5557

#include <iostream>
#include <vector> 

using namespace std;

int main(){
    
    int N;
    cin >> N;

    vector<vector<long long>> Nums(22, vector<long long>(N, 0));
    
    for(int i = 0; i < N; i++) cin >> Nums[0][i];
    
    Nums[Nums[0][0] + 1][0] = 1;
    
    for(int i = 1; i < N - 1; i++){
        for(int j = 1; j < 22; j++){
            if(Nums[j][i - 1] > 0){
                long long p = j - 1 + Nums[0][i];
                long long m = j - 1 - Nums[0][i];
                if(0 <= p && p <= 20) Nums[p + 1][i] += Nums[j][i - 1];
                if(0 <= m && m <= 20) Nums[m + 1][i] += Nums[j][i - 1];
            }
        }
    }
    
    cout << Nums[Nums[0][N - 1] + 1][N - 2];
    
    return 0;
}