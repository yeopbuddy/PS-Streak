#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
    
    int n, c, w;
    cin >> n >> c;
    deque<int> bucket(n);
    
    for(int i = 0; i < n; i++) cin >> bucket[i];
    sort(bucket.begin(), bucket.end());

    int ans = 0;

    while(!bucket.empty()){
        if(bucket.size() == 1){
            ++ans;
            break;
        }
        int l = bucket[0];
        int r = bucket[bucket.size() - 1];
        if(l + r < c){
            bucket.pop_front();
            bucket.pop_back();
        }else bucket.pop_back();
        ++ans;
    }

    cout << ans;

    return 0;
}