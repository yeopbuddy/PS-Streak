// https://www.acmicpc.net/problem/17281
#include <iostream>
#include <vector>

using namespace std;

bool vis[9];
vector<int> seq;
vector<vector<int>> hits;

int n;
int ans = 0;

int cal() {
    int idx = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int uno, dos, tre; // each base
        uno = dos = tre = 0;
        int out = 0;
        while (out != 3) {
            switch (hits[i][seq[idx++]]) {
                case 0: {
                    ++out; break;
                }case 1: {
                    cur += tre; tre = dos; dos = uno; uno = 1; break;
                }case 2: {
                    cur += (dos + tre); tre = uno; dos = 1; uno = 0; break;
                }case 3: {
                    cur += (dos + tre + uno); tre = 1; uno = dos = 0; break;
                }case 4: {
                    cur += (dos + tre + uno + 1); uno = dos = tre = 0; break;
                }
            }
            idx %= 9;
        }
    }
    return cur;
}

void gen(int lev) { // generate sequence
    if (lev == 9) {
        int cur = cal();
        ans = (ans > cur ? ans : cur);
        return;
    }
    if (lev == 3) { // fixed
        seq.push_back(0);
        gen(lev + 1);
        seq.pop_back();
    }
    else {
        for (int i = 1; i < 9; i++) {
            if (!vis[i]) {
                vis[i] = true;
                seq.push_back(i);
                gen(lev + 1);
                vis[i] = false;
                seq.pop_back();
            }
        }
    }
    return;
}

int main() {

    cin >> n;
    hits.resize(n, vector<int>(9));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> hits[i][j];
        }
    }

    gen(0);

    cout << ans;

    return 0;
}