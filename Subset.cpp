class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        return calSubsets(S);
    }
    vector<vector<int> > calSubsets(vector<int> &S){
        vector<vector<int> > results;
        if(S.size()==0) {
            vector<int> result;
            result.clear();
            results.push_back(result);
        }
        else{
             vector<int> pre_vector = vector<int>(S.begin(),S.end()-1);
             vector<vector<int> > pre_results = calSubsets(pre_vector);
             int new_ele = S[S.size()-1];
             
             for(auto pre_result:pre_results){
                 results.push_back(pre_result);
                 vector<int> result(pre_result.begin(),pre_result.end());
                 result.push_back(new_ele);
                 results.push_back(result);
             }
        }
        return results;
    }
};