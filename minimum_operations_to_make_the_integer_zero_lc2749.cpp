class Solution {
public:
    int f(long long n) {
        int cnt = 0;
        while (n) {
            n &= (n - 1);
            cnt++;
        }
        return cnt;
    }

    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k < 61; k++) {
            long long x = 1LL * num1 - 1LL * k * num2;  
            if (x < k) continue;                       
            if (f(x) <= k) return k;
        }
        return -1;
    }
};
