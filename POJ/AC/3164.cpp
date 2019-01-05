#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn = 103;

struct DMST{
    static const double inf = 1e10;

    double g[maxn][maxn], fw[maxn];
    int n, fr[maxn];
    bool vis[maxn], nil[maxn];
    void clear() {
        for(int i = 0; i < maxn; ++i) {
            for(int j = 0; j < maxn; ++j) {
                g[i][j] = inf;
            }
            vis[i] = false;
            nil[i] = true;
        }
    }
    void addedge(int u, int v, double w) {
        g[u][v] = min(g[u][v], w);
    }
    double operator()(int root, int _n) {
        n = _n;
        if (dfs(root) != n) return -1;
        double ans = 0;
        while (true) {
            for (int i = 1; i <= n; ++i) fw[i] = inf, fr[i] = i;
            for (int i = 1; i <= n; ++i) if (nil[i]) {
                for (int j = 1; j <= n; ++j) {
                    if (nil[j] && i != j && g[j][i] < fw[i]) {
                        fw[i] = g[j][i];
                        fr[i] = j;
                    }
                }
            }

            int x = -1;
            for (int i = 1; i <= n; ++i) if (i != root && nil[i]) {
                int j = i, c = 0;
                while (j != root && fr[j] != i && c <= n) ++c, j = fr[j];
                if (j == root || c > n) continue;
                else { x = i; break; }
            }
    
            if (!~x) {
                for (int i = 1; i <= n; ++i) if (i != root && nil[i]) ans += fw[i];
                return ans;
            }

            for (int i = 1; i <= n; ++i) vis[i] = false;
            int y = x;
            do {
                ans += fw[y]; y = fr[y]; vis[y] = true; nil[y] = false;
            } while (y != x);
            nil[x] = true;

            for (int k = 1; k <= n; ++k) if (vis[k]) {
                for (int j = 1; j <= n; ++j) if (!vis[j]) {
                    if (g[x][j] > g[k][j]) g[x][j] = g[k][j];
                    if (g[j][k] < inf && g[j][k] - fw[k] < g[j][x]) g[j][x] = g[j][k] - fw[k];
                }
            }
        }
        return ans;
    }
    int dfs(int now) {
        int r = 1;
        vis[now] = true;
        for (int i = 1; i <= n; ++i) if (g[now][i] < inf && !vis[i]) r += dfs(i);
        return r;
    }
} meow;

double pos[maxn][2];

int main() {
    int n, m; while (scanf("%d%d", &n, &m) == 2) {
        meow.clear();
        for (int i = 1; i <= n; ++i) {
            scanf("%lf%lf", &pos[i][0], &pos[i][1]);
        }
        while (m--) {
            int u, v; scanf("%d%d", &u, &v);
            meow.addedge(u, v, sqrt(pow(pos[u][0] - pos[v][0], 2) + pow(pos[u][1] - pos[v][1], 2)));
        }
        double ans = meow(1, n);
        if (ans < 0) {
            printf("poor snoopy\n");
        } else {
            printf("%.2f\n", ans);
        }
    }
}