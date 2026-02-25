#include <iostream>

using namespace std;

int n;
int arr[500][500];
int outSand = 0;

void Movesand(int x, int y, int didx) {
    if (arr[x][y] == 0) return;

    int totalSand = arr[x][y];
    int spreadSum = 0;

    int p1 = totalSand * 1 / 100;
    int p2 = totalSand * 2 / 100;
    int p5 = totalSand * 5 / 100;
    int p7 = totalSand * 7 / 100;
    int p10 = totalSand * 10 / 100;

    // (1%, 1%, 2%, 2%, 7%, 7%, 10%, 10%, 5%, alpha)
    int dx[4][10] = {
        {-1, 1, -2, 2, -1, 1, -1, 1, 0, 0},  // Left
        {-1, -1, 0, 0, 0, 0, 1, 1, 2, 1},   // Down
        {-1, 1, -2, 2, -1, 1, -1, 1, 0, 0},  // Right
        {1, 1, 0, 0, 0, 0, -1, -1, -2, -1}   // Up
    };
    int dy[4][10] = {
        {1, 1, 0, 0, 0, 0, -1, -1, -2, -1},  // Left
        {-1, 1, -2, 2, -1, 1, -1, 1, 0, 0},  // Down
        {-1, -1, 0, 0, 0, 0, 1, 1, 2, 1},    // Right
        {-1, 1, -2, 2, -1, 1, -1, 1, 0, 0}   // Up
    };
    int rates[9] = {1, 1, 2, 2, 7, 7, 10, 10, 5};

    for (int i = 0; i < 10; i++) {
        int nx = x + dx[didx][i];
        int ny = y + dy[didx][i];
        int sand;

        if (i < 9) { 
            sand = totalSand * rates[i] / 100;
            spreadSum += sand;
        } else { 
            sand = totalSand - spreadSum;
        }

        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            arr[nx][ny] += sand;
        } else {
            outSand += sand; 
        }
    }

    arr[x][y] = 0;
}

int main(){
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    int x, y;
    x = y = n/2;
    
    int plus = 0;
    int dist = 1;
    int didx = 0;
    
    int dx[4] = {0,1,0,-1};
    int dy[4] = {-1,0,1,0};
    
    bool arrived = false;
    
    while (!arrived) {
        for (int i = 0; i < 2; i++) {
            for (int d = 0; d < dist; d++) {
                x += dx[didx];
                y += dy[didx];
                
                Movesand(x, y, didx); 
                
                if (x == 0 && y == 0) {
                    arrived = true;
                    break;
                }
            }
            if (arrived) break;
            didx = (didx + 1) % 4;
        }
        dist++;
    }

    cout << outSand;
    
    return 0;
}