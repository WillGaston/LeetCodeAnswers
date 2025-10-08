class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // if a potion is successful, all potions of higher strength will also be successful, so find index of potion which is just strong enough
        // if sorted, evcery index greater will also be successful

        sort(potions.begin(), potions.end());

        int numPotions = potions.size() - 1;
        vector<int> output;

        for (int spellStrength : spells) {
            int low = 0;
            int high = numPotions;

            while (low <= high) {
                int mid = (low + high) / 2;
                if (((long long)potions[mid] * spellStrength) >= success) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            output.push_back(numPotions - low + 1);
        }

        return output;
    }
};
