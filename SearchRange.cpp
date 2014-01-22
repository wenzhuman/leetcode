class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
        int index = binarySearch(A,0,n,target);
        if (index==-1){
            result.push_back(-1);
            result.push_back(-1);
        }
        else{
            int beginIndex = index,endIndex = index;
            while(A[beginIndex] == target&&beginIndex>=0){
                beginIndex--;
            }
            result.push_back(beginIndex+1);
            while(A[endIndex] == target&&endIndex<n){
                endIndex++;
            }
            result.push_back(endIndex-1);
        }
        return result;
    }
    int binarySearch(int A[],int begin,int end,int target){
        if(begin>end) return -1;
        
        int mid = begin+(end-begin)/2;
        
        if(A[mid]==target) return mid;
        else if (A[mid]>target){
            binarySearch(A,begin,mid-1,target);
        }
        else{
            binarySearch(A,mid+1,end,target);
        }
    }
};