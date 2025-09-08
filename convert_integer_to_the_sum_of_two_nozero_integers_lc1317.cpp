class Solution {
public:
    bool f(int n){
        while(n>0){
            if(n%10==0) return false;
            n/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            int j=n-i;
            if(f(i) && f(j)) return {i,j};
        }
        return {};
    }
};