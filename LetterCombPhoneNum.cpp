class Solution {
public:
    
    vector<string> letterCombinations(string digits) {
        map<char,string> phoneNumberLetters;
        phoneNumberLetters['2'] = "abc";
        phoneNumberLetters['3'] = "def";
        phoneNumberLetters['4'] = "ghi";
        phoneNumberLetters['5'] = "jkl";
        phoneNumberLetters['6'] = "mno";
        phoneNumberLetters['7'] = "pqrs";
        phoneNumberLetters['8'] = "tuv";
        phoneNumberLetters['9'] = "wxyz";
        return getCombination(digits, phoneNumberLetters, 0);

    }
    vector<string> getCombination(string digits, const map<char,string>& phoneNumberLetters,int pos){
        vector<string> results;
        if(pos==digits.size()){
            results.push_back("");
        }
        else {
            for(string s :getCombination(digits, phoneNumberLetters, pos+1)){
                for(char letter : phoneNumberLetters.at(digits[pos])){
                    results.push_back(letter+s);
                }
            }
        } 
        return results;
    }
};