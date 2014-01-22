class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0,j=s.size()-1;i<j;i++,j--){
            while(!isalpha(s[i])&&!isdigit(s[i])){
                i++;
                if(i>=j) return true;
            }
             while(!isalpha(s[j])&&!isdigit(s[j])){
                j--;
                if(i>=j) return true;
            }
            if(isupper(s[i])) s[i] = tolower(s[i]);
            if(isupper(s[j])) s[j] = tolower(s[j]);
            if((s[i]!=s[j])) return false;
        }
        return true;
    }
};