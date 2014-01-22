class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int>> pascalTriangle;
        if(numRows<=0) return pascalTriangle;
        pascalTriangle.push_back(vector<int>{1});
        for(int i = 1;i < numRows;i++){
        vector<int> row;
        for(int j = 0;j<=i;j++){
            if(j == 0 ||j == i) row.push_back(1);
            else{
                int tmp = pascalTriangle[i-1][j-1]+pascalTriangle[i-1][j];
                row.push_back(tmp);
                }
            }
        pascalTriangle.push_back(row);
        }
            
        return pascalTriangle;
    }
};