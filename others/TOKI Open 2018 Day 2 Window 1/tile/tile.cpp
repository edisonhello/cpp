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

#ifndef WEAK
#include "tile.h"
#endif

int n,k,q,m,a[300005];
int st[20][300005];

void init(){
    sort(a,a+m);
    
    a[m]=1e9+7122;
    for(int i=0;i<m;++i){
        st[0][i]=lower_bound(a,a+m,a[i]+k)-a;
        PDE(i,st[0][i]);
    }
    for(int i=1;i<20;++i){
        for(int j=0;j<m;++j){
            st[i][j]=st[i-1][st[i-1][j]];
            if(st[i-1][j]==m)st[i][j]=m;
        }
    }
}
int getans(int L,int R){
    int now=lower_bound(a,a+m,L)-a;
    int ans=0;
    for(int i=19;i>=0;--i){
        if(now==m)break;
        if(a[st[i][now]]>R)continue;
        PDE(L,R,st[i][now]);
        now=st[i][now];
        ans+=1<<i;
    }
    return ans+int(a[now]<=R);
}

void init(int N,int K,int Q,int M,vector<int> A){ tie(n,k,q,m)=tie(N,K,Q,M); copy(A.begin(),A.end(),a); init(); }
int getNumberOfSpecialTiles(int L,int R){ return getans(L,R); }

#ifdef WEAK
int main(){
    int n,k,q,m; cin>>n>>k>>q>>m;
    vector<int> a(m);
    for(int &i:a)cin>>i;
    init(n,k,q,m,a);
    while(q--){
        int l,r; cin>>l>>r;
        cout<<"Answer: "<<getans(l,r)<<endl;
    }
}
#endif
