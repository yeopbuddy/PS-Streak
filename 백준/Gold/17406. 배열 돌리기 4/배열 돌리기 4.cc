// 다음엔 깔끔하게 풀기 . . .
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> vec;
vector<vector<int>> tmp;
vector<tuple<int, int, int>> rot;
vector<int> Gen;
bool vis[51][51];
bool Vis[7];
int N, M, K, r, c, s;
int Ans = 1e9;

void out(){
    cout << "\n==========\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << tmp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n==========\n";
}

void cal(){
    int Cur = 1e9;
    for(int i = 0; i < N; i++){
        int Tmp = 0;    
        for(int j = 0; j < M; j++){
            Tmp += tmp[i][j];
        }
        Cur = min(Cur, Tmp);
    }
    Ans = min(Ans, Cur);
    // out();
    tmp.clear();
}

void spi(int x1, int y1, int x2, int y2){
    // cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
    for(int x = x1; x <= x2; x++){
        for(int y = y1; y <= y2; y++){
            vis[x][y] = false;
        }
    }
    int x = x1;
    int y = y1;
    while(true){
        vector<pair<int, int>> cor;
        vector<int> val;
        while(true){ // right
            vis[x][y] = true;
            cor.push_back({x, y});
            val.push_back(tmp[x][y]);
            // cout << "right - " <<  x << " " << y << "\n";
            int stp = -100;
            if(y + 1 <= y2 && !vis[x][y + 1]) y++;
            else break;   
        }while(true){ // down
            if(x + 1 <= x2 && !vis[x + 1][y]) x++;
            else break;   
            vis[x][y] = true;
            cor.push_back({x, y});
            val.push_back(tmp[x][y]);
            // cout << "down - " <<  x << " " << y << "\n";
        }while(true){ // left
            if(y - 1 >= y1 && !vis[x][y - 1]) y--;
            else break;   
            vis[x][y] = true;
            cor.push_back({x, y});
            val.push_back(tmp[x][y]);
            // cout << "left - " <<  x << " " << y << "\n";
        }while(true){ // up
            if(x - 1 >= x1 && !vis[x - 1][y]) x--;
            else break;   
            vis[x][y] = true;
            cor.push_back({x, y});
            val.push_back(tmp[x][y]);
            // cout << "up - " <<  x << " " << y << "\n";
        }
        
        int fst = val[val.size() - 1];
        for(int i = 1; i < val.size(); i++){
            tmp[cor[i].first][cor[i].second] = val[i - 1];
        }tmp[cor[0].first][cor[0].second] = fst;
        
        if(!vis[x][y + 1]) y++; // jump
        else break;
    }
}

void seq(){
    tmp = vec;
    for(int g = 0; g < K; g++){
        int r, c, s;
        tie(r, c, s) = rot[Gen[g]];
        spi(r-s-1, c-s-1, r+s-1, c+s-1);
        // cout << "spin from (" << r-s-1 <<", " << c-s-1 << ") to (" << r+s-1 << ", " << c+s-1 << ")\n";
    }
    cal();
}

void gen(int st, int ed){
    if(st == ed){
        seq();
        return;
    }
    for(int i = 0; i < ed; i++){
        if(!Vis[i]){
            Vis[i] = true;
            Gen.push_back(i);
            gen(st + 1, ed);
            Vis[i] = false;
            Gen.pop_back();
        }
    }
}



int main(){
    
    cin >> N >> M >> K;
    
    vec.resize(N, vector<int>(M));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> vec[i][j];
        }
    }

    for(int k = 0; k < K; k++){
        cin >> r >> c >> s;
        rot.push_back({r, c, s});
    }
    
    gen(0, K);
    
    cout << Ans;
    
    return 0;
}