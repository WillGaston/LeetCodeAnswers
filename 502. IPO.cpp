class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // can finish k projects
        // n projects
        // ith project gives profit[i] but requires capital[i] to start
        // start with w

        // want to maximize profits doing at most k projects

        // simply choose the startable project with the largest profit

        priority_queue<int> a; // just possible profit
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> na; // capital, profit
        int c = w;
        
        for (int i = 0; i < profits.size(); i++) {
            if (capital[i] <= c) {
                a.push({profits[i]});
            } else {
                na.push({capital[i], profits[i]});
            }
        }

        for (int i = 0; i < k && (!a.empty() || !na.empty()); i++) {
            if (!a.empty()) {
                c += a.top();
                a.pop();
            }

            while (!na.empty() && na.top().first <= c) {
                a.push(na.top().second);
                na.pop();
            }
        }

        return c;
    }
};
