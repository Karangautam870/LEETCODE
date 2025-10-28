class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                
                for (int dir : {-1, 1}) {
                    vector<int> temp = nums; 
                    int j = i;               
                    int move = dir;          

                    while (j >= 0 && j < n) {
                        if (temp[j] == 0) {
                            j += move; 
                        } else {
                            temp[j]--; 
                            move = -move; 
                            j += move; 
                        }
                    }

                    bool valid = true;
                    for (int k = 0; k < n; k++) {
                        if (temp[k] != 0) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
