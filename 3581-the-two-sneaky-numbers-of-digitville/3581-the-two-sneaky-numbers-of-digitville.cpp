class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int sum = 0;
        int x = 1;
        vector<int>arr(101,0);

        for(auto&it:nums){
            arr[it]++;
        }
        int a = -1,b = -1;
        for(int i = 0;i <= 100;i++){
            if(arr[i] >= 2 && a == -1){
                a = i;
            }else if(b == -1 && arr[i] >= 2){
                b = i;
                break;
            }
        }
        return {a,b};
    }
};