class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string longestCommonPrefix;
        if(strs.empty()) return longestCommonPrefix;
        
        longestCommonPrefix = strs[0];
        
        int pos = strs[0].size();
        
        for(string str:strs){
            pos = pos<str.size()?pos:str.size();
            for(int i = 0;i<str.size();i++){
                if(str[i]!=longestCommonPrefix[i]){
                    pos = pos<i?pos:i; 
                    break;
                }
                
            }
        }
        longestCommonPrefix = longestCommonPrefix.substr(0,pos);
        return longestCommonPrefix;
    }
};