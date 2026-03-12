class Solution {
public:
    int find(vector<int> &par, int x) {
        if (par[x] != x) par[x] = find(par, par[x]);
        return par[x];
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        // need to find the maximum, minimum stability score of any valid MST
        // first include all must edges
        // add remaining edges greedily weight
        //  - we want to increase the score of the smallest needed edges

        // modified kruskalls sorting by decreasing, the last k edges get doubled

        set<int> used;
        vector<vector<int>> usedEdgeStr;
        vector<vector<int>> nonMust;
        int minStr = INT_MAX;
        vector<int> par(n, 0);

        for (int i = 0; i < n; i++) {
            par[i] = i;
        }

        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[2] > b[2];
        });

        for (vector<int> e : edges) {
            int u = e[0];
            int v = e[1];
            int isMust = e[3];
            int str = e[2];

            if (isMust) {
                used.insert(u);
                used.insert(v);
                par[find(par, v)] = find(par, u);
                minStr = min(minStr, str);
                usedEdgeStr.push_back({str, 1});
            } else {
                nonMust.push_back(e);
            }
        }

        for (vector<int> e : nonMust) {
            int u = e[0];
            int v = e[1];
            int isMust = e[3];
            int str = e[2];

            if (find(par, u) != find(par, v)) {
                used.insert(u);
                used.insert(v);
                par[find(par, v)] = find(par, u);
                usedEdgeStr.push_back({str, 0});
            }
        }

        sort(usedEdgeStr.begin(), usedEdgeStr.end());

        int uesz = usedEdgeStr.size();

        for (vector<int> eu : usedEdgeStr) {
            if (eu[1] == 1) continue;
            if (k > 0) { eu[0] *= 2; k--; }
            minStr = min(minStr, eu[0]);
        }

        int parPot = find(par, 0);
        for (int i = 1; i < n; i++) {
            if (find(par, i) != parPot) return -1;
        }

        return (uesz == n - 1) ? minStr : -1;

    }
};
