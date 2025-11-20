class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort by end increasing, and if tie, start decreasing
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        int a = -1e9, b = -1e9;  
        int ans = 0;

        for (auto &it : intervals) {
            int start = it[0], end = it[1];

            if (start > b) {
                ans += 2;
                a = end - 1;
                b = end;
            }
            else if (start > a) {
                ans += 1;
                a = b;
                b = end;
            }
            else {
            }
        }

        return ans;
    }
};
