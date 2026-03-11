class ATM {
public:
    map<int, int> bm;
    vector<int> posToNote = {20, 50, 100, 200, 500};

    ATM() {
        bm.clear();
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) {
            bm[posToNote[i]] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        // greedy - must use largest or fail
        vector<int> used(5, 0);
        for (int i = 4; i >= 0; i--) {
            int noteAmount = posToNote[i];
            used[i] = min(bm[noteAmount], amount / noteAmount);
            amount -= used[i] * noteAmount;
        }

        if (amount > 0) {
            return { -1 };
        }

        for (int i = 0; i < 5; i++) {
            bm[posToNote[i]] -= used[i];
        }

        return used;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
