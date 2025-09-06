class Solution {
public:
    long long expSum4[18]={1};//precomputed array where expSum4[i] stores the sum of reductions for all numbers from 1 to 4^i - 1
    long long expSum(unsigned x){
        if(x==0) return 0;
        int logxbase4=(31-countl_zero(x))/2;
        int r=x-(1<<(2*logxbase4));//the remaining part of x after subtracting the largest power of 4
        return expSum4[logxbase4]+r*(logxbase4+1LL);//each of these r numbers needs at least logxbase4 + 1 operations to be reduced to zero
    }
    long long minOperations(vector<vector<int>>& queries) {
        for(int i=1;i<18;i++){
            expSum4[i]=expSum4[i-1]+3LL*i*(1LL<<(2*(i-1)))+1;//the term 3 * i * 4^(i-1) comes from the numbers in the range [4^(i-1), 4^i - 1]. There are 3 * 4^(i-1) such numbers
        }
        long long oprncnt=0;
        for(auto& q:queries){
            int l=q[0]-1;
            int r=q[1];
            oprncnt+=(expSum(r)-expSum(l)+1)/2;
        }
        return oprncnt;
    }
};