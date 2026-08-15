class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor == color) return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> copy(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                copy[i][j] = image[i][j];
            }
        }
        copy[sr][sc] = color;
        while(!q.empty()){
                    int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

            int r = q.front().first;
            int c = q.front().second;
            q.pop();
           for(int i=0;i<4;i++){
               int nrow = r+delrow[i];
               int ncol = c+delcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && copy[nrow][ncol]==image[sr][sc]){
                   q.push({nrow,ncol});
                   copy[nrow][ncol] = color;
               }
           }
        }
        return copy;
    }
};