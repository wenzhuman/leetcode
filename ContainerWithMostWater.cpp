class Solution {
public:
    int maxArea(vector<int> &height) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
    int maxA = 0;
    int i = 0;
    int j = height.size()-1;
    while(i < j){
        int curArea = (j-i) * (min(height[i], height[j]));
        maxA = max(curArea,maxA);
        if(height[i] < height[j]) i++;
        else j--;
    }

        return maxA;
    }
};