class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> >results(n, vector<int>(n));
        int i = -1, j = -1, delta = 0;
        int elem = 1;
        while(elem<=n*n){
            if(elem==n*n){
                i++;
                j++;
                results[i][j] = elem;
                return results;
            }
             for(i++,j++;j<n-delta-1;j++){
                results[i][j] = elem;
                elem++;
                if(elem>n*n) return results;
            }
            for(;i<n-1-delta;i++){
                results[i][j] = elem;
                elem++;
                if(elem>n*n) return results;
            }
            for(;j>delta;j--){
                results[i][j] = elem;
                elem++;
                if(elem>n*n) return results;
            }
            for(;i>delta;i--){
                results[i][j] = elem;
                elem++;
                if(elem>n*n) return results;
            }
            delta++;
        }
        
    }
};