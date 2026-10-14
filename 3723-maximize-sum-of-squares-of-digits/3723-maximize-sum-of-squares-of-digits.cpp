class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";

        for (int i = 0; i < num; i++) {
            int d = min(9, sum);
            ans += char('0' + d);
            sum -= d;
        }
        if (sum > 0)
            return "";
        return ans;
    }
};