#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
    vector<int>rank,parent,size;
    
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
          
    }
    int find(int u){
        if(u==parent[u]) return u;
        return parent[u]=find(parent[u]);  // Path Compression
    }
    void unionByRank(int a,int b){
        int pa=find(a),pb=find(b);
        if(pa==pb)return;
        if(rank[pa]<rank[pb]){
             parent[pa]=pb;
        }
        else if(rank[pa]>rank[pb]) parent[pb]=pa;
        else{
            parent[pb]=pa;
            rank[pa]++;
        }
    }
void unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    
    }
};