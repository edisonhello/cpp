#include<bits/stdc++.h>
using namespace std;

#ifndef WEAK
#include"lib1885.h"
#else

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
int coins[6],pos[6],qtime;
int Init(){ return 1; }
void orderCoins(){
    cout<<"orderCoins: "<<endl;
    for(int i=0;i<6;++i)cin>>coins[i],pos[coins[i]]=i;
}
void answer(int *a){
    cout<<"answer: ";
    for(int i=0;i<6;++i)cout<<a[i]<<" "; cout<<endl;
    cout<<"Query "<<qtime<<" times"<<endl;
}
int getHeaviest(int i,int j,int k){
    ++qtime;
    if(pos[i]>pos[j] && pos[i]>pos[k])return i;
    if(pos[j]>pos[i] && pos[j]>pos[k])return j;
    if(pos[k]>pos[i] && pos[k]>pos[j])return k;
}
int getLightest(int i,int j,int k){
    ++qtime;
    if(pos[i]<pos[j] && pos[i]<pos[k])return i;
    if(pos[j]<pos[i] && pos[j]<pos[k])return j;
    if(pos[k]<pos[i] && pos[k]<pos[j])return k;
}
int getMedian(int i,int j,int k){
    ++qtime;
    if((pos[i]>pos[j])^(pos[i]>pos[k]))return i;
    if((pos[j]>pos[i])^(pos[j]>pos[k]))return j;
    if((pos[k]>pos[i])^(pos[k]>pos[j]))return k;
}
int getNextLightest(int i,int j,int k,int l){
    ++qtime;
    pair<int,int> pp[4]={{pos[i],i},{pos[j],j},{pos[k],k},{pos[l],l}};
    sort(pp,pp+4);
    if(pp[3].second==l)return pp[0].second;
    for(int i=0;i<3;++i)if(pp[i].second==l)return pp[i+1].second;
}
#pragma GCC diagnostic pop
#endif


void go(vector<vector<int>> &now){
    auto pnow=[&](){
        cout<<"now: "<<endl;
        for(auto &v:now){
            for(int i:v)cout<<i<<" ";
            cout<<endl;
        }
    };
    int pos[8];
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
    auto _sim_getHeaviest=[&](const int i,const int j,const int k){
        if(pos[i]>pos[j] && pos[i]>pos[k])return i;
        if(pos[j]>pos[i] && pos[j]>pos[k])return j;
        if(pos[k]>pos[i] && pos[k]>pos[j])return k;
    };
    auto _sim_getLightest=[&](const int i,const int j,const int k){
        if(pos[i]<pos[j] && pos[i]<pos[k])return i;
        if(pos[j]<pos[i] && pos[j]<pos[k])return j;
        if(pos[k]<pos[i] && pos[k]<pos[j])return k;
    };
    auto _sim_getMedian=[&](const int i,const int j,const int k){
        if((pos[i]>pos[j])^(pos[i]>pos[k]))return i;
        if((pos[j]>pos[i])^(pos[j]>pos[k]))return j;
        if((pos[k]>pos[i])^(pos[k]>pos[j]))return k;
    };
    auto _sim_getNextLightest=[&](const int i,const int j,const int k,const int l){
        pair<int,int> pp[4]={{pos[i],i},{pos[j],j},{pos[k],k},{pos[l],l}};
        sort(pp,pp+4);
        if(pp[3].second==l)return pp[0].second;
        for(int i=0;i<3;++i)if(pp[i].second==l)return pp[i+1].second;
    };
#pragma GCC diagnostic pop

    while(now.size()>1u){
        for(int i=1;i<=4;++i){
            for(int j=i+1;j<=5;++j){
                for(int k=j+1;k<=6;++k){
                    int r1=0,r2=0,r3=0,lim=(now.size()+2)/3;
                    for(auto &v:now){
                        for(int i=0;i<6;++i)pos[v[i]]=i;
                        int r=_sim_getHeaviest(i,j,k);
                        if(r==i)++r1;
                        if(r==j)++r2;
                        if(r==k)++r3;
                    }
                    cout<<"rrrl: "<<r1<<" "<<r2<<" "<<r3<<" "<<lim<<endl;
                    if(r1<=lim && r2<=lim && r3<=lim){
                        int rt=getHeaviest(i,j,k);
                        vector<vector<int>> tmp;
                        for(auto &v:now){
                            for(int i=0;i<6;++i)pos[v[i]]=i;
                            if(_sim_getHeaviest(i,j,k)==rt)tmp.push_back(v);
                        }
                        now.swap(tmp);
                        pnow();
                        if(now.size()==1u)break;
                    }

                    r1=r2=r3=0; lim=(now.size()+2)/3;
                    for(auto &v:now){
                        for(int i=0;i<6;++i)pos[v[i]]=i;
                        int r=_sim_getLightest(i,j,k);
                        if(r==i)++r1;
                        if(r==j)++r2;
                        if(r==k)++r3;
                    }
                    cout<<"rrrl: "<<r1<<" "<<r2<<" "<<r3<<" "<<lim<<endl;
                    if(r1<=lim && r2<=lim && r3<=lim){
                        int rt=getLightest(i,j,k);
                        vector<vector<int>> tmp;
                        for(auto &v:now){
                            for(int i=0;i<6;++i)pos[v[i]]=i;
                            if(_sim_getLightest(i,j,k)==rt)tmp.push_back(v);
                        }
                        now.swap(tmp);
                        pnow();
                        if(now.size()==1u)break;
                    }

                    r1=r2=r3=0; lim=(now.size()+2)/3;
                    for(auto &v:now){
                        for(int i=0;i<6;++i)pos[v[i]]=i;
                        int r=_sim_getMedian(i,j,k);
                        if(r==i)++r1;
                        if(r==j)++r2;
                        if(r==k)++r3;
                    }
                    cout<<"rrrl: "<<r1<<" "<<r2<<" "<<r3<<" "<<lim<<endl;
                    if(r1<=lim && r2<=lim && r3<=lim){
                        int rt=getMedian(i,j,k);
                        vector<vector<int>> tmp;
                        for(auto &v:now){
                            for(int i=0;i<6;++i)pos[v[i]]=i;
                            if(_sim_getMedian(i,j,k)==rt)tmp.push_back(v);
                        }
                        now.swap(tmp);
                        pnow();
                        if(now.size()==1u)break;
                    }

                    for(int l=1;l<=6;++l){
                        if(l==i || l==j || l==k)continue;
                        r1=r2=r3=0; lim=(now.size()+2)/3;
                        for(auto &v:now){
                            for(int i=0;i<6;++i)pos[v[i]]=i;
                            int r=_sim_getNextLightest(i,j,k,l);
                            if(r==i)++r1;
                            if(r==j)++r2;
                            if(r==k)++r3;
                        }
                    cout<<"rrrl: "<<r1<<" "<<r2<<" "<<r3<<" "<<lim<<endl;
                        if(r1<=lim && r2<=lim && r3<=lim){
                            int rt=getNextLightest(i,j,k,l);
                            vector<vector<int>> tmp;
                            for(auto &v:now){
                                for(int i=0;i<6;++i)pos[v[i]]=i;
                                if(_sim_getNextLightest(i,j,k,l)==rt)tmp.push_back(v);
                            }
                            now.swap(tmp);
                            pnow();
                            if(now.size()==1u)break;
                        }
                    }
                    if(now.size()==1u)break;
                }
                if(now.size()==1u)break;
            }
            if(now.size()==1u)break;
        }
    }
}

int main(){
    int t=Init(); while(t--){
        orderCoins();
        int a[6]={1,2,3,4,5,6};
        vector<vector<int>> now;
        vector<int> tmp(a,a+6);
        do{
            now.push_back(tmp);
        }while(next_permutation(tmp.begin(),tmp.end()));
        go(now);
        for(int i=0;i<6;++i)a[i]=now[0][i];
        answer(a);
    }
}
// 4 2 5 3 6 1 
