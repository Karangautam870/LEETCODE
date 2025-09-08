class Solution {
public:
    bool check(int n){
        while(n > 0){
            if(n%10 == 0){
                return 0;
            }
            n /= 10;
        }
        return 1;
    }

    vector<int> getNoZeroIntegers(int n) {
        int a = -1 , b = -1;
        for(int i = 1; i < n;i++){
            if(check(i) && check(n - i)){
                return {i , n - i};
            }
        }
        return {1,1};
    }
};