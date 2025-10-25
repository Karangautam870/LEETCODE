class Solution {
public:
    int totalMoney(int n) {
        if (n <= 7) {
            return n * (n + 1) / 2;
        }

        int cnt = 1;                  
        vector<int> day(7, 0);        

        for (int i = 1; i <= n; i++) {
            int idx = (i - 1) % 7;    
            
            day[idx] += cnt;          
            cnt++;

            if (i % 7 == 0) {
                cnt = (i / 7) + 1;  
            }
        }

        int ans = 0;
        for (int i = 0; i < 7; i++) {
            ans += day[i];
        }

        return ans;
    }
};
