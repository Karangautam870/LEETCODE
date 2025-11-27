class Solution {
public:
    using ll = long long;
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll ans = LLONG_MIN, sum = 0;
        
        vector<ll> pre(k, LLONG_MAX / 2);
        pre[k - 1] = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            ans = max(ans, sum - pre[i % k]);
            pre[i % k] = min(pre[i % k], sum);
        }

        return ans;
    }
};