class Solution {
public:

        bool allSetBits(int x) {
            return (x & (x + 1)) == 0;
    }

        int smallestNumber(int n) {
            while (!allSetBits(n)) {
            n++;
    }
    return n;
}
};