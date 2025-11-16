class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        long long cnt=0,ans=0;
        int MOD = 1e9+7;
        for(int i=0;i<n;i++){
            if(s[i]=='1') {
                cnt++;
            }
            else{
                ans = (ans + ((cnt * (cnt+1)) % MOD)/2) % MOD;
                cnt=0;
            }
        }
        ans = (ans + ((cnt * (cnt+1)) % MOD)/2) % MOD;
        return (int)ans;
    }
};