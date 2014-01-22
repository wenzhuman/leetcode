class Solution {
public:
    int maxSubArray(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> currentMAX(A,A+n);
        for(int i = 1;i<n;i++){
            
            if(currentMAX[i-1]>0){
            currentMAX[i] += currentMAX[i-1];
            }
        }
        int max= currentMAX[0];//consider the negative case so initialize the array to the first elem
        for(int i = 0;i<n;i++){
            if(currentMAX[i]>max)
                max = currentMAX[i];
        }
        return max;
    }
};