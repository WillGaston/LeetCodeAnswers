class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int total = 0;
        int prevNum = 0;

        for (string row : bank) {
            int currNum = 0;
            for (char c : row) {
                if (c == '1') currNum++;
            }

            total += currNum * prevNum;
            if (currNum != 0) prevNum = currNum;
        }

        return total;
    }
};
