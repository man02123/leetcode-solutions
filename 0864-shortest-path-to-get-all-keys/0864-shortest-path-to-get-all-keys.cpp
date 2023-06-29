// class Solution {
// public:vector<int> dx,dy;
//     int n,m;
//     int ans;
//     unordered_map<char,int> mp;
//     int shortestPathAllKeys(vector<string>& g) {
//         m =g.size();
//         ans = 0;
//         n = g[0].size();
//         dx = {1,-1,0,0};
//         dy = {0,0,-1,1};
        
//         vector<vector<int>> vis(m,vector<int>(n,0));
        
//         for(int i  =0;i<m;i++)
//         {
//            for(int j =0;j<n;j++)
//            {
//                if(g[i][j] =='@')
//                {
//                   bfs(g,vis,i,j);
//                    break;
//                }
                   
//            }
//         }
       
//         for(int i  =0;i<m;i++)
//         {
//            for(int j =0;j<n;j++)
//            {
//                if(islower(g[i][j]))
//                {
//                  if(mp.find(g[i][j])==mp.end())
//                      return -1;
//                }
                   
//            }
//         }
        
//         return ans;
        
        
//     }
//     void bfs(vector<string> &g ,vector<vector<int>>&vis , int x,int y)
//     {
        
//         queue<pair<pair<int,int>,int>> q;
//         q.push({{x,y},0});
//         vis[x][y] = 1;
        
//         while(q.size()>0)
//         {
//             int i = q.front().first.first;
//             int j = q.front().first.second;
//             int dist = q.front().second;
//             q.pop();
            
//             for(int k = 0;k<4;k++)
//             {
//                 int nx= i+dx[k];
//                 int ny = j+dy[k];
                
//                 if(isvalid(nx,ny)  && vis[nx][ny]==0 && g[nx][ny] !='#')
//                 {
//                     if(isupper(g[nx][ny])  && mp.find(tolower(g[nx][ny])==mp.end()))
//                         continue;
//                     else if(islower(g[nx][ny]))
//                     {
//                         mp[g[nx][ny]]=1;
//                         vis[nx][ny]=1;
//                         q.push({{nx,ny},dist+1});
//                         ans = max(ans,dist+1);
//                     }
//                     else if(isupper(g[nx][ny])  && mp.find(tolower(g[nx][ny])!=mp.end()))
//                     {
//                         vis[nx][ny]=1;
//                         q.push({{nx,ny},dist+1});
//                     }
//                     else
//                     {
//                          vis[nx][ny]=1;
//                         q.push({{nx,ny},dist+1});
//                     }
//                 }
                
//             }
//         }
        
//     }
//     bool isvalid(int x,int y)
//     {
//         if(x>=0 && y>=0 && x<m && y<m)
//             return true;
//         return false;
//     }
// };

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_map<char, int> key_bit;
        int bit_start = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (islower(grid[i][j]))
                    key_bit[grid[i][j]] = bit_start++;
            }
        }

        int form_end = (1 << bit_start) - 1;
        int form_size = (1 << bit_start);

        vector<vector<vector<bool>>> memo(m, vector<vector<bool>>(n, vector<bool>(form_size, false)));

        vector<int> start;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@')
                    start = { i, j, 0 }; // 0 denoting no key state
            }
        }

        queue<vector<int>> q;
        q.push(start);
        int Ashish = 0; // Step counter

        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                int row = q.front()[0];
                int col = q.front()[1];
                int form = q.front()[2];
                q.pop();

                // Check if out of bounds
                if (row < 0 || row >= m || col < 0 || col >= n)
                    continue;

                // Check if position is blocked
                if (grid[row][col] == '#')
                    continue;

                // Check if the key is required but not collected
                if (isupper(grid[row][col])) {
                    if ((form & (1 << key_bit[tolower(grid[row][col])])) == 0)
                        continue;
                }

                // If the position contains a key, collect it
                if (islower(grid[row][col])) {
                    form = form | (1 << key_bit[grid[row][col]]);
                }

                // If all keys are collected, return the step count
                if (form == form_end)
                    return Ashish;

                // If the position and form combination has been visited, continue to the next iteration
                if (memo[row][col][form])
                    continue;
                memo[row][col][form] = true;

                // Add adjacent positions to the queue
                q.push({ row + 1, col, form });
                q.push({ row - 1, col, form });
                q.push({ row, col + 1, form });
                q.push({ row, col - 1, form });
            }
            Ashish++; // Increment step count
        }
        return -1;
    }
};
