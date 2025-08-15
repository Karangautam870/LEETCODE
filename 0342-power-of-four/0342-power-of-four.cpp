class Solution {
public:
    bool isPowerOfFour(int n) { 
        if(n <= 0){
            return 0;
        }

        // int i = 0;
        // while(i <= n/2){
        //     if(pow(4,i) == n){
        //         return 1;
        //     }
        //     if(pow(4,i) > n){
        //         break;
        //     }
        //     i++;
        // }

        // return 0;
        return n>0 && !(n & (n-1)) && (n & 0x55555555);
    }
};