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
const ll mod=1e9+7;

int a[1044];
int n,s,m; 

int dfs(int now){
    if(now>n){
        for(int i=2;i<=n;++i){
            bool diff=0;
            for(int j=1;j<=i/2;++j){
                if(a[j]!=a[i+1-j]){
                    diff=1;
                    break;
                }
            }
            if(!diff)return 0;
        }
        return 1;
    }
    int r=0;
    for(int i=1;i<=s;++i){
        a[now]=i;
        r+=dfs(now+1);
        if(r>=m)r-=m;
    }
    return r;
}

int pw(int b,int n,int a=1){
    while(n){
        if(n&1)a=1ll*a*b%m;
        b=1ll*b*b%m; n>>=1;
    }
    return a;
}


int main(){
    CPPinput;
    cin>>n>>s>>m;
    for(int i=2;i<=n;++i){
        a[i]=(1ll*s*a[i-1]%m+1ll*pw(s,(i+1)/2)-1ll*a[(i+1)/2]+m)%m;
        PDE(i,a[i]);
    }
    cout<<(0ll+pw(s,n)-a[n]+m)%m<<endl;
    /* m=mod;
    for(s=1;s<=10;++s){
        for(n=1;n<=10;++n){
            cout<<dfs(1)<<",";
        }
        cout<<endl;
    } */
    // cout<<dfs(1)<<endl;
}