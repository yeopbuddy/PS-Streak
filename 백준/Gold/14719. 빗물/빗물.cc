#include <iostream>

using namespace std;

int H, W, T;
    
int arr[501][501];

int main(){
    
    cin >> H >> W;
    
    for(int w = 0; w < W; w++){
        cin >> T;
        for(int t = 0; t < T; t++) arr[t][w] = 1;
    }
    
    int cnt = 0;
    
    for(int i = 0; i < H; i++){
        int tmp = 0;
        bool open = false;
        for(int j = 0; j < W; j++){
            if(open){ 
                if(arr[i][j] == 0) tmp++;
                else{
                    cnt += tmp;
                    tmp = 0;
                    open = false;    
                }
            }else if(j > 0 && arr[i][j - 1] == 1 && arr[i][j] == 0){
                open = true;
                tmp++;
            }
        }
    }
    
    cout << cnt;

    return 0;
}