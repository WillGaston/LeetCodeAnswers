class Solution {
public:
    int reverseBits(int n) {
        // we can uise XOR to flip the bits

        // 0 <--> 1, 0^1 = 1 (R), 0<->1, 0^1 = 1 (L), 1<->1, 1^1 = 0 (R) ==> 1 <--> 0 (flipped)
        // using the same logic for 0-0, 1-1, 1-0, the bits will also be flipped

        //e.g. n[i] = n[i] ^ n[32 - i]
        // n[32 - i] = n[i] ^ n[32 - i]
        // n[i] == n[i] ^ n[32 - i]

        // in such a case when it is an int simply iterate in reverse and append to new int
        int newI = 0;

        for (int i = 0; i < 32; i++) {
            newI |= ((n & 1) << (32 - i - 1));
            n >>= 1;
        }

        return newI;
    }
};
