class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> results;
        int delta = 0;
        int m = matrix.size();
        if(m==0) return results;
        int n = matrix[0].size();
        if(m<=1|n<=1) {
            for(auto vec:matrix){
                for(int ele:vec){
                    results.push_back(ele);
                }
            }
            return results;
        }
        
       
        
        int i = -1,j=-1;
        while(true){
            if(results.size()==m*n-1){
                i++;
                j++;
                results.push_back(matrix[i][j]);
                if(results.size()==m*n) return results;
            }
            for(i++,j++;j<n-delta-1;j++){
                results.push_back(matrix[i][j]);
                if(results.size()==m*n) return results;
            }

            for(;i<m-delta-1;i++){
                results.push_back(matrix[i][j]);
                if(results.size()==m*n) return results;
            }
            for(;j>delta;j--){
                results.push_back(matrix[i][j]);
                if(results.size()==m*n) return results;
            }
            
            for(;i>delta;i--){
                results.push_back(matrix[i][j]);
                if(results.size()==m*n) return results;
            }
            delta++;
        }
        return results;
    }
};