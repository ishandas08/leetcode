
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long cnt[31] = {0};
        long long mod = 1e9 + 7;

        for (int x : nums) {
            for (int i = 0; i < 31; i++) {
                if ((x >> i) & 1) {
                    cnt[i]++;
                }
            }
        }

        long long ans = 0;

        while (k--) {
            long long x = 0;

            for (int i = 0; i < 31; i++) {
                if (cnt[i] > 0) {
                    x |= (1LL << i);
                    cnt[i]--;
                }
            }

            ans = (ans + x * x) % mod;
        }

        return ans;
    }
};
