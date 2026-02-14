#include <iostream>
#include <vector>

using namespace std;

int r, c;
char gas[32][32];

bool Isopen(int x, int y, int d){
    
    // to !
    char U[] = {'|', '+', '1', '4'};
    char D[] = {'|', '+', '2', '3'};
    char R[] = {'-', '+', '3', '4'};
    char L[] = {'-', '+', '1', '2'};
    
    if(0 > x || x >= r || 0 > y || y >= c) return false;
    
    switch(d){
        case 0:{
            for(int i = 0; i < 4; i++){
                if(gas[x][y] == U[i]) return true;
            }
            break;
        }case 1:{
            for(int i = 0; i < 4; i++){
                if(gas[x][y] == D[i]) return true;
            }
            break;
        }case 2:{
            for(int i = 0; i < 4; i++){
                if(gas[x][y] == R[i]) return true;
            }
            break;
        }case 3:{
            for(int i = 0; i < 4; i++){
                if(gas[x][y] == L[i]) return true;
            }
            break;
        }
    }
    return false;
}

int main(){
    
    cin >> r >> c;
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> gas[i][j];
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(gas[i][j] == '.'){
                int cux, cuy, cdx, cdy, crx, cry, clx, cly;
                cux = i - 1; cuy = j; cdx = i + 1; cdy = j; crx = i; cry = j + 1; clx = i; cly = j - 1;
                bool BU = (Isopen(cux, cuy, 0) ? true : false);
                bool BD = (Isopen(cdx, cdy, 1) ? true : false);
                bool BR = (Isopen(crx, cry, 2) ? true : false);
                bool BL = (Isopen(clx, cly, 3) ? true : false);
                
                // 4 sides open -> '+'    
                if(BU && BD && BR && BL) cout << i + 1 << " " << j + 1 << " +";
                // left, right open -> '-'
                else if(BL && BR) cout << i + 1 << " " << j + 1 << " -";
                // up, down open -> '|'
                else if(BU && BD) cout << i + 1 << " " << j + 1 << " |";
                // down, right open -> '1'
                else if(BD && BR) cout << i + 1 << " " << j + 1 << " 1";
                // up, right open -> '2'
                else if(BU && BR) cout << i + 1 << " " << j + 1 << " 2";
                // left, up open -> '3'
                else if(BL && BU) cout << i + 1 << " " << j + 1 << " 3";
                // left, down open -> '4'    
                else if(BL && BD) cout << i + 1 << " " << j + 1 << " 4";
            }
        }
    }

    return 0;
}