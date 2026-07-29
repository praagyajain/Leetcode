class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> mpp;
        string a = "";
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        string ans = "";
        for(auto it: mpp){
            if(it.second%2!=0) {
                a=it.first;
            }
            for(int i=0;i<it.second/2;i++){
                ans+=it.first;
            }
        }
        string ans1 = ans;
        reverse(ans.begin(), ans.end());
        return ans1 +a+ ans;

    }
};