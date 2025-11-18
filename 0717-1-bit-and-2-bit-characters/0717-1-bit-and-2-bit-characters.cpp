class Solution {
public:
    bool isOneBitCharacter(vector<int> &arr) {
        int n = arr.size();
        int i = 0;

        while (i < n - 1) {
            if (arr[i] == 1) {
                i += 2;  
            } else {
                i += 1;  
            }
        }
        return i == n - 1;
    }
};
