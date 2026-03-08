class Solution {
public:
    int minInsertions(string s) {
        int num = 0;
        int stackSize = 0;
        int sz = s.size();

        // single ) means we need to insert to form ))
        // )) with empty stack means we insert (
        // each remaining ( requires inserting ))

        for (int i = 0; i < sz; i++) {
            if (s[i] == ')') {
                if (i + 1 >= sz || s[i + 1] != ')') { num++; }
                else i++;
                if (stackSize >= 1) {
                    stackSize--;
                } else {
                    num++;
                }
            } else {
                stackSize++;
            }
        }

        num += 2 * stackSize;

        return num;
    }
};
