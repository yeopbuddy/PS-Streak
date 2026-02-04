#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(){
    
    int T; cin >> T;
    
    for(int t = 0; t < T; t++){
        
        int n, ex, ey;
        
        deque<pair<int, int>> dq(1);
        
        cin >> n >> dq[0].first >> dq[0].second;
        
        vector<bool> visit(n + 1, false);
        vector<pair<int, int>> cvs(n + 1);
        
        for(int i = 0; i < n + 1; i++){
            cin >> cvs[i].first >> cvs[i].second;
        }
        
        ex = cvs[n].first; ey = cvs[n].second;
        
        bool arrive = false;
        
        while(!dq.empty()){
            int px = dq.front().first;
            int py = dq.front().second;
            if(px == ex && py == ey) arrive = true;
            dq.pop_front();
            for(int i = 0; i < n + 1; i++){
                if(!visit[i] && abs(cvs[i].first - px) + abs(cvs[i].second - py) <= 1000){
                    visit[i] = true;
                    dq.push_back({cvs[i].first, cvs[i].second});
                }
            }
        }
        
        cout << (arrive ? "happy\n" : "sad\n");
        
    }

    return 0;
}