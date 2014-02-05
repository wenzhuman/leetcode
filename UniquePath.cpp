class Solution {
public:
    int uniquePaths(int m, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int a[m+1][n+1];
        
        for(int i = 0;i<=m;i++){
            for(int j = 0;j<=n;j++){
                a[i][j] = 0;
            }
        }
        
        a[m-1][n] = 1;
        
        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                a[i][j] = a[i+1][j]+a[i][j+1];
            }
        }
        return a[0][0];
    }
};