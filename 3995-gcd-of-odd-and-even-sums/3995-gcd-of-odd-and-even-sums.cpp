class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // n * (n + 1) --> even numbers
        // n * n --> odd number
        
        return gcd(n * (n + 1),n * n);
    }
};