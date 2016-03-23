#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define db double
struct val{
    ull v,s;
    db lv,ls;
    val(){
        v=s=0;
        lv=ls=0;
    }
    void update(){
        lv=log((db)v);
        ls=log((db)s);
        return;
    }
};
const ull MOD = 1e9+7;
/*val operator + (const val &a,const val &b){
    val t;
    t.s=a.s*b.s%MOD;
    t.ls=a.ls+b.ls;
    bool which; //ans=max(lc->ans,lc->sum+rc->ans);
    if(abs((a.lv) - (a.ls+a.lv+b.lv))<1e-9){
        if(a.v > a.s*b.v){
            which = 0;
        }
        else{
            which = 1;
        }
    }
    else{
        if(a.lv > a.ls+b.lv){
            which = 0;
        }
        else{
            which =1;
        }
    }
    if(which==0){
        t.v = a.v*b.v;
        t.lv= a.lv+b.lv;
    }
    else{
        t.v = a.s*b.v%MOD;
        t.lv= a.ls+b.lv;
    }
    return t;
}*/
#define mid (l+r)/2
struct node{
    val v;
    node *l,*r;
    node(){
        l = r = NULL;
    }
};

vector<ull> x,y;

inline ull rit(){
    ull t=0,k=1;char c;
    do{
        c=getchar();
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
}

void pull(node *now){
    now->v.s = now->l->v.s * now->r->v.s % MOD;
    now->v.ls= now->l->v.ls* now->r->v.ls;
    if(now->l->v.lv > now->l->v.ls+now->r->v.lv){  ///1e-9
        now->v.lv = now->l->v.lv;
        now->v.v  = now->l->v.v ;
    }
    else{
        now->v.lv = now->l->v.ls+now->r->v.lv;
        now->v.v  = now->l->v.s *now->r->v.v%MOD;
    }
}

void build(node *now,int l,int r){
    if(l==r){
        now->v.v = (x[l]*y[l])%MOD;
        now->v.s = y[l];
        now->v.update();
        return;
    }
    now->l = new node();
    now->r = new node();
    build(now->l,l,mid);
    build(now->r,mid+1,r);
    pull(now);
}

void update(node *now,int l,int r,int pos,ull val,int type){
    if(l==r){
        assert(l==pos);
        if(type==1){
            now->v.s = val;
            now->v.update();
        }
        else{
            now->v.v = val;
            now->v.update();
            return ;
        }
    }       cout<<"jizz";
    if(pos>mid){
        update(now->r,mid+1,r,pos,val,type);
    }
    if(pos<=mid){
        update(now->l,l,mid,pos,val,type);
    }
    pull(now);
}

void dlt(node *now){
    if(now->l)dlt(now->l);
    if(now->r)dlt(now->r);
    delete now;
}

int main(){
    int t=rit();
    while(t--){//cout<<"jizz"<<endl;
        node *root;
        int n=rit();
        x.clear();y.clear();
        x.resize(n);y.resize(n);
        for(int i=0;i<n;i++){
            x[i]=rit();
        }
        for(int j=0;j<n;j++){
            y[j]=rit();
        }
        root = new node();
        build(root,0,n-1);
        printf("%llu\n",root->v.v);
        int m=rit();
        for(int i=0;i<m;i++){
            int k=rit(),p=rit();ull v=rit();
            update(root,0,n-1,p-1,v,k);
            printf("%llu\n",root->v.v);
        }
        dlt(root);
    }

}
