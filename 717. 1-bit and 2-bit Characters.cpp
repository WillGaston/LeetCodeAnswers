class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int numConsec1 = 0;

        for (int i = bits.size() - 2; i >=0; i--) {
            if (bits[i] == 1) numConsec1++;
            else break;
        }

        return ((numConsec1 % 2 == 0));
    }
};
