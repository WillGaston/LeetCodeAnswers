class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> out;

        // 1111111111 is 1023 in decimal, thus iterate over all bit combinations
        for (int i = 0; i < 1024; i++) {
            int numUsed = 0;
            int temp = i;
            while (temp > 0) {
                if ((temp & 1) == 1) numUsed++;
                temp >>= 1;
            }

            if (numUsed != turnedOn) continue;

            int hours = i >> 6;
            int minutes = i & 63;

            if (hours < 12 && minutes < 60) {
                string time = to_string(hours) + ((minutes < 10) ? ":0" : ":") + to_string(minutes);
                out.push_back(time);
            }
        }

        return out;
    }
};
