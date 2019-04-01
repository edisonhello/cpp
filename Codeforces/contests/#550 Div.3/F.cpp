#include <bits/stdc++.h>
using namespace std;

pair<int, int> edg[200005];
vector<int> G[200005];
int c[200005];

bool dfs(int now, int cur) {
    c[now] = cur;
    for (int i : G[now]) {
        if (c[i]) {
            if (c[i] == cur) return false;
        } else {
            if (!dfs(i, 3 - cur)) return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        edg[i] = make_pair(u, v);
    }
    if (!dfs(1, 1)) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (int i = 0; i < m; ++i) {
            if (c[edg[i].first] == 1) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
}
