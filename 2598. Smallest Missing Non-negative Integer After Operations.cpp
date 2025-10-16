class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        // need to find the maximum smallest missing non-negative integer

        vector<int> freq(value, 0);
        cout << value << endl;

        for (int num : nums) {
            cout << num % value << endl;
            if (num % value < 0) {
                freq[(num % value) + value]++;
            } else {
                freq[num % value]++;
            }
            if ()
        }

        int magnitude = INT_MAX;
        int mod = INT_MAX;

        // we want the smallest mod of the smallest magnitude

        for (int i = 0; i < value; i++) {
            if (freq[i] < magnitude) {
                magnitude = freq[i];
                mod = i;
            }
        }

        return (value * magnitude) + mod;
    }
};
