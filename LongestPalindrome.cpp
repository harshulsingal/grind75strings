class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(52,0);
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isupper(s[i])){
                count[s[i]-'A']++;
            }else{
                count[s[i]-'a'+26]++;
            }
        }
        int ans=0;
        int odd=0;
        int x=0;
        for(int i=0;i<52;i++){
            if(count[i]%2==0){
                ans+=count[i];
            }else{
                ans+=(count[i]-1);
                x=1;
            }
        }
        return ans+x;
    }
};
