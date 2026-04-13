#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first == p2.first)
    {
        return p1.second < p2.second;
    }
    else
    {
        return p1.first < p2.first;
    }
}

int main()
{
    int N, L, S, E, C, CC, n;
    
    cin >> N >> L;
    
    vector<pair<int, int>> Rains(N);
    
    for(n = 0; n < N; n++)
    {
        cin >> Rains[n].first >> Rains[n].second;
    }
    
    sort(Rains.begin(), Rains.end(), Compare);
    
    S = Rains[0].first;
    C = (Rains[0].second - Rains[0].first) / L;
    
    if((Rains[0].second - Rains[0].first) % L != 0)
    {
        ++C;
    }
    
    E = S + L * C;
    
    for(n = 1; n < N; n++)
    {
        if(Rains[n].first < E)
        {
            if(Rains[n].second <= E)
            {
                continue;
            }
            
            S = E;
            
            CC = (Rains[n].second - S) / L;
            
            if((Rains[n].second - S) % L != 0)
            {
                ++CC;
            }
            
            C += CC;
            
            E = S + L * CC;
        }
        else
        {
            S = Rains[n].first;
            
            CC = (Rains[n].second - Rains[n].first) / L;
    
            if((Rains[n].second - Rains[n].first) % L != 0)
            {
                ++CC;
            }
            
            C += CC;
            
            E = S + L * CC;
        }
    }
    
    cout << C;
}