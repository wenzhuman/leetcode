class Solution {
public:
    bool canJump(int A[], int n) {
        int steps = A[0];
        if(n<=1) return true;
        while (steps< n&&steps>0){
            if(steps==n-1) return true;
            else{
                if(A[steps]<=0) return false;
                else steps += A[steps];
            }
        }
        if(steps>= n) return true;
        else{
            return false;
        }
    }
};