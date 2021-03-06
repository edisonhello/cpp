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

string s;
ll hh[100005],pp[100005];

ll gethh(int l,int r){
    return ((hh[r]-hh[l-1])*pp[100000-r]%mod+mod)%mod;
}
ll gethh(string s){
    ll rt=0;
    for(int i=0;i<int(s.size());++i){
        rt+=s[i]*pp[i+1]%mod;
    }
    rt%=mod;
    return rt*pp[100000-s.size()]%mod;
}

map<int,vector<int>> occ[11];

bool check(int l,int r,vector<string> &ss,bool ft,bool bt){
    if(ss.empty())return 1;
    if(!ft){
        auto it=occ[ss[0].size()].find(gethh(ss[0]));
        if(it==occ[ss[0].size()].end())return 0;
        auto it2=lower_bound(it->second.begin(),it->second.end(),l);
        if(it2==it->second.end() || *it2!=l)return 0;
    }
    if(!bt){
        auto it=occ[ss.back().size()].find(gethh(ss.back()));
        if(it==occ[ss.back().size()].end())return 0;
        auto it2=lower_bound(it->second.begin(),it->second.end(),r-int(ss.back().size())+1);
        if(it2==it->second.end() || *it2!=r-int(ss.back().size())+1)return 0;
    }
    for(int i=0;i<ss.size();++i){
    // for(string &s:ss){
        string s=ss[i];
        PDE(s);
        ll hh=gethh(s);
        auto it=occ[s.size()].find(hh);
        if(it==occ[s.size()].end())return 0;
        auto it2=lower_bound(it->second.begin(),it->second.end(),l);
        if(it2==it->second.end())return 0;
        int p=*it2;
        if(p+int(s.size())-1>r)return 0;
        /* if(!i){
            if(!ft && p!=l)return 0;
        }
        if(i==ss.size()-1 && !bt){
            auto it3=lower_bound(it->second.begin(),it->second.end(),r-s.size()+1);
            if(it3==it->second.end())return 0;
            if(*it3!=r-s.size()+1)return 0;
            if(i==0 && !ft && *it3!=l)return 0;
        } */
        l=p+1;
    }
    return 1;
}

int main(){
    CPPinput;
    cin>>s; s="$"+s;
    int n=s.size();
    pp[0]=47017;
    for(int i=1;i<=100002;++i)pp[i]=pp[i-1]*47017%mod;
    for(int i=1;i<=n;++i)hh[i]=(hh[i-1]+s[i]*pp[i])%mod;
    for(int z=1;z<=10;++z){
        for(int i=1;i<=n;++i){
            if(i+z-1>n)break;
            occ[z][gethh(i,i+z-1)].push_back(i);
        }
    }
    int q; cin>>q; while(q--){
        vector<string> ss;
        string ts;
        int l,r; string p; cin>>l>>r>>p; p+='*';
        for(char c:p){
            if(c=='*'){
                if(ts!="")ss.push_back(ts),ts="";
            }
            else ts+=c;
        }
        check(l,r,ss,p[0]=='*',p[p.size()-2]=='*')?Yes:No;
    }
}
