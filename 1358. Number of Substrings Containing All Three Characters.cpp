class Solution {
public:
    int numberOfSubstrings(string s) {
        // 
        int sz = s.size();
        vector<int> v1(sz, -1);
        vector<int> v2(sz, -1);
        vector<int> v3(sz, -1);

        int num = 0;

        for (int i = 0; i < sz; i++) {
            switch(s[i]) {
                case 'a':
                    v1[i] = i;
                    if (i - 1 >= 0) {v2[i] = v2[i - 1];v3[i] = v3[i - 1];}
                    break;
                case 'b':
                    v2[i] = i;
                    if (i - 1 >= 0) {v3[i] = v3[i - 1];v1[i] = v1[i - 1];}
                    break;
                case 'c':
                    v3[i] = i;
                    if (i - 1 >= 0) {v2[i] = v2[i - 1];v1[i] = v1[i - 1];}
                    break;
            } 
            int mini = min(v1[i], min(v2[i], v3[i]));
            if (mini == -1) continue;
            num += mini + 1;
        }

        return num;
    }
};
