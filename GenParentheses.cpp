class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string parenthesis = "";
        genParenthesisLeftAndRight(n, n, parenthesis, result);
        return result;
        
    }
   void genParenthesisLeftAndRight(int left,int right,string parenthesis,vector<string> &result){
        if(right == 0){

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
};