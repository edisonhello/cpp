// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC diagnostic ignored "-W"

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <utility>
#include <functional>
#include <complex>
#include <climits>
#include <random>
#include <thread>

#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#endif

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/rope>

using namespace std;
// using namespace __gnu_pbds;

#define ld long double
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define vint vector<int>
#define vpii vector<pair<int, int>>
#define SS stringstream
#define PQ priority_queue
#define MS(x, v) memset((x), (v), sizeof(x))
#define RZUNI(x) sort(x.begin(), x.end()), x.resize(unique(x.begin(), x.end()) - x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0), cin.tie(0)
#define FIO(fname) freopen(fname ".in", "r", stdin), freopen(fname ".out", "w", stdout)
#define FIN(fname) freopen(fname, "r", stdin)
#define FOUT(fname) freopen(fname, "w", stdout)

#define tm Ovuvuevuevue
#define y1 Enyetuenwuevue
#define left Ugbemugbem
#define ws Osas
#define dec tetteterette
#define expl explexplexpl
#define data datadetedoto

#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

#ifdef WEAK
#include"/home/edison/Coding/cpp/template/debug.cpp"
#define DEB(...) printf(__VA_ARGS__), fflush(stdout)
#define WHR() printf("%s: Line %d\n", __PRETTY_FUNCTION__, __LINE__), fflush(stdout)
#define LOG(...) printf("%s: Line %d ", __PRETTY_FUNCTION__, __LINE__), printf(__VA_ARGS__), puts(""), fflush(stdout)
#define DEBUG 1
#define exit(x) cout << "exit code " << x << endl, exit(0)
#else
#define PDE(...) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define DEBUG 0
#endif

#define lowbit(x) ((x) & (-(x)))

void JIZZ(string output = ""){ cout << output; exit(0); }

const long double PI = 3.14159265358979323846264338327950288;
const long double eps = 1e-10;
const long long mod = 1e9+7;

vector<int> prod(const vector<int> &a, const vector<int> &b) {
	vector<int> c(a.size() + b.size(), 0);
	for (int i = 0; i < (int)a.size(); ++i) for (int j = 0; j < (int)b.size(); ++j) {
		(c[i + j] += 1ll * a[i] * b[j] % mod) >= mod ? c[i + j] -= mod : 0;
		PDE(i, j, c);
	}
	PDE(a, b, c);
	return c;
}

int main() {
    CPPinput;
	int n; cin >> n;
	vector<int> a(n + 1);
	vector<int> b(n + 1), bpre(n + 1);
	for (int i = 0; i <= n; ++i) cin >> a[i];
	for (int i = 0; i <= n; ++i) a[i] = (a[i] + mod) % mod;
	auto na = a;
	for (int i = 0; i <= n; ++i) cin >> b[i];
	for (int i = 0; i <= n; ++i) b[i] = (b[i] + mod) % mod;
	bpre[0] = b[0];
	for (int i = 1; i <= n; ++i) (bpre[i] = bpre[i - 1] + b[i]) >= mod ? bpre[i] -= mod : 0;
	vector<int> c = prod(a, b);
	vector<int> cpre(c.size());
	cpre[0] = c[0];
	for (int i = 1; i < (int)c.size(); ++i) (cpre[i] = cpre[i - 1] + c[i]) >= mod ? cpre[i] -= mod : 0;

	vector<pair<int, int>> recent;
	set<int> change;
	const int bufsize = 2;

	int m; cin >> m;
	for (int i = 0; i < m; ++i) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			int l, r; cin >> l >> r;
			int ans = (cpre[r] - (l ? cpre[l - 1] : 0) + mod); ans >= mod ? ans -= mod : 0;
			PDE(ans);
			for (int i : change) {
				int v = na[i], ov = a[i];
				int ll = i, rr = i + n;
				ll = max(ll, l);
				rr = min(rr, r);
				if (ll > rr) continue;
				PDE(ll, rr);
				ll -= i, rr -= i;
				PDE(ll, rr);
				int dta = (v - ov + mod); dta >= mod ? dta -= mod : 0;
				PDE(dta);
				dta = 1ll * dta * (bpre[rr] - (ll ? bpre[ll - 1] : 0) + mod) % mod;
				PDE(dta);
				(ans += dta) >= mod ? ans -= mod : 0;
			}
			cout << ans << '\n';
		} else {
			int p, q; cin >> p >> q;
			q = (q + mod) % mod;
			recent.emplace_back(p, q);
			change.insert(p);
			na[p] += q;
			if (na[p] >= mod) na[p] -= mod;
			if ((int)recent.size() >= bufsize) {
				for (int i : change) a[i] = na[i];
				c = prod(a, b);
				cpre[0] = c[0];
				for (int i = 1; i < (int)c.size(); ++i) (cpre[i] = cpre[i - 1] + c[i]) >= mod ? cpre[i] -= mod : 0;
				recent.clear();
				change.clear();
			}
		}
	}
}
