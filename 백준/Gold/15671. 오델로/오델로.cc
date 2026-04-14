#include <iostream>
#include <vector>
using namespace std;

int board[6][6];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

void place(int r, int c, int color)
{
    board[r][c] = color;
    for(int d = 0; d < 8; d++)
    {
        int nx = r + dx[d], ny = c + dy[d];
        vector<pair<int,int>> flips;
        while(0 <= nx && nx < 6 && 0 <= ny && ny < 6 && board[nx][ny] == -color)
        {
            flips.push_back({nx, ny});
            nx += dx[d]; ny += dy[d];
        }
        if(0 <= nx && nx < 6 && 0 <= ny && ny < 6 && board[nx][ny] == color)
            for(auto [x, y] : flips) board[x][y] = color;
    }
}

int main()
{
    
    board[2][2] = -1; board[3][3] = -1;
    board[2][3] =  1; board[3][2] =  1;

    int N, r, c;
    cin >> N;
    int color = 1;
    for(int i = 0; i < N; i++)
    {
        cin >> r >> c;
        place(r-1, c-1, color);
        color = -color;
    }

    int black = 0, white = 0;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(board[i][j] == 1)  
            { 
                cout << 'B'; black++; 
            }
            else if(board[i][j] == -1) 
            { 
                cout << 'W'; white++; 
            }
            else 
            {
                cout << '.';
            }
        }
        cout << '\n';
    }
    cout << (black > white ? "Black" : "White") << '\n';

    return 0;
}