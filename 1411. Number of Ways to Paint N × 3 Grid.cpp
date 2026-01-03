class Solution {
public:
    int numOfWays(int n) {
        // no two adjacent squares can be the same colour.
        // each row 3 wide has 4 instances of colour j in each of the three cols.
        // there are two patterns: 2 colours XYX and 3 colours XYZ
        // let two[i] be the number of ways to paint an i x 3 grid using 2 colours
        // let three[i] be the number of ways to paint an i x 3 grid using three colours.

        // a two colour row can come from: 3 two colours, 2 three colours
        // a three colour row can come from: 2 three colours, 2 two colours

        // two[1] = 6
        // three[1] = 6

        int modNum = 1000000007;
        
        vector<long> two;
        vector<long> three;

        two.push_back(6);
        three.push_back(6);

        for (int i = 1; i <= n; i++) {
            two.push_back((2*three[i - 1] + 3*two[i - 1]) % modNum);
            three.push_back((2*three[i - 1] + 2*two[i - 1]) % modNum);
        }

        return (two[n - 1] + three[n - 1]) % modNum;
    }
};
