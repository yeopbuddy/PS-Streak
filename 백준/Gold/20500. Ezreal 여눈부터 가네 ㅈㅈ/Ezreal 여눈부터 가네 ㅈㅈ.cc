#include <iostream>

using namespace std;

int main(){
    
    int64_t _15[2048] = {0};
    
    for(int32_t i = 0; i < 4; i++)
    {
        _15[i] = i / 2;
    }
    
    for(int32_t i = 4; i <= 1515; i++)
    {
        _15[i] = ((_15[i - 2] << 1) % (int64_t)(1e9 + 7) + (_15[i - 1]) % (int64_t)(1e9 + 7)) % (int64_t)(1e9 + 7);
    }
 
    int32_t N;
    
    cin >> N;
    
    cout << _15[N];
}