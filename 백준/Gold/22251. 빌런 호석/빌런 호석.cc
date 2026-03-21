#include <iostream>
#include <string>

using namespace std;

int seg7[10][7] = { 0 };
int diff[10][10] = { 0 };
int N, K, P, X;
string s;
int ans = -1;

void dfs(int i, int p, string s) {

    if (i == K) { // 숫자의 길이 끝까지 도달했으면, 범위 검사를 수행하고 answer에 숫자를 더해준다.
        if (stoi(s) <= N && stoi(s) > 0) ++ans;
        return;
    }

    int cnum = s[i] - '0';

    for (int j = 0; j < 10; j++) { // 현재 인덱스의 숫자를 읽어 (현재 남은 반전 횟수 범위 내의)변환 가능한 숫자들을 찾고,  다음 인덱스로 넘어간다.
        if (p + diff[cnum][j] <= P) {
            char c = s[i];
            s[i] = (char)(j + 48);
            dfs(i + 1, p + diff[cnum][j], s);
            s[i] = c;
        }
    }

}

int main() {

    // 7-segment 전처리
    seg7[0][0] = seg7[0][1] = seg7[0][2] = seg7[0][4] = seg7[0][5] = seg7[0][6] = 1;
    seg7[1][2] = seg7[1][2] = seg7[1][5] = 1;
    seg7[2][0] = seg7[2][2] = seg7[2][3] = seg7[2][4] = seg7[2][6] = 1;
    seg7[3][0] = seg7[3][2] = seg7[3][3] = seg7[3][5] = seg7[3][6] = 1;
    seg7[4][1] = seg7[4][2] = seg7[4][3] = seg7[4][5] = 1;
    seg7[5][0] = seg7[5][1] = seg7[5][3] = seg7[5][5] = seg7[5][6] = 1;
    seg7[6][0] = seg7[6][1] = seg7[6][3] = seg7[6][4] = seg7[6][5] = seg7[6][6] = 1;
    seg7[7][0] = seg7[7][2] = seg7[7][5] = 1;
    seg7[8][0] = seg7[8][1] = seg7[8][2] = seg7[8][3] = seg7[8][4] = seg7[8][5] = seg7[8][6] = 1;
    seg7[9][0] = seg7[9][1] = seg7[9][2] = seg7[9][3] = seg7[9][5] = seg7[9][6] = 1;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int cnt = 0;
            for (int k = 0; k < 7; k++) {
                if (seg7[i][k] != seg7[j][k]) ++cnt;
            }
            diff[i][j] = cnt;
        }
    }

    cin >> N >> K >> P >> X;

    s = to_string(X);

    while (s.size() != K) {
        s = '0' + s;
    }

    dfs(0, 0, s);

    cout << ans;

    return 0;
}