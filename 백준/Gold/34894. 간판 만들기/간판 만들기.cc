#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long Arr[300001];

int main(){
    
    int n; string s;
    
    cin >> n >> s;
    
    for(int i = 0; i < n; i++) cin >> Arr[i];
    
    long long MinU, MinO, MinS, MinP, MinC; 
    MinU = MinO = MinS = MinP = MinC = 7e9;
    
    for(int i = 0; i < n; i++){
        if(s[i] == 'U'){
            MinU = min(MinU, Arr[i]);
        }else if(s[i] == 'O' && MinU != 7e9){
            MinO = min(MinO, Arr[i] + MinU);
        }else if(s[i] == 'S' && MinO != 7e9){
            MinS = min(MinS, Arr[i] + MinO);
        }else if(s[i] == 'P' && MinS != 7e9){
            MinP = min(MinP, Arr[i] + MinS);
        }else if(s[i] == 'C' && MinP != 7e9){
            MinC = min(MinC, Arr[i] + MinP);
        }
    }

    cout << ((MinC == 7e9) ? -1 : MinC);

    return 0;
}