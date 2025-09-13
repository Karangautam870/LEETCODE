
class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> arr(26, 0);

        for (char& it : s) {
            arr[it - 'a']++;
        }

        int r1 = 0; 
        int r2 = 0; 

        for (int i = 0; i < 26; i++) {
            if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20) { 
                r1 = max(arr[i], r1);
            } else {
                r2 = max(arr[i], r2);
            }
        }
        return r1 + r2;
    }
};