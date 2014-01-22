class Solution {
public:
    int removeDuplicates(int A[], int n) {
        bool isTwo = false;
        if(n==0) return 0;
        int j = 1;
        for(int i = 1;i<n;i++){
            if(A[i-1]==A[i]&&isTwo == false){
                isTwo = true;
                A[j] = A[i];
                j++;
            }
            else if(A[i-1]!=A[i]){
                if(isTwo == true){
                    isTwo = false;
                }
                A[j] = A[i];
                j++;
            }
        }
        return j;
    }
};