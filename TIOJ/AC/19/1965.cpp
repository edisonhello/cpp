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
#define DEBUG "jizz"
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
#define DEBUG 0
#ifdef WEA
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#else
#define FIN ;
#define FOUT ;
#endif
#endif

template<typename TA,typename TB> ostream& operator<<(ostream& ostm, const pair<TA,TB> &p){ostm<<"("<<p.X<<","<<p.Y<<")";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm, const vector<T> &v){ostm<<"[ ";for(auto i:v)ostm<<i<<" ";ostm<<"]";return ostm;}
template<typename TA,typename TB> ostream& operator<<(ostream &ostm, const map<TA,TB> &mp){ostm<<"[ ";for(auto &it:mp)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const set<T> &s){ostm<<"[ ";for(auto &it:s)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const stack<T> &inp){stack<T> st=inp;ostm<<"[ ";while(!st.empty()){ostm<<st.top()<<" ";st.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const queue<T> &inp){queue<T> q=inp;ostm<<"[ ";while(!q.empty()){ostm<<q.front()<<" ";q.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const priority_queue<T> &inp){priority_queue<T> pq=inp;ostm<<"[ ";while(!pq.empty()){ostm<<pq.top()<<" ";pq.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const deque<T> &inp){deque<T> dq=inp;ostm<<"[ ";while(!dq.empty()){ostm<<dq.front()<<" ";dq.pop_front();}ostm<<"]";return ostm;}

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
inline bool rit(T &x){
    char c=0; bool fg=0;
    while(c=getchar(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c&15);
    while(c=getchar(), c>='0' && c<='9')x=x*10+(c&15);
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
void JIZZ(){cout<<"";exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-8;
const ll mod=1e9+7;
#ifndef WEAK
#include"lib1965.h"
#endif

#define ull uint64_t
// ull *a,b[420000];
// int n,nblock,blockSize,blockST[420000][4][16],bigST[20][420000];
ull *a,*b,*blockST[4][16],*bigST[20];
int n,nblock,blockSize,*lg,*iblockST[4][16],*ibigST[20];

inline void jizz(){
    b=new ull[nblock+7];

    if(n>1000000){
        for(int i=0;i<4;++i){
            for(int j=0;j<blockSize+1;++j){
                blockST[i][j]=new ull[nblock+7];
            }
        }

        int lognblock=ceil(log(nblock)/log(2));
        for(int i=0;i<lognblock+2;++i){
            bigST[i]=new ull[nblock];
        }
    }
    else{
        for(int i=0;i<4;++i){
            for(int j=0;j<blockSize+1;++j){
                iblockST[i][j]=new int[nblock+7];
            }
        }

        int lognblock=ceil(log(nblock)/log(2));
        for(int i=0;i<lognblock+2;++i){
            ibigST[i]=new int[nblock];
        }
    }
}
inline void doLog(){
    lg=new int[n+5];
    lg[1]=lg[2]=0;
    for(int i=2;i<=n;++i)lg[i]=lg[i>>1]+1;
}
inline ull buildBlockST(int n,int l,int r){
    int s=r-l+1; ull mx=0;
    for(int i=l;i<=r;++i)blockST[0][i-l][n]=a[i],mx=max(mx,a[i]);
    for(int i=1,d=1;d<s;++i,d<<=1){
        for(int j=l;j+(d<<1)-1<=r;++j){
            blockST[i][j-l][n] = max(blockST[i-1][j-l][n],blockST[i-1][j+d-l][n]);
        }
    } return mx;
}
inline void buildBigST(){
    for(int i=0;i<nblock;++i)bigST[0][i]=b[i];
    for(int i=1,d=1;d<nblock;++i,d<<=1){
        for(int j=0;j+(d<<1)-1<nblock;++j){
            bigST[i][j] = max(bigST[i-1][j],bigST[i-1][j+d]);
        }
    }
}
inline ull ibuildBlockST(int n,int l,int r){
    int s=r-l+1; ull mx=0;
    for(int i=l;i<=r;++i)iblockST[0][i-l][n]=i,mx=max(mx,a[i]);
    for(int i=1,d=1;d<s;++i,d<<=1){
        for(int j=l;j+(d<<1)-1<=r;++j){
            iblockST[i][j-l][n] = a[iblockST[i-1][j-l][n]] > a[iblockST[i-1][j+d-l][n]] ? iblockST[i-1][j-l][n] : iblockST[i-1][j+d-l][n];
        }
    } return mx;
}
inline void ibuildBigST(){
    for(int i=0;i<nblock;++i)ibigST[0][i]=i;
    for(int i=1,d=1;d<nblock;++i,d<<=1){
        for(int j=0;j+(d<<1)-1<nblock;++j){
            ibigST[i][j] = b[ibigST[i-1][j]] > b[ibigST[i-1][j+d]] ? ibigST[i-1][j] : ibigST[i-1][j+d];
        }
    }
}
void init(int N,ull C[]){
    a=C; n=N; blockSize=ceil(log(n)/log(2)/2), nblock=ceil((double)n/blockSize);
    jizz(); doLog();
    if(n>1000000){
        for(int i=0;i<nblock;++i)b[i]=buildBlockST(i,i*blockSize,min((i+1)*blockSize-1,n-1));
        buildBigST();
    }
    else{
        for(int i=0;i<nblock;++i)b[i]=ibuildBlockST(i,i*blockSize,min((i+1)*blockSize-1,n-1));
        ibuildBigST();
    }
}

inline ull queryBlock(int n,int l,int r){
    int d=r-l+1;
    int lv=lg[d],nblockSize=n*blockSize;
    return max(blockST[lv][l-nblockSize][n],blockST[lv][r-(1<<lv)+1-nblockSize][n]);
}
inline ull queryBig(int l,int r){
    if(r<l)return 0;
    int d=r-l+1;
    int lv=lg[d];
    return max(bigST[lv][l],bigST[lv][r-(1<<lv)+1]);
}
inline ull iqueryBlock(int n,int l,int r){
    int d=r-l+1;
    int lv=lg[d],nblockSize=n*blockSize;
    return max(a[iblockST[lv][l-nblockSize][n]],a[iblockST[lv][r-(1<<lv)+1-nblockSize][n]]);
}
inline ull iqueryBig(int l,int r){
    if(r<l)return 0;
    int d=r-l+1;
    int lv=lg[d];
    return max(b[ibigST[lv][l]],b[ibigST[lv][r-(1<<lv)+1]]);
}
ull RMQ(int l,int r){
    if(r-l==1)return a[l]; --r;
    int lblock=l/blockSize;
    int rblock=r/blockSize;
    PDE4(l,r,lblock,rblock);
    if(n>1000000){
        if(lblock==rblock){
            return queryBlock(lblock,l,r);
        }
        else{
            return max(queryBlock(lblock,l,(lblock+1)*blockSize-1)
            ,max(queryBig(lblock+1,rblock-1)
            ,queryBlock(rblock,rblock*blockSize,r)));
        }
    }
    else{
        if(lblock==rblock){
            return iqueryBlock(lblock,l,r);
        }
        else{
            return max(iqueryBlock(lblock,l,(lblock+1)*blockSize-1)
            ,max(iqueryBig(lblock+1,rblock-1)
            ,iqueryBlock(rblock,rblock*blockSize,r)));
        }
    }
}


#ifdef WEAK
ull C[10000007];
int main(){
    int N;cin>>N;
    for(int i=0;i<N;++i)cin>>C[i];
    init(N,C);
    int M;cin>>M;
    for(int i=0;i<M;++i){
        int L,R;cin>>L>>R;
        cout<<RMQ(L,R)<<endl;
    }
}
#endif
