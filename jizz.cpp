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

ll tt,k;
inline ll rit(){
    tt=0,k=1;
    char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        tt=tt*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return tt*k;
};


int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    bitset<2000> b;
    cout<<b<<endl;
}
