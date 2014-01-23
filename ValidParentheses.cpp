class Solution {
public:
    bool isValid(string s) {
        stack<char> parenthes;
        for(char parenth : s){
            if(parenth =='('|parenth =='{'|parenth =='['){
                parenthes.push(parenth);
            }
            if(parenth == ')'){
                if(!parenthes.empty()&&parenthes.top()=='(') parenthes.pop();
                else return false;
            }
            if(parenth == '}'){
                
                if(!parenthes.empty()&&parenthes.top()=='{') parenthes.pop();
                else return false;
            }
            if(parenth == ']'){
                if(!parenthes.empty()&&parenthes.top()=='[') parenthes.pop();
                else return false;
            }
            
        }
        if(!parenthes.empty()) return false;
        else return true;
    }
};