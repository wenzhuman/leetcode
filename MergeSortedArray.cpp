class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        while(n>0){
            if(m>0&&A[m-1]>B[n-1]){
                
                    A[n+m-1] = A[--m];
                
    
            }
            else{
                A[n+m-1] = B[--n];
            }
        }
    }
};