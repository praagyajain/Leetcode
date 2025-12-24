class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin(),apple.end(),0);
        int cnt=0,ans=0;
        sort(capacity.begin(),capacity.end(),greater<int>());
        for(int i=0;i<capacity.size();i++){
            if(ans>=sum) return cnt;
            else{
                ans+=capacity[i];
                cnt++;
            }
        }
        if(ans>=sum) return capacity.size();
        return 0;
    }
};