class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
       array<bool,9> a;
        a.fill(false);
        for(int i = 0;i<9;i++){
             a.fill(false);
            
            for(int j = 0;j<9;j++){
                
                if(board[i][j]!='.'){
                int index = board[i][j] - '1';
                
                if(a[index] == true) {
                    return false;
                }
                a[index] = true;
                }
            }
        }
        a.fill(false);
        for(int k = 0;k<9;k=k+3){
            //a.fill(false);
            for(int h = 0;h<9;h=h+3){
            a.fill(false);
            for(int i = 0;i<3;i++){
                for(int j = 0;j<3;j++){
                    if(board[k+i][h+j]!='.'){
                    int index = board[k+i][h+j] - '1';
                    if(a[index] == true) {
                        return false;
                    }
                    a[index] = true;
                    }
                }
            }
            
            }
        }
        a.fill(false);
        for(int j = 0;j<9;j++){
            a.fill(false);
            for(int i = 0;i<9;i++){
                if(board[i][j]!='.'){
                int index = board[i][j] - '1';
                if(a[index] == true) {
                    return false;
                }
                a[index] = true;
                }
            }
        }
        return true;
    }
};