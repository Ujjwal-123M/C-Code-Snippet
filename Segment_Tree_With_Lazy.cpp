#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N 200005
ll arr[N]; // 1 based indexing me array me insert karni hai
ll lazy[4*N];
ll seg[4*N];
void buildTree(int pos,int l,int r){
    if(l==r) {
        seg[pos] = arr[l];
        return;
    }    
    ll mid=(l+r)/2;
    buildTree(2*pos, l, mid);
    buildTree(2*pos+1, mid+1, r);
    seg[pos] = seg[2*pos]+ seg[2*pos+1];
}
void update(int l,int r,int pos,int ql,int qr,int val){
      if(lazy[pos]!=0){
        int dx=lazy[pos];
        lazy[pos]=0;
        seg[pos]+=dx*(r-l+1);
        if(l!=r)
        lazy[2*pos]+=dx,lazy[2*pos+1]+=dx;
    }
     
    if(l>ql || r<qr) return;
    if(l>=ql && r<=qr){
      int dx=(r-l+1)*val;
      seg[pos]+=dx;
      if(l!=r) 
      lazy[2*pos]+=val,lazy[2*pos+1]+=val;
      return;
    }
    ll mid=(l+r)/2;

    update(l,mid,2*pos,ql,qr,val);
    update(mid+1,r,2*pos+1,ql,qr,val);
    seg[pos] = min(seg[2*pos] , seg[2*pos+1]);
}
ll getsum(int l,int r,int ql,int qr,int pos){
    if(lazy[pos]!=0){
        int dx=lazy[pos];
        lazy[pos]=0;
        seg[pos]+=dx*(r-l+1);
        if(l!=r)
        lazy[2*pos]+=dx,lazy[2*pos+1]+=dx;
    }

    if(ql>r || qr<l) return 0;
    if(ql<=l && qr>=r) return seg[pos];
    ll mid=(l+r)/2;
    return getsum(l,mid,ql,qr,2*pos) + getsum(mid+1,r,ql,qr,2*pos+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
      memset(lazy,0,sizeof(lazy));

    return 0;
}
