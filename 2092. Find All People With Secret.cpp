class Solution {
public:
    vector<int> parents;
    int firstSecretHolder = 0;

    void unify(int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if (parA == parB) return;

        if (parA == 0) parents[parB] = 0;
        else if (parB == 0) parents[parA] = 0;
        else parents[parA] = parB;
    }

    int find(int a) {
        if (parents[a] == a) return a;
        return parents[a] = find(parents[a]);
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> res;
        int mz = meetings.size();

        for (int i = 0; i < n; i++) parents.push_back(i);

        parents[firstPerson] = 0;

        sort(meetings.begin(), meetings.end(), [](vector<int>& a, vector<int>& b) {return a[2] < b[2];});

        for (int i = 0; i < mz;) {
            vector<int> peopleThisIt;
            int currTime = meetings[i][2];

            int j = i;
            while (j < mz && meetings[j][2] == currTime) {
                unify(meetings[j][0], meetings[j][1]);
                peopleThisIt.push_back(meetings[j][0]);
                peopleThisIt.push_back(meetings[j][1]);
                j++;
            }

            for (int person : peopleThisIt) {
                if (find(person) != 0) {
                    parents[person] = person;
                }
            }

            i = j;
        }

        for (int i = 0; i < n; i++) {
            if (find(i) == 0) res.push_back(i);
        }

        return res;
    }
};
