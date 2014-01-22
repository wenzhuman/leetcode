class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int rowNum = -1;
        for(int i = 0;i<matrix.size();i++){
            if(matrix[i][0]<target){ 
            rowNum = i;
            }
            if(matrix[i][0]==target){
                return true;
            }
        }
        if(rowNum<0) return false;
        int index = binarySearch(matrix[rowNum],target);
        if(index>=0) return true;
        else return false;
    }
    int binarySearch(vector<int> &row,int target){
       
        if(row.size()== 0) return -1;
        int mid = row.size()/2;
        vector<int> left(row.begin(),row.begin()+mid);
        if(row[mid]>target) return binarySearch(left,target);
        vector<int> right(row.begin()+mid+1,row.end());
        if(row[mid]<target) return binarySearch(right,target);
        else return mid;
        
    }
    
};