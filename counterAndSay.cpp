#include<iostream>
#include<string>
using namespace std;
string countRec(string input);
string countAndSay(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
          if(n == 1) return "1";
          
          int count = n;
          string s = "1";
          count--;
          
          while(count>0){
            s = countRec(s);
            count--;
          }
          return s;
    }
    string countRec(string input){
      cout<<"run"+input<<endl;
        string result;
        //if(n<1) return result;
        //string input = to_string(n);
        int counter =1;
        char curChar = input[0];
        for(char c : input){
          cout<<c<<endl;
            if(c!=curChar){
               result.push_back(counter+'0');
               result.push_back(curChar);
               counter = 1;
               curChar = c;
            }
            else{
                counter++;
            }
        }
        result.push_back(counter+'0');
        result.push_back(curChar);
        return result;
    }
  int main(){
    cout<<countAndSay(2)<<endl;
  }