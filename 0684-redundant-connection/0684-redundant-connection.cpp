class Disjoint{

vector<int> rank,parent,size;
public:
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
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        Disjoint ds(e.size()+1);
        
        for(auto it:e)
        {
            
            int parx = ds.findparent(it[0]);
            int pary = ds.findparent(it[1]);
            
            if(parx==pary)
                return {it[0],it[1]};
            
            ds.UnionByRank(it[0],it[1]);
            
            
  
        }
//         for(auto it:e)
//         {
//             int parx = ds.findparent(it[0]);
//             int pary = ds.findparent(it[1]);
            
//             if(parx==pary  && parx!=it[0] && pary!=it[1])
//                 return {parx,it[1]};
//         }
        return {};
    }
};