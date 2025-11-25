class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        // let dp[i][j] be a vector of values which can be created from each way of breaking up the items from index i to j
        // for each value at dp[i][j] we 
        
        set<char> ops = {'+', '-', '*'};

        int ez = expression.size();

        // the ith operation will be after the ith number
        vector<char> o;
        vector<int> nums;

        for (int i = 0; i < ez; i++) {
            if (ops.contains(expression[i])) {
                o.push_back(expression[i]);
            } else {
                if (i + 1 < ez && !ops.contains(expression[i + 1])) {
                    nums.push_back((expression[i] - '0') * 10 + (expression[i + 1] - '0'));
                    i++;
                } else {
                    nums.push_back((expression[i] - '0'));
                }
            }
        }

        int nz = nums.size();
        vector<vector<vector<int>>> dp(nz, vector<vector<int>>(nz));

        for (int i = 0; i < nz; i++) {
            dp[i][i].push_back(int(nums[i]));
        }

        for (int l = 2; l <= nz; l++) {
            for (int i = 0; i + l - 1 < nz; i++) {
                int j = l + i - 1;

                // k is the intermediate index splitting our bounds (i.e. i..k and k+1..j)
                for (int k = i; k < j; k++) {
                    for (int lexp : dp[i][k]) {
                        for (int rexp : dp[k + 1][j]) {
                            if (o[k] == '+') dp[i][j].push_back(lexp + rexp);
                            if (o[k] == '-') dp[i][j].push_back(lexp - rexp);
                            if (o[k] == '*') dp[i][j].push_back(lexp * rexp);
                        }
                    }
                }
            }
        }

        return dp[0][nz - 1];
    }
};
