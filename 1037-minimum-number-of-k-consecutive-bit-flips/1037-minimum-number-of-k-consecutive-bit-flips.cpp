class Solution {
public:
    int minKBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0,flip = 0;

        int i = 0;

        while (i < n) {
            
            if (i >= k && arr[i - k] > 1) {
                flip ^= 1;
                arr[i - k] -= 2;
            }

            if ((arr[i] ^ flip) == 0) {
                if (i + k > n){
                    return -1;
                }
                
                ans++;
                flip ^= 1;
                arr[i] += 2;
            }
            i++;
        }

        return ans;
    }
};