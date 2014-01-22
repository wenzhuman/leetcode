#include<iostream>
#include<string>
#include<vector>
using namespace std;
   void genParenthesisLeftAndRight(int left,int right,string parenthesis,vector<string> &result){
        if(right == 0){
            cout<<parenthesis<<endl;
            result.push_back(parenthesis); 
            return;
        }
        if(left > 0){

            genParenthesisLeftAndRight(left-1,right,parenthesis+'(',result);
        }
        if(left < right){

            genParenthesisLeftAndRight(left,right-1,parenthesis+')',result);
           
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string parenthesis = "";
        genParenthesisLeftAndRight(n, n, parenthesis, result);
        return result;
        
    }
    int main(){
        vector<string> r1;
        r1 = generateParenthesis(2);

        for(auto s : r1){
            cout<<s<<endl;
        }
    }