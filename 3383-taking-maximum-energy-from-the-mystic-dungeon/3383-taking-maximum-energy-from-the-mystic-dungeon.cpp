class Solution {
public:
    int maximumEnergy(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> sum(n, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            sum[i] = arr[i];
            if (i + k < n) {
                sum[i] += sum[i + k];
            }
        }

        int ans = sum[0];
        for (int i = 1; i < n; i++) {
            ans = max(ans, sum[i]);
        }
        return ans;
    }
};