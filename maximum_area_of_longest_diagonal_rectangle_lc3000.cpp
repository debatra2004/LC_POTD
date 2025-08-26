struct compare{
    bool operator() (const vector<int>& a, const vector<int>& b) const{
        long long da=1LL*a[0]*a[0]+1LL*a[1]*a[1];
        long long db=1LL*b[0]*b[0]+1LL*b[1]*b[1];
        if(da!=db){
            return da<db;
        }
        long long areaA = 1LL * a[0] * a[1];
        long long areaB = 1LL * b[0] * b[1];
        return areaA < areaB; 
    }
};
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dims) {
        sort(dims.begin(),dims.end(),compare());
        int n=dims.size();
        return dims[n-1][0]*dims[n-1][1];
    }
};