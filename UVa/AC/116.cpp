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
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include<vector>
#include<utility>

using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define LN(x) ((int)(x).length())
#define rz(x) resize(x)
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vint vector<int>
#define endl '\n'
#define el putchar('\n')
#define spc putchar(' ')
#define SS stringstream
#define PQ priority_queue
#define PRF(...) printf(__VA_ARGS__)
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define MSMB(x) memset((x),0x80,sizeof(x))
#define PAR(x,n) for(int ___=0;___<(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define PAR1(x,n) for(int ___=1;___<=(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define CIO ios_base::sync_with_stdio(0);
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#define FLH fflush(stdout)

#ifdef WEAK
#define PDE1(a) cout<<#a<<" = "<<(a)<<'\n'
#define PDE2(a,b) cout<<#a<<" = "<<(a)<<" , "<<#b<<" = "<<(b)<<'\n'
#define PDE3(a,b,c) cout<<#a<<" = "<<(a)<<" , "<<#b<<" = "<<(b)<<" , "<<#c<<" = "<<(c)<<'\n'
#define PDE4(a,b,c,d) cout<<#a<<" = "<<(a)<<" , "<<#b<<" = "<<(b)<<" , "<<#c<<" = "<<(c)<<" , "<<#d<<" = "<<(d)<<'\n'
#define DEB(...) printf(__VA_ARGS__),fflush(stdout)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__),fflush(stdout)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__),fflush(stdout)
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#define FLH fflush(stdout)
#else
#define PDE1(a) ;
#define PDE2(a,b) ;
#define PDE3(a,b,c) ;
#define PDE4(a,b,c,d) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define getchar gtx
#ifdef WEA
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#define FLH fflush(stdout)
#else
#define FIN ;
#define FOUT ;
#define FLH ;
#endif
#endif

template<typename TA,typename TB> ostream& operator<<(ostream& ostm, const pair<TA,TB> &p){ostm<<"("<<p.X<<","<<p.Y<<")";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm, const vector<T> &v){ostm<<"[ ";for(auto i:v)ostm<<i<<" ";ostm<<"]";return ostm;}
template<typename TA,typename TB> ostream& operator<<(ostream &ostm, const map<TA,TB> &mp){ostm<<"[ ";for(auto it:mp)ostm<<*it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const set<T> &s){ostm<<"[ ";for(auto it:s)ostm<<*it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const stack<T> &inp){stack<T> st=inp;ostm<<"[ ";while(!st.empty()){ostm<<st.top()<<" ";st.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const queue<T> &inp){queue<T> q=inp;ostm<<"[ ";while(!q.empty()){ostm<<q.front()<<" ";q.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const priority_queue<T> &inp){priority_queue<T> pq=inp;ostm<<"[ ";while(!pq.empty()){ostm<<pq.top()<<" ";pq.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const deque<T> &inp){deque<T> dq=inp;ostm<<"[ ";while(!dq.empty()){ostm<<dq.front()<<" ";dq.pop_front();}ostm<<"]";return ostm;}

inline int lowbit(int &x){return x&-x;}
inline ll lowbit(ll &x){return x&-x;}
template<typename T>
inline T _pow(T b,int n){
    T a=1; while(n){
        if(n&1)a*=b; b*=b,n>>=1;
    } return a;
}
template<typename T>
inline T _pow(T b,int n,T mod){
    T a=1%mod; while(n){
        if(n&1)a=a*b%mod; b=b*b%mod,n>>=1;
    } return a;
}

inline int gtx(){
    const int N=1048576;
    static char __buffer[N];
    static char *__p=__buffer,*__end=__buffer;
    if(__p==__end){
        if((__end=__buffer+fread(__buffer,1,N,stdin))==__buffer)return EOF;
        __p=__buffer;
    } return *__p++;
}

template<typename T>
inline bool rit(T& x){
    char c=0; bool fg=0;
    while(c=getchar(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c-'0');
    while(c=getchar(), c>='0' && c<='9')x=x*10+c-'0';
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}

inline void pit(int x){printf("%d",x);}
inline void pln(ll x){printf("%I64d",x);}
template<typename ...Args>
inline void pit(int x,Args ...args){printf("%d ",x);pit(args...);}
template<typename ...Args>
inline void pln(ll x,Args ...args){printf("%I64d ",x);pit(args...);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-8;
const ll mod=1e9+7;

int n,m;
int mp[111][111],dp[111][111],cf[111][111];

int main(){
    FIN;FOUT;
    while(cin>>n>>m){
        MS0(dp);MS0(cf);
        for(int i=0;i<n;++i){
            for(int j=m-1;j>=0;--j){
                cin>>mp[i][j];
            }
        }
        for(int i=0;i<n;++i)dp[i][0]=mp[i][0];
        for(int j=1;j<m;++j){
            for(int i=0;i<n;++i){
                dp[i][j]=dp[i][j-1]+mp[i][j]; cf[i][j]=i;
                if(i>0){if(dp[i-1][j-1]+mp[i][j]<=dp[i][j])dp[i][j]=dp[i-1][j-1]+mp[i][j],cf[i][j]=i-1;}
                else if(dp[n-1][j-1]+mp[i][j]<dp[i][j])dp[i][j]=dp[n-1][j-1]+mp[i][j],cf[i][j]=n-1;
                if(i<n-1){if(dp[i+1][j-1]+mp[i][j]<dp[i][j]||(dp[i+1][j-1]+mp[i][j]==dp[i][j]&&cf[i][j]>i+1))dp[i][j]=dp[i+1][j-1]+mp[i][j],cf[i][j]=i+1;}
                else if(dp[0][j-1]+mp[i][j]<=dp[i][j]||(dp[0][j-1]+mp[i][j]==dp[i][j]&&cf[i][j]>0))dp[i][j]=dp[0][j-1]+mp[i][j],cf[i][j]=0;
            }
        }
        // for(int i=0;i<n;++i){
        //     for(int j=0;j<m;++j)cout<<setw(2)<<dp[i][j]<<" ";cout<<endl;
        // }
        int minat=-1,minv=(1<<30);
        for(int i=0;i<n;++i)if(dp[i][m-1]<minv)minv=dp[i][m-1],minat=i;
        queue<int> ans;int j=m-1;bool first=1;while(j>=0){
            ans.push(minat+1);
            minat=cf[minat][j];
            --j;
        } while(ans.size()){
            if(!first)cout<<" ";first=0;cout<<ans.front();ans.pop();
        } cout<<endl<<minv<<endl;
    }
}
