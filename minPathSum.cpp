class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        vector<vector<int>> minPathSum(grid.size()+1,vector<int>(grid[0].size()+1,0));
        //minPathSum[][] = grid[grid.size()-1][grid[0].size()-1];
        for(int i = grid.size()-1; i >= 0;i--){
            for(int j = grid[0].size()-1;j>=0;j--){
                if(i == grid.size()-1){
                    minPathSum[i][j] = grid[i][j]+minPathSum[i][j+1];
                }
                else if(j == grid[0].size()-1){
                    minPathSum[i][j] = grid[i][j]+minPathSum[i+1][j];
                }
                else{
                    minPathSum[i][j] = grid[i][j]+min(minPathSum[i+1][j],minPathSum[i][j+1]); 
                }
            }
        }
     
            return minPathSum[0][0];
        
        
    }
};