#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define X first
#define Y second
#define S(x) (int)(x).size()
#define rz(x) reserve(x)
#define PB(x) push_back(x)
#define pii pair<int,int>
#define vint vector<int>
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define SS stringstream
#define PQ priority_queue
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
// #define getchar getchar_unlocked
// #define putchar putchar_unlocked
#define PVC(x) for(auto ___:(x))cout<<___<<" ";cout<<endl;
#define PAR(x,n) for(int ___=0;___<(n);___++)cout<<x[___]<<" ";cout<<endl;

int _(string &a,string &b){
    if(b.length()>a.length())return 0;
    int f[10005]={0};
    f[0]=-1,f[1]=0;
    for(int i=1,j=1;i<(int)b.length();i++,j=i){
        while(b[i]!=b[f[j]]&&j)j=f[j];
        f[i+1]=f[j]+1;
    }
    int cnt=0;
    for(int i=0,j=0;i+j<(int)a.length();++j){
        if(a[i+j]==b[j]){if(j==(int)b.length()-1){
            ++cnt;i+=b.length()-f[j+1];j-=b.length()-f[j+1];
        }}
        else{
            i+=j-f[j];j-=j-f[j]+1;if(j<-1)j=-1;
        }
    }
    return cnt;
}
int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    int ts;cin>>ts;while(ts--){
        string s;cin>>s;int n;cin>>n;while(n--){
            string t;cin>>t;cout<<_(s,t)<<'\n';
        }
    }
}
