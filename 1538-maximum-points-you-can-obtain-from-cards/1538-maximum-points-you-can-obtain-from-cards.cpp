class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();

        int j = 0,ans = 0,left = 0, right = 0;
        
        while (j < k) {
            left += arr[j];
            j++;
        }

        ans = left;

        j = 0;

        while (j < k) {
            right += arr[n - 1 - j];
            left -= arr[k - 1 - j];

            ans = max(ans, left + right);

            j++;
        }
        return ans;
    }
};