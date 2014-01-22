class Solution {
public:
    int numTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> numTree = {};
        numTree.push_back(1);
        numTree.push_back(1);
        for(int i = 1;i<n;i++){
            int num = 0;
            for(int j = 0;j<=i;j++){
                num += numTree[j]*numTree[i-j];
            }
            numTree.push_back(num);
        }
        return numTree[n];
    }
};