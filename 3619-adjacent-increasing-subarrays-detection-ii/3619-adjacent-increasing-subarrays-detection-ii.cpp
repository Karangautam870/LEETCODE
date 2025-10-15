// class Solution {
// public:
//     bool isValid(vector<int>& nums, int k) {
//         int n = nums.size();

//         for (int i = 0; i <= n - 2 * k; i++) {
//             bool firstInc = true, secondInc = true;

//             for (int j = i; j < i + k - 1; j++) {
//                 if (nums[j] >= nums[j + 1]) {
//                     firstInc = false;
//                     break;
//                 }
//             }

//             if (firstInc) {
//                 for (int j = i + k; j < i + 2 * k - 1; j++) {
//                     if (nums[j] >= nums[j + 1]) {
//                         secondInc = false;
//                         break;
//                     }
//                 }

//                 if (secondInc)
//                     return true;
//             }
//         }

//         return false;
//     }

//     int maxIncreasingSubarrays(vector<int>& nums) {
        
//         int n = nums.size();
//         int l = 1, r = n / 2;
//         int maxK = 0;

//         while (l <= r) {
//             int mid = l + (r - l) / 2;

//             if (isValid(nums, mid)) {
//                 maxK = mid;
//                 l = mid + 1;
//             } else {
//                 r = mid - 1;
//             }
//         }

//         return maxK;
//     }
// };



class Solution {
public:
    void precomputeIncreasingSubarrays(vector<int>& nums, vector<int>& inc) {
        int n = nums.size();
        inc[0] = 1;  
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                inc[i] = inc[i - 1] + 1;  
            } else {
                inc[i] = 1;
            }
        }
    }

    bool isValid(const vector<int>& nums, int k, const vector<int>& inc) {
        int n = nums.size();
        

        for (int i = 0; i <= n - 2 * k; i++) {

            if (inc[i + k - 1] >= k && inc[i + 2 * k - 1] >= k) {
                return true;
            }
        }
        
        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n / 2;
        int maxK = 0;


        vector<int> inc(n, 0);
        precomputeIncreasingSubarrays(nums, inc);  


        while (l <= r) {
            int mid = l + (r - l) / 2;  

            if (isValid(nums, mid, inc)) {
                maxK = mid;  
                l = mid + 1;
            } else {
                r = mid - 1;  
            }
        }

        return maxK;
    }
};
