#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int N, K;
    cin >> N >> K;
    
    vector<int> seq(N);
    
    for(int i = 0; i < N; i++) cin >> seq[i];
    
    int group = 0;
    int cnt[500002];
    
    for(int i = 0; i < 500002; i++) cnt[i] = 0;
    
    int idx;
    
    for(idx = 0; idx < K; idx++){
        int lg = cnt[seq[idx] - 1];
        int rg = cnt[seq[idx] + 1];
        ++cnt[seq[idx]];
        if(lg == 0 && rg == 0 && cnt[seq[idx]] == 1){
            ++group;
        }else if(lg >= 1 && rg >= 1 && cnt[seq[idx]] == 1){
            --group;
        }
        // cout << "idx is " << idx << " group is " << group << "\n";
    }--idx;
    while(group != 1){
        ++idx;
        --cnt[seq[idx - K]];
        if(cnt[seq[idx - K] - 1] >= 1 && cnt[seq[idx - K] + 1] >= 1 && cnt[seq[idx - K]] == 0){
            ++group;
        }else if(cnt[seq[idx - K] - 1] == 0 && cnt[seq[idx - K] + 1] == 0 && cnt[seq[idx - K]] == 0){
            --group;
        }
        ++cnt[seq[idx]];
        int lg = cnt[seq[idx] - 1];
        int rg = cnt[seq[idx] + 1];
        if(lg == 0 && rg == 0 && cnt[seq[idx]] == 1){
            ++group;
        }else if(lg >= 1 && rg >= 1 && cnt[seq[idx]] == 1){
            --group;
        }
        // cout << "idx is " << idx << " group is " << group << "\n";
        if(idx == N - 1) break;
    }

    if(group == 1){
        cout << "YES\n";
        for(int i = idx - K + 1; i <= idx; i++) cout << seq[i] << " ";
    }else{
        cout << "NO";
    }
    
    return 0;
}