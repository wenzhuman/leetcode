class Solution {
public:
    int trap(int A[], int n) {
        if(n<=2) return 0;
        int leftMost[n];
        int rightMost[n];
        int leftMostValue = INT_MIN;
        int rightMostValue = INT_MIN;
        for(int i = 1;i<n;i++){
            if(A[i-1]>leftMostValue){
                leftMostValue= A[i-1];
            }
            leftMost[i] = leftMostValue;
        }
        int sum = 0;
        for(int i = n-2;i>0;i--){
            if(A[i+1]>rightMostValue){
                rightMostValue= A[i+1];
            }
            rightMost[i] = rightMostValue;
            
            int thred = rightMost[i]>leftMost[i]?leftMost[i]:rightMost[i];
            if(thred-A[i]>0){
                sum+=thred-A[i];
            }
        }
        return sum;
        
    }
};