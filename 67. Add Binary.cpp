class Solution {
public:
    string addBinary(string a, string b) {
        string out = "";

        bool carry = false;
        int as = a.size();
        int bs = b.size();

        int i = as - 1;
        int j = bs - 1;

        while (i >= 0 || j >= 0) {
            int ab = 0;
            int bb = 0;

            if (i >= 0) ab = a[i] - '0';
            if (j >= 0) bb = b[j] - '0';

            int sum = ab + bb + ((carry) ? 1 : 0);

            if (sum == 0) {
                out.push_back('0');
                carry = false;
            } else if (sum == 1) {
                out.push_back('1');
                carry = false;
            } else if (sum == 2) {
                out.push_back('0');
                carry = true;
            } else {
                out.push_back('1');
                carry = true;
            }

            i--;
            j--;
        }

        if (carry) out.push_back('1');
        reverse(out.begin(), out.end());

        return out;      
    }
};
