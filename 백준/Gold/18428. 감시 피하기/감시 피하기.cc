#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    vector<vector<char>> school(n, vector<char>(n));
    vector<pair<int, int>> teacher;
    vector<pair<int, int>> blank;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> school[i][j];
            if(school[i][j] == 'X') blank.push_back({i, j});
            else if(school[i][j] == 'T') teacher.push_back({i, j});
        }
    }

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool can = false;

    for(size_t i = 0; i < blank.size(); i++){
        for(size_t j = i + 1; j < blank.size(); j++){
            for(size_t k = j + 1; k < blank.size(); k++){
                school[blank[i].first][blank[i].second] = 'O';
                school[blank[j].first][blank[j].second] = 'O';
                school[blank[k].first][blank[k].second] = 'O';
                
                bool ccan = true;
                
                for(size_t l = 0; l < teacher.size(); l++){
                    int x = teacher[l].first;
                    int y = teacher[l].second;
                    for(int m = 0; m < 4; m++){
                        int xx = x + dx[m];
                        int yy = y + dy[m];   
                        while(0 <= xx && xx < n && 0 <= yy && yy < n){
                            if(school[xx][yy] == 'O') break;
                            else if(school[xx][yy] == 'T') break;
                            else if(school[xx][yy] == 'S') ccan = false;
                            xx += dx[m];
                            yy += dy[m];
                        }
                    }
                }
                
                if(ccan) can = true;
                
                school[blank[i].first][blank[i].second] = 'X';
                school[blank[j].first][blank[j].second] = 'X';
                school[blank[k].first][blank[k].second] = 'X';
            }   
        }   
    }

    cout << (can ? "YES" : "NO");

    return 0;
}