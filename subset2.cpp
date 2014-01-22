#include<iostream>
#include<vector>

using namespace std;
vector<vector<int> > calSubsets(vector<int> &S);
vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());

        return calSubsets(S);

             
    }
    vector<vector<int> > calSubsets(vector<int> &S){
        vector<vector<int> > results;
        bool isDup = false;
        if(S.size()==0) {
            vector<int> result;
            result.clear();
            results.push_back(result);
        }
        else{
             int new_ele = S[S.size()-1];
             vector<vector<int> > pre_results;
             vector<int> pre_vector = vector<int>(S.begin(),S.end()-1);
             pre_results = calSubsets(pre_vector);
             
             if(S.size()>1){
                 isDup = new_ele==S[S.size()-2]? true:false;
             }
             cout<<"isDup"<<isDup<<endl;
             int pos=0;
             for(vector<vector<int> >::iterator it = pre_results.begin();it!=pre_results.end();it++,pos++){
                 vector<int> pre_result = *it;
                 results.push_back(pre_result);
                 if(isDup&&pos/2){
                    vector<int> result(pre_result.begin(),pre_result.end());
                    result.push_back(new_ele);
                    cout<<"new"<<new_ele<<endl;
                    results.push_back(result);
                }
                 
             }
        }
        return results;
    }
int main(){
    int tmp[] = { 1,2,2};
    vector<int> v(tmp,tmp+3);
    vector<vector<int> > results = subsetsWithDup(v);
    for(auto v:results){
        cout<<"vec"<<endl;
        for(auto ele:v){
            cout<<ele<<endl;
        }
    }
}