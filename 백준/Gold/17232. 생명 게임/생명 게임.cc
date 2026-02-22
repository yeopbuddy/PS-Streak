#include <iostream>
#include <algorithm>

using namespace std;

char arr[101][101];

int main(){
    
    int N, M, T, K, A, B;
    
    cin >> N >> M >> T >> K >> A >> B;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }
    
    while(T-- != 0){
        
        int sfa[101][101];
        char subarr[101][101];
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                sfa[i][j] = 0;
                subarr[i][j] = '.';
            }
        }
        
        sfa[0][0] = (arr[0][0] == '*' ? 1 : 0);
        
        for(int i = 1; i < N; i++) sfa[i][0] = sfa[i - 1][0] + (arr[i][0] == '*' ? 1 : 0);
        for(int j = 1; j < M; j++) sfa[0][j] = sfa[0][j - 1] + (arr[0][j] == '*' ? 1 : 0);
        
        for(int i = 1; i < N; i++){
            for(int j = 1; j < M; j++){
                sfa[i][j] = sfa[i-1][j] + sfa[i][j-1] - sfa[i-1][j-1] + (arr[i][j] == '*' ? 1 : 0);   
            }
        }
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){

                int sx = max(0, i - K), sy = max(0, j - K);
                int ex = min(N - 1, i + K), ey = min(M - 1, j + K);
        
                int heart = sfa[ex][ey];
                
                if(sx > 0) heart -= sfa[sx - 1][ey];
                if(sy > 0) heart -= sfa[ex][sy - 1];
                if(sx > 0 && sy > 0) heart += sfa[sx - 1][sy - 1];
        
                if(arr[i][j] == '*') --heart;
                
                if(A <= heart && heart <= B && arr[i][j] == '*'){ // 생존
                    subarr[i][j] = '*';
                }else if(A < heart && heart <= B && arr[i][j] == '.'){ // 탄생
                    subarr[i][j] = '*';
                }// else if(heart < A && arr[i][j] == '*'){ // 고독
                //     subarr[i][j] = '.';
                // }else if(B < heart && arr[i][j] == '*'){ // 과밀
                //     subarr[i][j] = '.';
                // }
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                arr[i][j] = subarr[i][j];
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << arr[i][j];
        }
        cout << "\n";
    }
    return 0;
}