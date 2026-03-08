// https://www.acmicpc.net/problem/2493

#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n; cin >> n;
    
    vector<int> buildings(n);
    
    for(int i = 0; i < n; i++) cin >> buildings[i];

    vector<int> laser(n, 0);
    vector<pair<int, int>> stack;

    for(int i = n - 1; i >= 0; i--){
        while(!stack.empty() && stack.back().first < buildings[i]){
            laser[stack.back().second] = i + 1;
            stack.pop_back();
        }stack.push_back({buildings[i], i});
    }
    
    for(int l : laser) cout << l << " ";

    return 0;
}