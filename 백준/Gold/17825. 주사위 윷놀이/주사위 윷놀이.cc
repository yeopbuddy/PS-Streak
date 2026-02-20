#include <iostream>

using namespace std;

int Map[9][9] = {
	{0,  0,  0,  0,  0,  0,  0,  0,  0},
	{2,  0,  0,  0,  0,  0,  0,  0,  0},
	{4,  0,  0,  0,  40, 38, 36, 0,  0},
	{6,  0,  0,  0,  35, 0,  0,  34, 0},
	{8,  0,  0,  0,  30, 0,  0,  0,  32},
	{10, 13, 16, 19, 25, 26, 27, 28, 30},
	{12, 0,  0,  0,  24, 0,  0,  0,  28},
	{0,  14, 0,  0,  22, 0,  24, 26, 0},
	{0,  0,  16, 18, 20, 22, 0,  0,  0}
};

int DirMap[9][9] = {
    {3, -1, -1, -1, -1, -1, -1, -1, -1},
    { 3, -1, -1, -1, -1, -1, -1, -1, -1},
    { 3, -1, -1, -1,  2,  0,  0, -1, -1},
    { 3, -1, -1, -1,  2, -1, -1,  6, -1},
    { 3, -1, -1, -1,  2, -1, -1, -1,  6},
    { 3,  1,  1,  1,  2,  0,  0,  0,  2},
    { 4, -1, -1, -1,  2, -1, -1, -1,  2},
    {-1,  4, -1, -1,  2, -1,  1,  5, -1},
    {-1, -1,  1,  1,  1,  5, -1, -1, -1}
};

bool Vis[10][9];

int Dice[10];

int ans = 0;

struct horses{
    int h1x, h1y, h2x, h2y, h3x, h3y, h4x, h4y;
}; horses H;

struct coord{
    int x, y;
};

// L R U D RD RU LU 
int dx[7]={0,0,-1,1,1,-1,-1};
int dy[7]={-1,1,0,0,1,1,-1};

void GetFinalD(coord& src, coord& dest, int d){
    
    int x = src.x;
    int y = src.y;
    
    if(src.x == 5 && src.y == 0){ // if at 1st blue circle
        y++; d--;    
    }else if(src.x == 8 && src.y == 4){ // if at 2nd blue circle
        x--; d--;
    }else if(src.x == 5 && src.y == 8){ // if at 3rd blue circle
        y--; d--;
    }
    
    while(d != 0){
        int nx = x + dx[DirMap[x][y]];
        int ny = y + dy[DirMap[x][y]];
        x = nx; y = ny;
        if(x == 1 && y == 4){
            break;
        } --d;
    }
    
    dest.x = x;
    dest.y = y;
}

void Simulate(int lev, int cur) {
	
	if(lev == 10) {
		ans = ans > cur ? ans : cur;
		return;
	}
	
	if(H.h1x != 1 || H.h1y != 4){ // move h1 in this turn(if not at the endpoint)
	    coord Cs = {H.h1x, H.h1y};
	    coord Ce;
	    GetFinalD(Cs, Ce, Dice[lev]); // get final destination and check visited
	    if(!Vis[Ce.x][Ce.y]){ // move(set visit), add score, recursion(next lev)
	        Vis[Cs.x][Cs.y] = false;
	        Vis[Ce.x][Ce.y] = true; Vis[1][4] = false;
	        H.h1x = Ce.x; H.h1y = Ce.y;
	        Simulate(lev + 1, cur + Map[Ce.x][Ce.y]);
	        // backtracking(move undo, visit undo)
	        Vis[Ce.x][Ce.y] = false; 
	        H.h1x = Cs.x; H.h1y = Cs.y;
	        if(Cs.x != 0 || Cs.y != 0){
	            Vis[Cs.x][Cs.y] = true;
	        }
	    }
	}if(H.h2x != 1 || H.h2y != 4){ // move h2 in this turn(if not at the endpoint)
	    coord Cs = {H.h2x, H.h2y};
	    coord Ce;
	    GetFinalD(Cs, Ce, Dice[lev]); // get final destination and check visited
	    if(!Vis[Ce.x][Ce.y]){ // move(set visit), add score, recursion(next lev)
	        Vis[Cs.x][Cs.y] = false;
	        Vis[Ce.x][Ce.y] = true; Vis[1][4] = false;
	        H.h2x = Ce.x; H.h2y = Ce.y;
	        Simulate(lev + 1, cur + Map[Ce.x][Ce.y]);
	        // backtracking(move undo, visit undo)
	        Vis[Ce.x][Ce.y] = false; 
	        H.h2x = Cs.x; H.h2y = Cs.y;
	        if(Cs.x != 0 || Cs.y != 0){
	            Vis[Cs.x][Cs.y] = true;
	        }
	    }
	}if(H.h3x != 1 || H.h3y != 4){ // move h3 in this turn(if not at the endpoint)
	    coord Cs = {H.h3x, H.h3y};
	    coord Ce;
	    GetFinalD(Cs, Ce, Dice[lev]); // get final destination and check visited
	    if(!Vis[Ce.x][Ce.y]){ // move(set visit), add score, recursion(next lev)
	        Vis[Cs.x][Cs.y] = false;
	        Vis[Ce.x][Ce.y] = true; Vis[1][4] = false;
	        H.h3x = Ce.x; H.h3y = Ce.y;
	        Simulate(lev + 1, cur + Map[Ce.x][Ce.y]);
	        // backtracking(move undo, visit undo)
	        Vis[Ce.x][Ce.y] = false; 
	        H.h3x = Cs.x; H.h3y = Cs.y;
	        if(Cs.x != 0 || Cs.y != 0){
	            Vis[Cs.x][Cs.y] = true;
	        }
	    }
	}if(H.h4x != 1 || H.h4y != 4){ // move h4 in this turn(if not at the endpoint)
	    coord Cs = {H.h4x, H.h4y};
	    coord Ce;
	    GetFinalD(Cs, Ce, Dice[lev]); // get final destination and check visited
	    if(!Vis[Ce.x][Ce.y]){ // move(set visit), add score, recursion(next lev)
	        Vis[Cs.x][Cs.y] = false;
	        Vis[Ce.x][Ce.y] = true; Vis[1][4] = false;
	        H.h4x = Ce.x; H.h4y = Ce.y;
	        Simulate(lev + 1, cur + Map[Ce.x][Ce.y]);
	        // backtracking(move undo, visit undo)
	        Vis[Ce.x][Ce.y] = false; 
	        H.h4x = Cs.x; H.h4y = Cs.y;
	        if(Cs.x != 0 || Cs.y != 0){
	            Vis[Cs.x][Cs.y] = true;
	        }
	    }
	}
	return;
}

int main() {

    H = {0,0,0,0,0,0,0,0};

	for(int i = 0; i < 10; i++) cin >> Dice[i];

	Simulate(0, 0);

	cout << ans;

	return 0;
}