class Solution {
public:
    int minJumps(vector<int>& arr) {
        // use graph :)
        int n = arr.size();

        map<int, vector<int>> m;

        for (int i = 0; i < n; i++) {
            m[arr[i]].push_back(i);
        }

        // once visited, visiting again provides no new paths
        vector<bool> visited (n, false);

        int currSteps = 0;

        queue<pair<int, int>> q;
        q.push({0, 0});

        while (q.size() > 0) {
            pair<int, int> p = q.front();
            q.pop();
            int currNode = p.first;
            int currDepth = p.second;
            if (currNode == n - 1) return currDepth;

            for (int neighbour : m[arr[currNode]]) {
                if (visited[neighbour]) continue;
                visited[neighbour] = true;
                q.push({neighbour, currDepth + 1});
            }

            m[arr[currNode]].clear();

            if (currNode - 1 >= 0 && !visited[currNode - 1]) {
                visited[currNode - 1] = true;
                q.push({currNode - 1, currDepth + 1});
            }

            if (currNode + 1 < n && !visited[currNode + 1]) {
                visited[currNode + 1] = true;
                q.push({currNode + 1, currDepth + 1});
            }

            visited[currNode] = true;
        }

        return -1;    
    }
};
