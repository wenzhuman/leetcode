class Solution {
public:
    int climbStairs(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> steps = {};
        steps.push_back(0);
        steps.push_back(1);
        steps.push_back(2);
        for(int i = 3; i<=n; i++){
            int step = steps[i-1] + steps[i-2];
            steps.push_back(step); 
        }
        return steps[n];
    }
};