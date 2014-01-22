#include<iostream>
#include<vector>
using namespace std;
 void rotate(vector<vector<int> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = matrix.size();
        //cout<<n<<endl;
        for(int i = 0;i < n/2;i++){
            for(int j = 0; j <= n/2;j++){
                //cout<<matrix[i][j]<<"\t"<<matrix[n-1-j][i]<<endl;
                //cout<<i<<"\t"<<j<<"\t"<<n-1-j<<"\t"<<n-1-i<<endl;
                //cout<<matrix[2][2];
                swap(matrix[i][j],matrix[n-1-j][i]);
                swap(matrix[j][n-1-i],matrix[n-1-j][i]);
                swap(matrix[n-1-i][n-1-j],matrix[n-1-j][i]);
            }
        }   
    }
int main(){
    vector<vector<int> > matrix;
    vector<int>v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    matrix.push_back(v1);

    vector<int>v2;
    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);
    matrix.push_back(v2);
    
    vector<int>v3;
    v3.push_back(7);
    v3.push_back(8);
    v3.push_back(9);
    matrix.push_back(v3);
    
    for(auto row:matrix){
        for (auto ele:row){
            cout<<ele<<endl;
        }
    }
    rotate(matrix);
    for(auto row:matrix){
        for (auto ele:row){
            cout<<ele<<endl;
        }
    }
}