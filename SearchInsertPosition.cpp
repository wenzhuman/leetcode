class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int index = n;
        
        for(int i = 0; i<n; i++){
            if (target< A[i]) {
                index = i;
                 return index;
            }
            else if(target == A[i]) {
                index = i;
                 return index;
            }
        }
        return n;
    }
};