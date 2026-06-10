class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank = 0;
        int currTank = 0;
        int startStation = 0;

        for (int i = 0; i < gas.size(); ++i) {
            int diff = gas[i] - cost[i];
            totalTank += diff;
            currTank += diff;

            // If we run out of gas on this route, the current start won't work
            if (currTank < 0) {
                startStation = i + 1; // Try next station as starting point
                currTank = 0;
            }
        }

        return (totalTank >= 0) ? startStation : -1;
    }
};
