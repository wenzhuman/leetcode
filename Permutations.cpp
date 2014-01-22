class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > result = permuteHelper(0,num);
        result.push_back(num);
        return result;
    }
    vector<vector<int> > permuteHelper(int pos,vector<int> &num){
        vector<vector<int> >result;
        
        for(int j = pos;j<num.size();j++){
            swap(num[pos],num[j]);
            if(pos!=j){
                result.push_back(num);
            }
            vector<vector<int> > result1 = permuteHelper(pos+1,num);
            result.insert(result.end(),result1.begin(),result1.end());
            swap(num[pos],num[j]);
        }
        return result;
    }
};