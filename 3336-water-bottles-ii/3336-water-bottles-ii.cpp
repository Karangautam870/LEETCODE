class Solution {
public:
    int maxBottlesDrunk(int nb, int ne) {
        int ans = nb;

        while (nb >= ne) {
            nb -= ne;
            
            ans++;
            ne++;
            nb++;
        }

        return ans;
    }
};