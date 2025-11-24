class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
       int nb = books.size();
       vector<int> dp(nb + 1, 0);

       // let dp[i] be the minimum total height needed to store the first i books
       // for each i we consider the possible start postition j of the last bookshelf
       //  - dp[i] will then bee the minimum total height of shelves exclduing the new one starting at j + the height of the new one at j

        dp[0] = 0;
        dp[1] = books[0][1];

        for (int i = 1; i <= nb; i++) {
            int remainingW = shelfWidth - books[i - 1][0];
            int currH = books[i - 1][1];
            dp[i] = dp[i - 1] + currH;

            // consider adding the jth book to the new shelf
            for (int j = i - 1; j > 0; j--) {
                remainingW -= books[j - 1][0];
                if (remainingW < 0) break;
                currH = max(currH, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + currH);
            }
        }

        return dp[nb];
    }
};
