class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;

        for (int num : nums) {
            int tempSum = 0;
            int numDivisors = 0;

            for (int i = 1; i <= num / i; i++) {
                if ((num % i) == 0) {
                    if (i == (num / i)) {
                        tempSum += i;
                        numDivisors++;
                    } else {
                        tempSum += (i + (num / i));
                        numDivisors += 2;
                    }
                }
                if (numDivisors > 4) break;
            }

            if (numDivisors == 4) sum += tempSum;
        }

        return sum;
    }
};
