#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int> mp;
string rem[100005];
int deg[100005];
vector<int> G[100005];

int gid(string s){
    int &x=mp[s];
    if(x==0)x=mp.size(),rem[x]=s;
    return x;
}

int main(){
    int n,ks=0; while(cin>>n){
    for(int i=0;i<1234;++i)G[i].clear();
    mp.clear();
    memset(deg,0,sizeof(int)*1234);
    for(int i=1;i<=n;++i){
        string s; cin>>s;
        int id=gid(s);
    }
    int m; cin>>m; while(m--){
        string as,bs; cin>>as>>bs;
        int a=gid(as),b=gid(bs);
        G[a].push_back(b);
        ++deg[b];
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<=n;++i)if(deg[i]==0)pq.push(i);
    vector<int> ans;
    while(pq.size()){
        ans.push_back(pq.top());
        int np=pq.top();
        pq.pop();
        for(int i:G[np]){
            --deg[i];
            if(deg[i]==0)pq.push(i);
        }
    }
    cout<<"Case #"<<(++ks)<<": Dilbert should drink beverages in this order:";
    for(int i:ans){
        cout<<" "<<rem[i];
    }
    cout<<".\n"<<endl;
}}
