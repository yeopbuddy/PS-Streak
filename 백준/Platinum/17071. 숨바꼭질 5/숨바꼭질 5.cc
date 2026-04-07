#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> DistEven(500001, -1); // 짝수 시간에 도달 가능한 최소 시간
vector<int> DistOdd(500001, -1);  // 홀수 시간에 도달 가능한 최소 시간

int main(){
    
    int N, K;
    cin >> N >> K;
    
    deque<pair<int, int>> Subin;
    
    Subin.push_back({N, 0});
    DistEven[N] = 0;
    
    while(!Subin.empty()){
        
        auto [Cp, Ct] = Subin.front();
        Subin.pop_front();
        
        int Next[3] = {Cp - 1, Cp + 1, Cp * 2};
        
        for(int Nx : Next)
        {
            if(Nx < 0 || Nx >= 500001) continue;
            
            int Nt = Ct + 1;
            
            if(Nt % 2 == 0 && DistEven[Nx] == -1)
            {
                DistEven[Nx] = Nt;
                Subin.push_back({Nx, Nt});
            }
            else if(Nt % 2 == 1 && DistOdd[Nx] == -1)
            {
                DistOdd[Nx] = Nt;
                Subin.push_back({Nx, Nt});
            }
        }
    }
    
    for(int Ct = 0; ; Ct++){
      
        int SisterPos = K + Ct * (Ct + 1) / 2;
        
        if(SisterPos >= 500001) break;
        
        int Dt = (Ct % 2 == 0) ? DistEven[SisterPos] : DistOdd[SisterPos];
        
        if(Dt != -1 && Dt <= Ct)
        {
            cout << Ct;
            return 0;
        }
    }
    
    cout << -1;
    
    return 0;
}