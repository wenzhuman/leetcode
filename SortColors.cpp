class Solution {
public:
    void sortColors(int A[], int n) {
        if(n <= 1) return;
        int pos_red = 0;
        int pos_blue = n-1;
        int cur = 0;
        while(cur<=pos_blue&&pos_red<n&&pos_blue>=0){
             if(A[cur] == 1) {
                cur++;
                continue;
            }
            if(A[cur] == 2){
                if(cur<pos_blue){
                    swap(A[pos_blue], A[cur]);
                    pos_blue--;
                }
                else{
                    cur++;
                }
                continue;
            }
            if(A[cur] == 0){
               
                if(cur>pos_red){
                    swap(A[pos_red], A[cur]);
                    pos_red++;
                }
                else{
                    cur++;
                }
                continue;
            }
            
        }
    }
    void swap(int&n,int&m){
        if(n!=m){
            int temp = m;
            m = n;
            n = temp;
        }
    }
};