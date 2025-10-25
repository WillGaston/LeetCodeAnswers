class Solution {
public:
    int totalMoney(int n) {
        int numFullWeeks = n / 7;
        int numExtraDays = n % 7;

        int x = numFullWeeks * 28 + 7 * (numFullWeeks * (numFullWeeks - 1)) / 2;
        int z = ((numFullWeeks + 1) * numExtraDays) + ((numExtraDays * (numExtraDays - 1)) / 2);

        return x + z;
    }
};
