#include <iostream>
#include <vector>

using namespace std;

int main() {


    int t, n, m, x, y;
    cin >> t;

    const char* s1 = "impossible\n";
    const char* s2 = "possible\n";

    for (int T = 0; T < t; T++) {
        cin >> n >> m;
        vector<vector<int>> Adj(n);
        vector<bool> Vis(n, false);
        vector<int> Color(n, 0);
        bool res = true;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            Adj[--x].push_back(--y);
            Adj[y].push_back(x);
        }
        for (int i = 0; i < n; i++) {
            if (!Vis[i]) {
                Vis[i] = true;
                Color[i] = 1;
                vector<pair<int, bool>> vec;
                vec.push_back({ i, true });
                while (!vec.empty()) {
                    int pn = vec[vec.size() - 1].first;
                    bool pc = vec[vec.size() - 1].second;
                    vec.pop_back();
                    for (size_t j = 0; j < Adj[pn].size(); j++) {
                        if (!Vis[Adj[pn][j]]) {
                            Vis[Adj[pn][j]] = true;
                            Color[Adj[pn][j]] = (pc ? 2 : 1);
                            vec.push_back({ Adj[pn][j], !pc });
                        }
                        else {
                            if (Color[pn] == Color[Adj[pn][j]]) res = false;
                        }
                    }
                }
            }
        }
        cout << (res ? s2 : s1);
    }

    return 0;
}