class Solution {
public:
    int findClosest(int x, int y, int z) {
        int cnt1 = (x > z) ? (x - z) : (z - x);
        int cnt2 = (y > z) ? (y - z) : (z - y);

        if(cnt1 == cnt2){
            return 0;
        } else if (cnt1 < cnt2){
            return 1;
        } else {
            return 2;
        }
    }
};
