class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26);
        int maxvwl=0;
        int maxcons=0;
        for(char c:s){
            freq[c-'a']++;
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') maxvwl=max(maxvwl,freq[c-'a']);
            else maxcons=max(maxcons,freq[c-'a']);
        }
        return maxvwl+maxcons;
    }
};