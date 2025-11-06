class Solution {
public:
    vector<int> parents;

    void unify(int a, int b) {
        int aPar = find(a);
        int bPar = find(b);
        if (aPar != bPar) {
            parents[aPar] = bPar;
        }
    }

    int find(int a) {
        if (parents[a] == a) return a;
        return parents[a] = find(parents[a]);
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> output;

        for (int i = 0; i <= c; i++) {
            parents.push_back(i);
        }

        for (vector<int> connection : connections) {
            unify(connection[0], connection[1]);
        }

        map<int, vector<set<int>>> cc;
        // m[blah][0] means operational
        // m[blah][1] means offline

        for (int i = 0; i <= c; i++) {
            int parent = find(i);
            if(cc.find(parent) == cc.end()) {
                cc[parent] = vector<set<int>>(2);
            }
            cc[parent][0].insert(i);
        }

        for (vector<int> check : queries) {
            int s = check[1];
            int parent = find(s);

            if (check[0] == 2) {
                cc[parent][1].insert(s);
                cc[parent][0].erase(s);
            } else {
                if (cc[parent][0].count(s)) output.push_back(s);
                else if (cc[parent][0].size() == 0) output.push_back(-1);
                else {
                    output.push_back(*(cc[parent][0].begin()));
                }
            }
        }

        return output;
    }
};
