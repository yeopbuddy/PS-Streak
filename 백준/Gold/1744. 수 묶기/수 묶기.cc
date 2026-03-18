#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    
    int N, S; cin >> N;
    
    vector<int> M;
    vector<int> P;
    bool Z = false;
    
    for(int i = 0; i < N; i++){
        cin >> S;
        if(S < 0) M.push_back(S); 
        else if(S > 0) P.push_back(S);
        else Z = true;
    }

    sort(M.begin(), M.end());
    sort(P.begin(), P.end(), greater<>());

    int Ans = 0;
    int Idx = 0;
    
    while(Idx < M.size()){
        if (Idx + 1 < M.size()){
            Ans += (M[Idx] * M[Idx + 1]);
            ++Idx;
        }else if(!Z) Ans += M[Idx];
        ++Idx;
    } Idx = 0;
    while(Idx < P.size()){
        if (Idx + 1 < P.size() && P[Idx] * P[Idx + 1] > P[Idx] + P[Idx + 1]){
            Ans += (P[Idx] * P[Idx + 1]);
            ++Idx;
        }else Ans += P[Idx];
        ++Idx;
    }

    cout << Ans;

    return 0;
}