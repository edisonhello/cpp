#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define sf(x) scanf(x)
#define pf(x) printf(x)
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
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
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;cin>>n;

    // cout<<"I ";
    for(int i=1;i<=n;i++){
        if(i-1){
            cout<<"that ";
        }
        if(i&1){
            cout<<"I hate ";
        }
        else{
            cout<<"I love ";
        }
    }
    cout<<"it\n";
}
