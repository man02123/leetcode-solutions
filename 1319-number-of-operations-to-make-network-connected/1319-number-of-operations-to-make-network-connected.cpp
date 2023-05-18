class Disjoint{
public:
vector<int> rank,parent,size;
  Disjoint(int n)
  {
    rank.resize(n+1,0);
    size.resize(n+1,0);
    parent.resize(n+1);
    for(int i =0;i<=n;i++)
    {
      parent[i] = i;

    }

  }
  int findparent(int node)
  {
    if(parent[node] == node)
      return node;
    else
      return parent[node] = findparent(parent[parent[node]]); //pathcompression
  }
  void UnionByRank(int u ,int v)
  {
    int ult_u = findparent(u);
    int ult_v = findparent(v);

    if(ult_u == ult_v)
      return ;
    if(rank[u] < rank[v])
    {
      parent[ult_u] = ult_v;
    }
    else if(rank[u] > rank[v])
    {
      parent[ult_v] = ult_u;
    }
    else
    {
      parent[ult_v] = ult_u;
      rank[ult_u]++;
    }

  }
  void UnionBySize(int u ,int v)
  {
    int ult_u = findparent(u);
    int ult_v = findparent(v);

    if(ult_u == ult_v)
      return ;
    if(size[ult_v] < size[ult_u])
    {
      parent[ult_v]  = ult_u;
      size[ult_u]+=size[ult_v];
    }
    else 
    {
      parent[ult_u]  = ult_v;
      size[ult_v]+=size[ult_u];

    }

  }

};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& conn) {
        Disjoint ds(n);
        int cntex = 0;
        
        
        for(auto it:conn)
        {
            int u=it[0];
            int v = it[1];
               if(ds.findparent(u) == ds.findparent(v) )
                   cntex++;
                else
                ds.UnionByRank(u,v);
                
        }
        int cnt = 0;
        
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i] == i)
                cnt++;
            
        }
        if(cntex>=cnt-1)
            return cnt-1;
        
        return -1;
    }
};