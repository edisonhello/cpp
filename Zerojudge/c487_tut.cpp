#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mid ((l+r)>>1)

struct Q{
    int l,i;
};
vector<Q> qs[100007];

int a[100007];
ll ans[100007];
struct node{
    node *l,*r;
    ll val,tag;
    node():l(0),r(0),val(0),tag(0){}
} *root;

void push(node *now,int l,int r){
    if(!now)return;
    if(!now->l)return;
    if(!now->tag)return;
    now->l->val+=now->tag*(mid-l+1);
    now->l->tag+=now->tag;
    now->r->val+=now->tag*(r-mid);
    now->r->tag+=now->tag;
    now->tag=0;
}
void pull(node *now){
    if(!now)return;
    if(!now->l)return;
    now->val=now->l->val+now->r->val;
}

void build(node *now,int l,int r){
    if(l==r){return;}
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
}
void modify(node *now,int l,int r,int ml,int mr,ll v){
    if(l>mr || ml>r)return;
    if(ml<=l&&r<=mr){
        now->tag+=v;
        now->val+=v*(r-l+1);
        return;
    }
    push(now,l,r);
    modify(now->l,l,mid,ml,mr,v);
    modify(now->r,mid+1,r,ml,mr,v);
    pull(now);
} 
ll query(node *now,int l,int r,int ql,int qr){
    if(r<ql || qr<l)return 0;
    if(ql<=l&&r<=qr)return now->val;
    push(now,l,r);
    return query(now->l,l,mid,ql,qr)+query(now->r,mid+1,r,ql,qr);
}

int main(){
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=q;++i){
        int l,r; cin>>l>>r;
        qs[r].push_back({l,i});
    }
    build(root=new node(),1,n);
    map<int,int,greater<int>> __set1,__set2;
    auto *it=&__set1,*prv=&__set2;
    for(int i=1;i<=n;++i){
        // cout<<"process of i: "<<i<<endl;
        it->clear();
        for(auto pi:(*prv)){
            int newgcd=__gcd(a[i],pi.first);
            auto &p=(*it)[newgcd];
            if(p==0)p=pi.second;
            else p=min(p,pi.second);
            // cout<<"gcd: "<<newgcd<<" p: "<<p<<endl;
        }
        auto &p=(*it)[a[i]];
        if(p==0)p=i;
        else p=min(p,i);
        int prvr=i;
        if(a[i])for(auto i:(*it)){
            // cout<<"segments: from "<<i.second<<" to "<<prvr<<" is "<<i.first<<endl;
            modify(root,1,n,i.second,prvr,i.first);
            prvr=i.second-1;
        }
        for(auto q:qs[i]){
            ans[q.i]=query(root,1,n,q.l,i);
        }
        swap(it,prv);
    }
    for(int i=1;i<=q;++i)cout<<ans[i]<<endl;
}
