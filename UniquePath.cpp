class Solution {
public:
    int uniquePaths(int m, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        //vector<vector<int> > a(m+1,vector<int>(n+1,0));
        auto a = new int[m+1][n+1];
        
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
        /*const int M_MAX = 100;
        const int N_MAX = 100;
        int mat[M_MAX+2][N_MAX+2] = {0};
        mat[m][n+1] = 1;
 
        for (int r = m; r >= 1; r--)
        for (int c = n; c >= 1; c--)
        mat[r][c] = mat[r+1][c] + mat[r][c+1];
 
        return mat[1][1];*/
    }
};