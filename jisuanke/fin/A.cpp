// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC diagnostic ignored "-W"

#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<vector>
#include<utility>
#include<functional>
#include<complex>
#include<climits>
#include<random>
#include<thread>

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#endif

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/rope>

using namespace std;
// using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define vint vector<int>
#define vpii vector<pair<int,int>>
#define SS stringstream
#define PQ priority_queue
#define MS(x,v) memset((x),(v),sizeof(x))
#define RZUNI(x) sort(x.begin(),x.end()), x.resize(unique(x.begin(),x.end())-x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0); cin.tie(0)
#define FIN(fname) freopen(fname,"r",stdin)
#define FOUT(fname) freopen(fname,"w",stdout)

#define tm Ovuvuevuevue
#define y1 Enyetuenwuevue
#define left Ugbemugbem
#define ws Osas
#define dec tetteterette
#define expl explexplexpl

#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl

#ifdef WEAK
#include"/home/edison/Coding/cpp/template/debug.cpp"
#define DEB(...) printf(__VA_ARGS__),fflush(stdout)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__),fflush(stdout)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__),fflush(stdout)
#define DEBUG 1
#define exit(x) cout<<"exit code "<<x<<endl, exit(0)
#else
#define PDE(...) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define DEBUG 0
#endif

#define lowbit(x) ((x)&(-(x)))

void JIZZ(string output=""){cout<<output; exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-10;
const ll mod=998244353;

int pw(int b, int n, int m, int a = 1) {
    while (n) {
        if (n & 1) a = 1ll * a * b % m;
        b = 1ll * b * b % m; n >>= 1;
    } return a;
}

int inv(int x) { return pw(x, mod - 2, mod); }

int a[500005], pos[500005], cnt[500005], ans[500005];

int main(){
    CPPinput;
    int n; cin >> n;
    vector<int> lis;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        if (lis.empty() || a[i] > lis.back()) lis.push_back(a[i]), pos[i] = lis.size();
        else {
            int p = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
            lis[p] = a[i];
            pos[i] = p + 1;
        }
        PDE(i, pos[i]);
    }
    int fi = lis.size();
    for (int i = n; i >= 1; --i) {
        if (pos[i] == fi) {
            --fi;
            ++cnt[fi + 1];
        } else if (pos[i] == fi + 1) {
            ++cnt[fi + 1];
        }
    }
    fi = lis.size();
    for (int i = n; i >= 1; --i) {
        if (pos[i] == fi) {
            --fi;
            ans[i] = inv(cnt[fi + 1]);
        } else if (pos[i] == fi + 1) {
            ans[i] = inv(cnt[fi + 1]);
        }
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << " "; cout << endl;
}
