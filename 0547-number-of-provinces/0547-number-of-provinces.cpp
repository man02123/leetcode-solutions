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
    int findCircleNum(vector<vector<int>>& gr){
        Disjoint ds(gr.size());
        
        for(int i =0;i<gr.size();i++)
        {
            for(int j = 0;j<gr.size();j++)
            {
                if(gr[i][j]  == 1)
                    ds.UnionBySize(i,j);
            }
        }
        int cnt = 0;
        for(int i=0;i<gr.size();i++)
        {
          if(ds.findparent(i) ==i)cnt++;
            
        }
        return cnt;
        
        
    }
};