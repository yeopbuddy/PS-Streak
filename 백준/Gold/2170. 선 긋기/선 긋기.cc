#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(pair<int, int> p1, pair<int, int> p2){
    if(p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
}

int main(){
    
    ios:: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N; cin >> N;
    
    vector<pair<int, int>> V(N);
    
    for(int i = 0; i < N; i++){
        cin >> V[i].first >> V[i].second;
    }
    
    sort(V.begin(), V.end(), Compare);
    
    int Dist = 0;
    int Left, Right;
    for(int v = 0; v < N; v++){
        if(v == 0){
            Left = V[v].first;
            Right = V[v].second;
        }else{ // EXTEND OR ADD
            if(V[v].first <= Right) Right = max(Right, V[v].second);
            else{
                Dist += (Right - Left);
                Left = V[v].first;
                Right = V[v].second;
            }
        }
    } Dist += (Right - Left);
    cout << Dist;
    return 0;
}