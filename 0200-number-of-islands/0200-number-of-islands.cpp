class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && vis[i][j]!=1){
                    cnt++;
                    vis[i][j] = 1;
                    q.push({i,j});
                    while(!q.empty()){
                        int delrow[4] = {-1,0,1,0};
                        int delcol[4] = {0,1,0,-1};
                        int a = q.front().first;
                        int b = q.front().second;
                        q.pop();
                        for(int i=0;i<4;i++){
                            int r = a + delrow[i];
                            int c = b + delcol[i];
                            if(r<n && r>=0 && c<m && c>=0 && grid[r][c] == '1' && vis[r][c]!=1){
                                vis[r][c] = 1;
                                q.push({r,c});
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};