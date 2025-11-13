class Solution {
public:
    int maxOperations(string s) {
        int n = s.size(),cnt=0,ans=0;
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                temp.push_back(i);
                cnt++;
            }
        }
        if(cnt==0) return 0;
        if(cnt==1 && s[n-1]=='1') return 0;
        else if(cnt==1 && s[n-1]!='1') return 1;
        for(int i=0;i<temp.size()-1;i++){
            if(temp[i+1] - temp[i]>1){
                ans+=i+1;
            }
            else {
                //cnt++;
                while(temp[i+1] - temp[i]==1) continue;
            }
            //ans+=cnt;
        }
        if(s[n-1]!='1') return ans+cnt;
        return ans;
    }
};