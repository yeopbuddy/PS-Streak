// https://www.acmicpc.net/problem/1038
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

vector<long long> dnums;

void gen(){
    
    deque<long long> dq;
    
    for(int i = 0; i < 10; i++) dq.push_back(i);
    for(int i = 0; i < 10; i++) dnums.push_back(i);
    
    while(!dq.empty()){
        long long pn = dq.front();
        dq.pop_front();
        for(int i = 0; i < 10; i++){
            if((pn % 10) <= i) break;
            dq.push_back(pn * 10 + i);
            dnums.push_back(pn * 10 + i);
        }
    }
}

void pre(){
    gen();
    sort(dnums.begin(), dnums.end());
}

int main(){

    pre();

    int n; cin >> n;
    
    if(n >= dnums.size()) cout << -1;
    else cout << dnums[n];

    return 0;
}