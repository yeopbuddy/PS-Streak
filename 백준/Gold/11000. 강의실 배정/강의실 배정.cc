#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Time{
    int st, ed;
};

bool Compare(Time t1, Time t2){
    if(t1.st == t2.st) return t1.ed < t2.ed;
    return t1.st < t2.st;
}

struct Cmp{
    bool operator()(Time t1, Time t2){
        return t1.ed > t2.ed;
    }
};

int main(){
    
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n; cin >> n;
    
    vector<Time> v(n);
    
    for(int i = 0; i < n; i++) cin >> v[i].st >> v[i].ed;
    
    sort(v.begin(), v.end(), Compare); // vector로 받아 정렬
    
    // 우선 순위 기준 세워진 pq에 하나씩 넣고 빼며 카운트

    priority_queue<Time, vector<Time>, Cmp> pq;

    int cnt = 1;
    pq.push({v[0]});

    for(int i = 1; i < n; i++){
        // cout << "top is " << pq.top().st << " " << pq.top().ed << "\n";
        // cout << "curr is " << v[i].st << " " << v[i].ed << "\n";
        if(pq.top().ed <= v[i].st){
            pq.pop();
            pq.push(v[i]);
        }else{
            cnt++;
            pq.push(v[i]);
        }
    }

    cout << cnt;
    
    return 0;
}