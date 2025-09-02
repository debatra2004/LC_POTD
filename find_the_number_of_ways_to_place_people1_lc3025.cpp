class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const vector<int>& a,const vector<int>& b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        int cnt=0;
        int n=points.size();
        for(int i=0;i<n-1;i++){
            int x=points[i][0];
            int y=points[i][1];
            int lower=-1;
            for(int j=i+1;j<n;j++){
                if(lower<points[j][1] && points[j][1]<=y){
                    cnt++;
                    lower=points[j][1];
                }
                if(lower==y) break;
            }
        }
        return cnt;
    }
};