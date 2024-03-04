#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N 200005
ll arr[N]; // 1 based indexing me array me insert karni hai
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
void update(int l,int r,int pos,int idx,int val){
    if(idx<l || idx>r) return;
    if(l==r){
        seg[pos] = val;
        return;
    }
    ll mid=(l+r)/2;
    if(mid<=idx)
    update(l,mid,2*pos,idx,val);
    else
    update(mid+1,r,2*pos+1,idx,val);
    seg[pos] = min(seg[2*pos] , seg[2*pos+1]);
}
ll getsum(int l,int r,int ql,int qr,int pos){
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
      int n,q;
      cin>>n>>q;
     for(int i=1;i<=n;i++) cin>>arr[i];
      buildTree(1,1,n);
      while(q--){
        int a,b;
        cin>>a>>b;
        cout<<getsum(1,n,a,b,1)<<"\n";
      }

    return 0;
}