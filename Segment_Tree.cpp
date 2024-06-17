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
    if(mid>=idx)
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


// new template 
#include <vector>
using namespace std;

class SegmentTree {
public:
    SegmentTree(const vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(nums, 0, n - 1, 0);
    }

    int query(int l, int r) {
        return queryUtil(0, n - 1, l, r, 0);
    }

    void updateRange(int l, int r, int val) {
        updateRangeUtil(0, n - 1, l, r, val, 0);
    }

private:
    int n;
    vector<int> tree, lazy;

    void build(const vector<int>& nums, int start, int end, int node) {
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = (start + end) / 2;
            build(nums, start, mid, 2 * node + 1);
            build(nums, mid + 1, end, 2 * node + 2);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void updateRangeUtil(int start, int end, int l, int r, int val, int node) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > end || start > r || end < l) return;

        if (start >= l && end <= r) {
            tree[node] += (end - start + 1) * val;
            if (start != end) {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }
            return;
        }

        int mid = (start + end) / 2;
        updateRangeUtil(start, mid, l, r, val, 2 * node + 1);
        updateRangeUtil(mid + 1, end, l, r, val, 2 * node + 2);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int queryUtil(int start, int end, int l, int r, int node) {
        if (start > end || start > r || end < l) return 0;

        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start >= l && end <= r) return tree[node];

        int mid = (start + end) / 2;
        return queryUtil(start, mid, l, r, 2 * node + 1) + queryUtil(mid + 1, end, l, r, 2 * node + 2);
    }
};

