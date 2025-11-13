class Solution {
public:
    int minOperations(vector<int>& arr) {
        int n = arr.size();
        int res = INT_MAX;

        int cnt = 0;
        int total_gcd = arr[0];
        for (int i = 1; i < n; i++)
            total_gcd = gcd(total_gcd, arr[i]);
        if (total_gcd != 1)
            return -1;

        
        for (int i = 0; i < n; i++) {
            
            int g = arr[i];
            //if (g == 1) return 1;  
            for (int j = i + 1; j < n; j++) {
                g = gcd(g, arr[j]);
                if (g == 1) {
                    res = min(res, j - i + 1);
                    break;  
                }
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]==1) cnt++;
        }
        cout<<res<<endl;
        if(res==INT_MAX) return -1;
        return res + n - 2 - cnt;
    }
};