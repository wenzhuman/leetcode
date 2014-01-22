class Solution {
public:
    vector<int> grayCode(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        int graycode = 0;
        for(int i = 0; i<pow(2,n);i++){
            graycode = i>>1^i;
            result.push_back(graycode);
        }
        return result;
    }
};