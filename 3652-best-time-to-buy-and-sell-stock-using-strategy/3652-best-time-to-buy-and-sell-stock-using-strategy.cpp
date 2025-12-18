class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long n = prices.size(),maxi = LLONG_MIN;
        vector<long long> prefixsum(n,0);
        vector<long long> prefixsum1(n,0);
        prefixsum[0] = strategy[0]*prices[0];
        prefixsum1[0] = prices[0];
        for(int i=1;i<n;i++){
            prefixsum[i] = prefixsum[i-1] + strategy[i]*prices[i];
        }
        for(int i=1;i<n;i++){
            prefixsum1[i] = prefixsum1[i-1] + prices[i];
        }
        for(int i=0;i<n-k+1;i++){
            long long ans=0;
            ans+=prefixsum1[i+k-1] - prefixsum1[i+k/2-1];
            cout<<ans<<endl;
            if(i>0)ans+=prefixsum[n-1] - prefixsum[i+k-1]  + prefixsum[i-1];
            else ans+=prefixsum[n-1] - prefixsum[i+k-1];
            maxi = max(maxi,ans);
            cout<<ans<<endl;
        }
        return max(maxi,prefixsum[n-1]);
    }
};