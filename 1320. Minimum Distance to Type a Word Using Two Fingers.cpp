class Solution {
public:
    int minimumDistance(string word) {
        // dp[i][j][k] = left finer at i, right finger at j, kth letter in word
        int wz = word.size();
        vector<vector<vector<long long>>> dp(26, vector<vector<long long>>(26, vector<long long>(wz, INT_MAX)));

        for (int i = 0; i < 26; i++) {
            dp[word[0] - 'A'][i][0] = 0;
            dp[i][word[0] - 'A'][0] = 0; 
        }

        for (int k = 1; k < wz; k++) {
            char currLetter = word[k] - 'A';
            char prevLetter = word[k - 1] - 'A';
            int prevDist = dist(currLetter, prevLetter);
            // two core cases
            //  - one of the previous fingers isnt at prev, and the finger that is at prev moves to curr
            //  - the prev finger stays put, and the non-prev finger moves to curr

            for (int j = 0; j < 26; j++) {
                // check dist where prev hand was at prevletter and other is at some j
                dp[currLetter][j][k] = min(dp[currLetter][j][k], dp[prevLetter][j][k - 1] + prevDist);
                dp[j][currLetter][k] = min(dp[j][currLetter][k], dp[j][prevLetter][k - 1] + prevDist);

                // if that some j was prev, then compute dist from any prev i to curr
                if (j == prevLetter) {
                    for (int i = 0; i < 26; i++) {
                        int otherDist = dist(currLetter, i);
                        dp[prevLetter][currLetter][k] = min(dp[prevLetter][currLetter][k], dp[prevLetter][i][k - 1] + otherDist);
                        dp[currLetter][prevLetter][k] = min(dp[currLetter][prevLetter][k], dp[i][prevLetter][k - 1] + otherDist);
                    }
                }
            }
        }

        long long minDist = INT_MAX;

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                minDist = min(minDist, dp[i][j][wz - 1]);
            }
        }

        return (int)minDist;
    }

    int dist(int posA, int posB) {
        int aRow = posA / 6;
        int aCol = posA % 6;
        int bRow = posB / 6;
        int bCol = posB % 6;
        return (abs(aRow - bRow) + abs(aCol - bCol));
    }
};
