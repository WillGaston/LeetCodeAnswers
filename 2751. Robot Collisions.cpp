class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // use stack push left onto it - pop and reduce value for right
        // - if nothing on stack and right - add to result
        // - if nothing left add what is on stack to result

        // convert to vector of vectors then sort based on position before

        vector<int> result;
        vector<vector<int>> tentative;
        stack<vector<int>> s;
        vector<vector<int>> robots;
        int nrz = directions.size();

        for (int i = 0; i < nrz; i++) {
            // L = 1, R = 2
            robots.push_back({positions[i], healths[i], (directions[i] == 'R') ? 2 : 1, i});
        }

        sort(robots.begin(), robots.end(), [](const auto& a, const auto& b) {return a[0] < b[0];});

        cout << robots[0][1];

        for (int i = 0; i < nrz; i++) {
            bool isLeft = (robots[i][2] == 1);

            // if same as s top, add to s - else compute deletions
            if (!isLeft) {
                s.push(robots[i]);
            } else {
                bool hasHealth = true;

                while (s.size() > 0 && hasHealth) {
                    vector<int> t = s.top();
                    bool topLeft = (t[2] == 1);

                    // same dir - left, so just add
                    if (topLeft) {
                        s.push(robots[i]);
                        hasHealth = false;
                        break;
                    } else { // diff dirs, so compute
                        // both destruct, both removed
                        s.pop();
                        if (robots[i][1] == t[1]) {
                            hasHealth = false;
                        }
                        // curr R > L, so do not add L back, reduce R pos by 1
                        else if (robots[i][1] > t[1]) {
                            robots[i][1]--;
                        }
                        // L > R, just reduce L pos by one and readd
                        else {
                            t[1]--;
                            s.push(t);
                            hasHealth = false;
                        }
                    }
                }
                if (hasHealth) s.push(robots[i]);
            }
        }

        while (s.size() > 0) {
            vector<int> t = s.top();
            s.pop();
            tentative.push_back({t[1], t[3]});
        }

        sort(tentative.begin(), tentative.end(), [](const auto& a, const auto& b) {return a[1] < b[1];});
        for (vector<int> i : tentative) {
            result.push_back(i[0]);
        }

        return result;
    }
};
