// #pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma vector temporal
// #pragma simd
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

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

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
#define exp expexpexpexp
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

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#endif

void JIZZ(string output=""){cout<<output; exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;

vector<int> G[100005];
ll w[100005];
ll tot,dta;

void xdfs(int now){
    vector<ll> v;
    for(int i:G[now]){
        xdfs(i);
        v.push_back(w[i]);
        sort(v.begin(),v.end(),greater<int>());
        if(v.size()>2u)v.pop_back();
    }
    if(v.size()>0u)tot+=max(0ll,v[0]);
    if(v.size()>1u)dta=max(dta,v[1]);
}
void ndfs(int now){
    vector<ll> v;
    for(int i:G[now]){
        ndfs(i);
        v.push_back(w[i]);
        sort(v.begin(),v.end(),less<int>());
        if(v.size()>2u)v.pop_back();
    }
    if(v.size()>0u)tot+=min(0ll,v[0]);
    if(v.size()>1u)dta=min(dta,v[1]);
}

void sol(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)G[i].clear();
    for(int i=2;i<=n;++i){
        int p; cin>>p;
        G[p].pb(i);
    }
    for(int i=1;i<=n;++i)cin>>w[i];
    tot=max(w[1],0ll); dta=0;
    xdfs(1);
    cout<<tot+dta<<" ";
    tot=min(w[1],0ll); dta=0;
    ndfs(1);
    cout<<tot+dta<<'\n';
}

int main(){
    CPPinput;
    int t; cin>>t; while(t--){
        sol();
    }
}
