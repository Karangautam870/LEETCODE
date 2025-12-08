class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        unordered_set<int>st;
        for(int a = 1; a <= n;a++){
            st.insert(a * a);
        }
        for(int c = n;c >= 1;c--){
            for(int b = c - 1; b >= 1;b--){
                if(st.count(c * c - b * b)){
                    ans++;
                }
            }
        }
        return ans;
    }
};