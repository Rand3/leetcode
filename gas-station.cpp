class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // https://oj.leetcode.com/problems/gas-station/
        //
        // There are N gas stations along a circular route, where the amount of gas
        // at station i is gas[i]. You have a car with an unlimited gas tank and it
        // costs cost[i] of gas to travel from station i to its next station (i+1). 
        // You begin the journey with an empty tank at one of the gas stations.
        // Return the starting gas station's index if you can travel around the circuit 
        // once, otherwise return -1. Note: The solution is guaranteed to be unique. 
        
        // start from zero, travel around the circuit, ignore the 'out-of-gas' error.
        // draw a graph with x for stations, and y for remaining gas. the lowest y
        // position is the answer to the problem.
        int top = INT_MAX;
        int remaining = 0;
        int station = -1;
        int size = (int)gas.size();
        if (size == 0 || size != (int)cost.size()) { return station; }
        for (int i = 0; i < size; i++) {
            remaining += gas[i] - cost[i];
            if (remaining < top) {
                top = remaining;
                station = i + 1;
            }
        }
        if (station == size) { station = 0; }
        return (remaining < 0 ? -1 : station);
    }
};
