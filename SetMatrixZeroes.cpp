class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
 
            if(matrix.size()>0){
                bool row1 = checkZero(matrix,-1,0);
                bool col1 = checkZero(matrix,0,-1);
                
                for(int i = 1;i<matrix.size();i++){
                    if(checkZero(matrix,-1,i))
                    matrix[i][0]= 0;
                }
                
               
                
                if(matrix[0].size()>0){
                    for(int i = 1;i<matrix[0].size();i++){
                        if(checkZero(matrix,i,-1))
                        matrix[0][i]= 0;
                    }
                }
                
                for(int i = 1;i<matrix.size();i++){
                    for(int j = 1;j<matrix[0].size();j++){
                        if(matrix[i][0] == 0||matrix[0][j] == 0)  matrix[i][j] = 0;
                    }
                }
                
                if(row1) {
                    for(int i = 0;i<matrix[0].size();i++){
                        matrix[0][i] = 0;
                    }
                }
                
                if(col1){
                    for(int i = 0;i<matrix.size();i++){
                        matrix[i][0] = 0;
                    }
                }
            }
            
            
    }
        
    bool checkZero(vector<vector<int> > &matrix, int col , int row){
        if(row >= 0){
            for(int i = 0;i<matrix[0].size();i++){
                if(matrix[row][i] == 0) return true;
            }
        
        }
        if(col >= 0){
            for(int i = 0;i<matrix.size();i++){
                if(matrix[i][col] == 0) return true;
            }
        }
        return false;
    }
};