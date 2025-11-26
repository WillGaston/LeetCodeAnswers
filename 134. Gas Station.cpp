class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // n gas stations, has gas[i] amount
        // travelling between gas stations incurs a cost : going from i ==> i + 1 costs cost[i]

        // want to determine if we can travel around the circuit once or not ==> return starting index or -1

        // to check if it is possible, track the total gas and total cost

        // to determine if we can start from a point - iterate and check if the current gas allows us to go to the next index
        // - if it does continue
        // - if it does not, then we cannot start from any of the previous points and must start from next point

        int totalCost = 0;
        int totalGas = 0;
        int currGas = 0;
        int ps = 0;

        int ns = gas.size();
        for (int i = 0; i < ns; i++) {
            totalCost += cost[i];
            totalGas += gas[i];
            currGas += (gas[i] - cost[i]);
            if (currGas < 0) {
                ps = i + 1; // cannot start on indices 0..i
                currGas = 0;
            }
        }

        if (totalCost > totalGas) return -1;
        return ps;
    }
};
