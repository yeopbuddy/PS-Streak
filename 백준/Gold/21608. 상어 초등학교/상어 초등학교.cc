#include <iostream>

using namespace std;

int n; 
int arr[21][21];
int sit[21][21];
bool lov[401][401];
bool vis[21][21];

bool Inrange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;    
}

int main(){
    
    cin >> n;
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sit[i][j] = -1;
            for(int k = 0; k < 4; k++){
                if (Inrange(i + dx[k], j + dy[k])) ++arr[i][j];
            }
        }
    }

    int seq[401];
    int sub[4];

    for(int i = 0; i < n*n; i++){
        cin >> --seq[i];
        for(int j = 0; j < 4; j++) cin >> --sub[j];
        for(int j = 0; j < 4; j++) lov[seq[i]][sub[j]] = true;
    }

    for(int a = 0; a < n*n; a++){
        int x = n*n;
        int y = n*n;
        int adj = -1;
        int emp = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int cur = 0;
                int cra = 0;
                if(!vis[i][j]){
                    for(int k = 0; k < 4; k++){
                        if(Inrange(i + dx[k], j + dy[k])){
                            if(!vis[i + dx[k]][j + dy[k]]) cur++;
                            else if(lov[seq[a]][sit[i + dx[k]][j + dy[k]]]) cra++;
                        } 
                    }
                    if ((adj < cra) || (adj == cra && emp < cur) || (adj == cra && emp == cur && x > i) || (adj == cra && emp == cur && x == i && y > j)){
                        x = i; y = j; adj = cra; emp = cur;
                    }
                }
            }
        }
        sit[x][y] = seq[a];
        vis[x][y] = true;
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int cur = 1000;
            for(int k = 0; k < 4; k++){
                if(!Inrange(i + dx[k], j + dy[k]) || !lov[sit[i][j]][sit[i + dx[k]][j + dy[k]]]) cur /= 10;
            }
            ans += cur;
        }
    }

    cout << ans;

    return 0;
}