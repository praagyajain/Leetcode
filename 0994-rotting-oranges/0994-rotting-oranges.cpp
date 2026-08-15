class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> copy(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                copy[i][j] = grid[i][j];
            }
        }
        queue < pair<pair<int, int>, int >> q;
        int time = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (copy[i][j] == 2)
                    q.push({{i, j}, time});
            }
        }
        while (!q.empty()) {
            int a = q.front().first.first;
            int b = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time,t);
            int delrow[4] = {-1, 0, 1, 0};
            int delcol[4] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int r = a + delrow[i];
                int c = b + delcol[i];
                if (r>=0 && r<n && c>=0 && c<m && grid[r][c] == 1 && copy[r][c]!=2){
                    q.push({{r,c},t+1});
                    copy[r][c] = 2;
                }
            }
        }
        bool flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (copy[i][j] == 1)
                flag = true;
            }
        }
        if(flag) return -1;
        return time;
    }
};