 #include<iostream>
 #include<vector>
using namespace std;
void sumFirstOper(vector<string> &tokens);
 int evalRPN(vector<string> &tokens) {
        while(tokens.size()!=1){
            cout<<"size"<<tokens.size()<<endl;
            sumFirstOper(tokens);
        }
        int result = atoi(tokens[0].c_str());
        return result;
    }
    void sumFirstOper(vector<string> &tokens){
        for(int i = 0; i<tokens.size(); i++){
            
            if(tokens[i] == "+"|tokens[i] == "-"|tokens[i] == "*"|tokens[i] == "/"){
                int result = 0 ;
                int op1 = atoi(tokens[i-2].c_str());
                int op2 = atoi(tokens[i-1].c_str());
                cout<<op1<<op2<<endl;
                    if(tokens[i]=="+"){
                        result = op1 + op2;
                    }
                    if(tokens[i]=="-"){
                        result = op1 - op2;
                    }
                    if(tokens[i]=="*"){
                        result = op1 * op2;
                    }
                    if(tokens[i]=="/"){
                        result = op1 / op2;
                    }
                
                tokens[i-2] = std::to_string(result);
                tokens.erase(tokens.begin()+i-1, tokens.begin()+i+1);
                for(string s:tokens){
                    cout<<s<<endl;
                }
                return;
            }
            
        }
    }
    int main(){
        vector<string> tokens;
        tokens.push_back("0");
        tokens.push_back("3");
        tokens.push_back("/");
        cout<<evalRPN(tokens);

    }