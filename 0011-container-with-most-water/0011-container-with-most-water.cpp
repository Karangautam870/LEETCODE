class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        int j = n - 1;
        int ans = 0;

        while(i < j){
            int h = arr[i];

            if(arr[j] < h){
                h = arr[j];
            }

            int w = j - i;
            int area = h * w;

            ans = max(area,ans);

            if(arr[i] < arr[j]){
                i++;
            }
            else{
                j--;
            }
        }

        return ans;
    }
};
