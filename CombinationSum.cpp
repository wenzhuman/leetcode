    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;
    vector<vector<int> > res;
    void DFSCompute(int sum,vector<int> &candidates, vector<int>result,int target, int pos);

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> result;
        sort(candidates.begin(),candidates.end());
        //unique(candidates.begin(),candidates.end());
        DFSCompute(0, candidates, result, target,0);
        return res;
    }
    void DFSCompute(int sum,vector<int> &candidates, vector<int>result,int target,int pos){
        if(sum>target){

            return;
        }
        if(sum == target){
            cout<<"push in "<<sum<<endl;
            //sort(result.begin(),result.end());
            res.push_back(result);
            return;
        }
       
        else {
            int preValue = -1;
            while(pos<candidates.size()){
                //cout<<"loop"<<endl;

                int newValue = candidates[pos];
                cout<<"new"<<newValue<<endl;
                while(newValue == preValue){
                    pos++;
                    if(pos<candidates.size()){
                    newValue = candidates[pos];
                    }
                    else{
                        return;
                    }
                }
                    result.push_back(newValue);
                    pos++;
                    DFSCompute(sum + newValue, candidates, result, target,pos);
                
                preValue = result.back();
                
                result.pop_back();
            }
        }
    }
    /*vector<vector<int> > solution;
    void generateAll(vector<int> &candidates, vector<int> &count, int target, int depth);
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        solution.clear();
        vector<int> count(candidates.size(), 0);
        sort(candidates.begin(), candidates.end());
        unique(candidates.begin(), candidates.end());
        generateAll(candidates, count, target, 0);
        return solution;
    }
    
    void generateAll(vector<int> &candidates, vector<int> &count, int target, int depth) {
        if (target == 0) {
            vector<int> comb;
            for (int i = 0; i < depth; i++)
                for (int j = 0; j < count[i]; j++)
                    comb.push_back(candidates[i]);
            solution.push_back(comb);
        } else {
            if (depth == candidates.size()) return;
            for (int i = 0; i <= target / candidates[depth]; ++i) {
                count[depth] = i;
                generateAll(candidates, count, target - i * candidates[depth], depth + 1);
            }
        }
    }*/
    int main(){
        vector<int> candidates;
        candidates.push_back(2);
        candidates.push_back(4);
        candidates.push_back(1);
        candidates.push_back(5);
        candidates.push_back(5);
        candidates.push_back(4);
        candidates.push_back(1);
        candidates.push_back(2);
        candidates.push_back(4);
        vector<vector<int> > res = combinationSum(candidates,10);
        for(auto vec : res){
            for(auto ele : vec){
                cout<<ele<<"\t";
        }
        cout<<endl;
        }
    }