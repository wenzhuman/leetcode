class Solution {
public:
    bool search(int A[], int n, int target) {
        int rotateIndex = n-1;
        for(int i = 1;i<n;i++){
            if(A[i-1]>A[i])
            rotateIndex = i-1;
        }
        int search1 = binarySearch(A,0,rotateIndex,target);
        int search2 = -1;
        if(rotateIndex+1<n){
          search2 = binarySearch(A,rotateIndex+1,n-1,target);
        }
        
        if(search1!=-1){
            return true;
        }
        else return search2!=-1;
    }
    int binarySearch(int A[], int begin, int end, int target){
        if(begin>end) return -1;
        int mid = begin+(end-begin)/2;
        if(A[mid] == target) return mid;
        else if(A[mid] < target) return binarySearch(A,mid+1,end, target);
        else return binarySearch(A,begin,mid-1, target);
    }
};