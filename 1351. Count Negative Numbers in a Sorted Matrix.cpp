class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // non-increasing, so something to the right or down must be less than or equal to.
        // start at top right
        //  - if current is positive, go down until a negative is found
        //  - if current is negative - iterate left until a positive is found
        //      - everything to right in current row is negative - move down as it must be smaller than current
        // repeate until we cannot move anymore

        int count = 0;

        int xs = grid[0].size();
        int ys = grid.size();

        int x = xs - 1;
        int y = 0;

        while (y < ys && x >= 0) {
            if (grid[y][x] < 0) {
                count += (ys - y);
                x--;
            } else {
                y++;
            }
        }

        return count;
    }
};
