class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b){
                 if (a[0] == b[0]) return a[1] > b[1]; // x asc, y desc
                 return a[0] < b[0];
             });

        int ans = 0, n = points.size();
        for (int i = 0; i < n; ++i) {
            int maxY = INT_MIN;  // critical: below any possible y
            for (int j = i + 1; j < n; ++j) {
                if (points[j][1] <= points[i][1] && points[j][1] > maxY) {
                    ++ans;
                    maxY = points[j][1];
                    if (maxY == points[i][1]) break; // optional micro-opt
                }
            }
        }
        return ans;
    }
};
