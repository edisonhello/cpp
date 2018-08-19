// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

struct sADD{ int *ptr,mod; sADD(int mod):ptr(0),mod(mod){} } ADD(mod);
sADD& operator<(const int &x,sADD &op){ op.ptr=&x; return op; }
int operator>(const sADD &op,const int y){ *op.ptr+=y; if(*op.ptr>=op.mod)*op.ptr-=op.mod; return *op.ptr; }

struct sMNS{ int *ptr,mod; sMNS(int mod):ptr(0),mod(mod){} } MNS(mod);
sMNS& operator<(const int &x,sMNS &op){ op.ptr=&x; return op; }
int operator>(const sMNS &op,const int y){ *op.ptr-=y; if(*op.ptr<0)*op.ptr+=op.mod; return *op.ptr; }

struct sTMS{ int *ptr,mod; sTMS(int mod):ptr(0),mod(mod){} } TMS(mod);
sTMS& operator<(const int &x,sTMS &op){ op.ptr=&x; return op; }
int operator>(const sTMS &op,const int y){ *op.ptr=1ll*(*op.ptr)*y%op.mod; return *op.ptr; }

int POW(int b,int n,int a=1){
    if(!n)return !b?b:a;
    if(n&1)return POW(b<TMS>b,n>>1,a<TMS>b);
    else return POW(b<TMS>b,n>>1,a);
}

struct sINV{ int mod; sINV(int mod):mod(mod){} } INV(mod);
int operator()(const sINV &op,const int x){ return POW(x,op.mod-2); }

struct sDIV{ int *ptr,mod; sDIV(int mod):ptr(0),mod(mod){} } DIV(mod);
sDIV& operator<(const int &x,sDIV &op){ op.ptr=&x; return op; }
int operator>(const sDIV &op,const int y){ *op.ptr=1ll*(*op.ptr)*INV(y)%op.mod; return *op.ptr; }

int main(){
    CPPinput;
}
