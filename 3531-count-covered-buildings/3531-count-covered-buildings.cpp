class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        unordered_map<int, vector<int>> rowMap;
        unordered_map<int, vector<int>> colMap;

        for (auto &b : buildings) {
            rowMap[b[0]].push_back(b[1]);
            colMap[b[1]].push_back(b[0]);
        }

        for (auto &r : rowMap) sort(r.second.begin(), r.second.end());
        for (auto &c : colMap) sort(c.second.begin(), c.second.end());

        int covered = 0;

        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            auto &row = rowMap[x];
            auto &col = colMap[y];


            int posRow = lower_bound(row.begin(), row.end(), y) - row.begin();
            bool left  = (posRow > 0);
            bool right = (posRow + 1 < row.size());


            int posCol = lower_bound(col.begin(), col.end(), x) - col.begin();
            bool up    = (posCol > 0);
            bool down  = (posCol + 1 < col.size());

            if (left && right && up && down)
                covered++;
        }

        return covered;
    }
};