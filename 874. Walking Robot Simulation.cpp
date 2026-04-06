class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0;
        int y = 0;
        int dir = 1; // 1 = n, 2 = e, 3 = s, 4 = w
        int dist = 0;

        map<int, map<int, int>> obs; // 1 = x, 2 = y
        for (vector<int> o : obstacles) {
            obs[o[0]][o[1]] = 1;
        }

        for (int command : commands) {
            if (command == -2) {
                if (dir == 1) dir = 4;
                else dir--;
            } else if (command == -1) {
                if (dir == 4) dir = 1;
                else dir++;
            } else {
                if (dir == 1 || dir == 3) {
                    // move in y
                    for (int i = 0; i < command; i++) {
                        if (obs[x][y + ((dir == 1) ? 1 : -1)] == 1) break; 
                        if (dir == 1) y++;
                        else y--;
                    }
                } else {
                    // move in x
                    for (int i = 0; i < command; i++) {
                        if (obs[x + ((dir == 2) ? 1 : -1)][y] == 1) break; 
                        if (dir == 2) x++;
                        else x--;
                    }
                }
            }
            dist = max(dist, static_cast<int>((x*x + y*y)));
        }

        return dist;
    }
};
