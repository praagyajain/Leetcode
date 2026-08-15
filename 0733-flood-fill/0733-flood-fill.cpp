class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor == color) return image;
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> copy(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                copy[i][j] = image[i][j];
            }
        }
        copy[sr][sc] = color;

        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){ 
           int a =  q.front().first;
           int b =  q.front().second;
           q.pop();
           int delrow[4] = {-1,0,1,0};
           int delcol[4] = {0,1,0,-1};
           for(int i=0;i<4;i++){
            int r = a + delrow[i];
            int c = b + delcol[i];
            if(r<n && r>=0 && c<m && c>=0 && copy[r][c] == image[a][b]){
                q.push({r,c});
                copy[r][c] = color;
            }
           }
        }
        return copy;
    }
};