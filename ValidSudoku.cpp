#include<iostream>
#include<vector>
#include<array>
using namespace std;

    bool isValidSudoku(vector<vector<char> > &board) {
       array<bool,9> a;
        a.fill(false);
        for(int i = 0;i<9;i++){
             a.fill(false);
            
            for(int j = 0;j<9;j++){
                
                if(board[i][j]!='.'){
                int index = board[i][j] - '1';
                
                if(a[index] == true) {
                    return false;
                }
                a[index] = true;
                }
            }
        }
        a.fill(false);
        for(int k = 0;k<9;k=k+3){
             a.fill(false);
            for(int i = 0;i<3;i++){
                for(int j = 0;j<3;j++){
                    if(board[k+i][k+j]!='.'){
                    int index = board[k+i][k+j] - '1';
                    if(a[index] == true) {
                        return false;
                    }
                    a[index] = true;
                    }
                }
            }
        }
        a.fill(false);
        for(int j = 0;j<9;j++){
            a.fill(false);
            for(int i = 0;i<9;i++){
                if(board[i][j]!='.'){
                int index = board[i][j] - '1';
                if(a[index] == true) {
                    return false;
                }
                a[index] = true;
                }
            }
        }
        return true;
    };
int main(){
   // int a[9] = 
    char a1[] = {'.','8','7','6','5','4','3','2','1'};
    vector<char> v1(a1, a1 + sizeof(a1) / sizeof(char));
    char a2[] ={'2','.','.','.','.','.','.','.','.'};
    vector<char> v2(a2, a2 + sizeof(a2) / sizeof(char));
    char a3[] ={'3','.','.','.','.','.','.','.','.'};
    vector<char> v3(a3, a3 + sizeof(a3) / sizeof(char));

    char a4[] ={'4','.','.','.','.','.','.','.','.'};
    vector<char> v4(a4, a4 + sizeof(a4) / sizeof(char));
    char a5[] = {'5','.','.','.','.','.','.','.','.'};
    vector<char> v5(a5, a5 + sizeof(a5) / sizeof(char));
    char a6[] ={'6','.','.','.','.','.','.','.','.'};

    vector<char> v6(a6, a6 + sizeof(a6) / sizeof(char));

    char a7[] = {'7','.','.','.','.','.','.','.','.'};
    vector<char> v7(a7, a7 + sizeof(a7) / sizeof(char));
    char a8[] = {'8','.','.','.','.','.','.','.','.'};
    vector<char> v8(a8, a8 + sizeof(a8) / sizeof(char));
    char a9[] = {'9','.','.','.','.','.','.','.','.'};
    vector<char> v9(a9, a9 + sizeof(a9) / sizeof(char));
    vector<vector<char> > v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);
    v.push_back(v6);
    v.push_back(v7);
    v.push_back(v8);
    v.push_back(v9);
    cout<<isValidSudoku(v)<<endl;

}