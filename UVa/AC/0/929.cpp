#include<cassert>
#include<cstdio>
#include<cstdlib>
// #include<cstring>
// #include<cmath>
// #include<ctime>
#include<algorithm>
// #include<iostream>
// #include<iomanip>
// #include<sstream>
// #include<deque>
#include<queue>
// #include<stack>
// #include<map>
// #include<set>
// #include<unordered_map>
// #include<unordered_set>
// #include<bitset>
// #include<utility>
#include<vector>
#include<ext/pb_ds/priority_queue.hpp>

using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define LN(x) ((int)(x).length())
#define rz(x) resize(x)
#define reset(x,n) (x).clear(), (x).resize(n)
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vint vector<int>
#define el putchar('\n')
#define spc putchar(' ')
#define SS stringstream
#define PQ priority_queue
#define PRF(...) printf(__VA_ARGS__)
#define MS(x,v) memset((x),(v),sizeof(x))
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x3f,sizeof(x))
#define MSBB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define MSMB(x) memset((x),0x80,sizeof(x))
#define PAR(x,n) for(int ___=0;___<(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define PAR1(x,n) for(int ___=1;___<=(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define CIO ios_base::sync_with_stdio(0);
#define FLH fflush(stdout)

#define tm Ovuvuevuevue
#define y2 Enyetuenwuevue
#define left Ugbemugbem
#define Osas

#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl

#ifdef WEAK
#define PDE1(a) cout<<#a<<" = "<<(a)<<'\n'
#define PDE2(a,b) cout<<#a<<" = "<<(a)<<" , ", PDE1(b)
#define PDE3(a,b,c) cout<<#a<<" = "<<(a)<<" , ", PDE2(b,c)
#define PDE4(a,b,c,d) cout<<#a<<" = "<<(a)<<" , ", PDE3(b,c,d)
#define PDE5(a,b,c,d,e) cout<<#a<<" = "<<(a)<<" , ", PDE4(b,c,d,e)
#define DEB(...) printf(__VA_ARGS__),fflush(stdout)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__),fflush(stdout)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__),fflush(stdout)
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#else
#define PDE1(a) ;
#define PDE2(a,b) ;
#define PDE3(a,b,c) ;
#define PDE4(a,b,c,d) ;
#define PDE5(a,b,c,d,e) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define endl '\n'
#define getchar gtx
#ifdef WEA
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#else
#define FIN ;
#define FOUT ;
#endif
#endif

// template<typename TA,typename TB> ostream& operator<<(ostream& ostm, const pair<TA,TB> &p){ostm<<"("<<p.X<<","<<p.Y<<")";return ostm;}
// template<typename T> ostream& operator<<(ostream &ostm, const vector<T> &v){ostm<<"[ ";for(auto i:v)ostm<<i<<" ";ostm<<"]";return ostm;}
// template<typename TA,typename TB> ostream& operator<<(ostream &ostm, const map<TA,TB> &mp){ostm<<"[ ";for(auto &it:mp)ostm<<it<<" ";ostm<<"]";return ostm;}
// template<typename T> ostream& operator<<(ostream &ostm,const set<T> &s){ostm<<"[ ";for(auto &it:s)ostm<<it<<" ";ostm<<"]";return ostm;}
// template<typename T> ostream& operator<<(ostream &ostm,const stack<T> &inp){stack<T> st=inp;ostm<<"[ ";while(!st.empty()){ostm<<st.top()<<" ";st.pop();}ostm<<"]";return ostm;}
// template<typename T> ostream& operator<<(ostream &ostm,const queue<T> &inp){queue<T> q=inp;ostm<<"[ ";while(!q.empty()){ostm<<q.front()<<" ";q.pop();}ostm<<"]";return ostm;}
// template<typename T> ostream& operator<<(ostream &ostm,const priority_queue<T> &inp){priority_queue<T> pq=inp;ostm<<"[ ";while(!pq.empty()){ostm<<pq.top()<<" ";pq.pop();}ostm<<"]";return ostm;}
// template<typename T> ostream& operator<<(ostream &ostm,const deque<T> &inp){deque<T> dq=inp;ostm<<"[ ";while(!dq.empty()){ostm<<dq.front()<<" ";dq.pop_front();}ostm<<"]";return ostm;}

#define lowbit(x) ((x)&(-(x)))

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
// void JIZZ(){cout<<"";exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-8;
const ll mod=1e9+7;

struct meow{int x,y,d;};
bool operator<(const meow &a,const meow &b){return a.d<b.d;}
bool operator>(const meow &a,const meow &b){return a.d>b.d;}

using namespace __gnu_pbds;
int a[1111][1111],d[1111][1111];
bool v[1111][1111];
__gnu_pbds::PQ<meow,greater<meow>,pairing_heap_tag>::point_iterator its[1111][1111];
int main(){
    int ts;rit(ts);while(ts--){
        int n,m;rit(n,m);
        for(int i=0;i<n;++i)for(int j=0;j<m;++j)rit(a[i][j]),d[i][j]=999999999,v[i][j]=0,its[i][j]=0;
        d[0][0]=a[0][0]; __gnu_pbds::PQ<meow,greater<meow>,pairing_heap_tag> pq; pq.push({0,0,a[0][0]});
        while(pq.size()){
            while(pq.size() && v[pq.top().x][pq.top().y])pq.pop();
            if(pq.empty())break;
            int nx=pq.top().x,ny=pq.top().y,nd=pq.top().d; pq.pop();
            v[nx][ny]=1;
            if(nx && !v[nx-1][ny] && d[nx-1][ny]>nd+a[nx-1][ny]){
                d[nx-1][ny]=nd+a[nx-1][ny];
                if(its[nx-1][ny]!=0)pq.modify(its[nx-1][ny],{nx-1,ny,d[nx-1][ny]});
                else its[nx-1][ny]=pq.push({nx-1,ny,d[nx-1][ny]});
            }
            if(nx<n-1 && !v[nx+1][ny] && d[nx+1][ny]>nd+a[nx+1][ny]){
                d[nx+1][ny]=nd+a[nx+1][ny];
                if(its[nx+1][ny]!=0)pq.modify(its[nx+1][ny],{nx+1,ny,d[nx+1][ny]});
                else its[nx+1][ny]=pq.push({nx+1,ny,d[nx+1][ny]});
            }
            if(ny && !v[nx][ny-1] && d[nx][ny-1]>nd+a[nx][ny-1]){
                d[nx][ny-1]=nd+a[nx][ny-1];
                if(its[nx][ny-1]!=0)pq.modify(its[nx][ny-1],{nx,ny-1,d[nx][ny-1]});
                else its[nx][ny-1]=pq.push({nx,ny-1,d[nx][ny-1]});
            }
            if(ny<m-1 && !v[nx][ny+1] && d[nx][ny+1]>nd+a[nx][ny+1]){
                d[nx][ny+1]=nd+a[nx][ny+1];
                if(its[nx][ny+1]!=0)pq.modify(its[nx][ny+1],{nx,ny+1,d[nx][ny+1]});
                else its[nx][ny+1]=pq.push({nx,ny+1,d[nx][ny+1]});
            }
        }
        pit(d[n-1][m-1]),el;
    }
}