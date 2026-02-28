class Solution {
public:
    int concatenatedBinary(int n) {
        long out = 0;
        int numBits = 0; // need to know how much to leftshift each individual number, rather than /2 each time, track bits

        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) numBits++;
            out = ((out << numBits) | i) % 1000000007;
        }

        return out;
    }
};
