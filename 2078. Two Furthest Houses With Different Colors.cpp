class Solution {
public:
    int maxDistance(vector<int>& colors) {
        // simple two pointers at start and end, just advance one if same colour
        // must do from both directions

        int cz = colors.size();
        return max(getDist(1, cz, colors), getDist(0, cz, colors));
    }

    int getDist(int dir, int size, vector<int>& colors) {
        int lo = 0;
        int hi = size - 1;

        while (1) {
            if (colors[lo] == colors[hi]) {
                if (dir == 1) hi--;
                else lo++;
            } else {
                return hi - lo;
            }
        }

        return -1;
    }
};2078. Two Furthest Houses With Different Colors
