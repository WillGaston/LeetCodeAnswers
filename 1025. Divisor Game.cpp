class Solution {
public:
    bool divisorGame(int n) {
        // if n is even, we can always subtract 1 and make it odd.
        // if n is odd, we can subtract an odd number which will make it even, we cannot make it odd again

        // we can never get to 0 because x < n, so the person who wins is the one who stops the other person from hacving a move

        // base cases:
        // if we get n == 1, then we lose because we cant subtract any x
        // if we get n == 2, then we win, because we subtract one and hand it to the other person

        // so we win if we can get to n == 2 or equivalent
        // they win if we get to n == 1.

        // if both play optimally the person who gets the first even turn will always force the number odd, so that the other player can never get to n == 2.

        if (n % 2 == 0) return true;
        return false;
    }
};
