#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define pii pair<int,int>
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue

inline int rit(){
    int t=0,k=1;
    char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
}

int main(){
    ll l1,r1,l2,r2,k;
    cin>>l1>>r1>>l2>>r2>>k;
    ll l=max(l1,l2);
    ll r=min(r1,r2);
    ll ans=r-l+1;
    if(l<=k && k<=r)ans--;
    cout<<(ans<0?0:ans)<<endl;
    // cout<<0<<endl;
}