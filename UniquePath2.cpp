
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        int a[m+1][n+1];
        
        for(int i = 0;i<=m;i++){
            for(int j = 0;j<=n;j++){
                a[i][j] = 0;
            }
        }
        
        a[m-1][n] = 1;
        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                if( obstacleGrid[i][j]==1 ){
                    a[i][j] = 0;
                }
                else{
                    a[i][j] = a[i+1][j]+a[i][j+1];
                }
            }
        }
        return a[0][0];
        
    }
