#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int N; cin >> N;
    
    vector<int> Eat(N);
    vector<int> Pfs(N + 1, 0);
    
    for(int i = 0; i < N; i++) cin >> Eat[i];

    sort(Eat.begin(), Eat.end(), greater<int>());

    int ans = 0;
    
    for(int i = 0; i < N; i++){
        ++Pfs[i];
        --Pfs[i + Eat[i] > N ? N : i + Eat[i]];
    }
    
    for(int i = 1; i <= N; i++){
        Pfs[i] += Pfs[i - 1];
        ans = (ans > Pfs[i - 1] ? ans : Pfs[i - 1]);
    }
    
    cout << ans;
    
    return 0;
}