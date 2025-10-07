class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        // n = rains.size() lakes

        // rains[i] = 0 means no rain on day i, we can choose any lake and empty it.
        // rains[i] > 0, means it rains at lake i

        // a lake can be rained upon twice before overflowing - if overflow then we flood.

        // greedy heuristic:
        // - choose to empty the lake who has the next rainy day and is already full
        // - if none are full, no need to empty anything - choose any index to empty.

        // approach: - create an array to determine the last time any rain got rained on
        //           - maintain a set of unused sunny days which we can perform draining on
        //           - if a lake is at risk of flooding find the sunny day closest to the initial rain which is before the second rain

        int n = rains.size();

        map<int, int> lastDayRained;
        set<int> unusedSunnyDays;
        map<int, int> amountOfRain;

        vector<int> output(n, 1);

        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] > 0) {
                output[i] = -1;
                // if it exists in the map - i.e. is already full
                if (lastDayRained.count(rains[i])) {
                    // find sunny day for drainage
                    int day = findSunnyDay(lastDayRained[rains[i]] + 1, i, unusedSunnyDays);
                    if (day == -1) return {};
                    output[day] = rains[i];
                    // note that the rain on this day makes it full again - once its rained once it will always be full
                }
                lastDayRained[rains[i]] = i;
            } else {
                unusedSunnyDays.insert(i);
            }
        }

        return output;
    }

    // find smallest index in unusedSunnyDays after last rained day for curr index
    int findSunnyDay(int minDay, int maxDay, set<int>& unusedSunnyDays) {
        // first unused day greater than minDay
        auto it = unusedSunnyDays.lower_bound(minDay);

        if (it != unusedSunnyDays.end() && *it <= maxDay) {
            int day = *it;
            unusedSunnyDays.erase(it);
            return day;
        }

        return -1;
    }
};
