class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string>> stringMap;
        vector<string> anagrams;
        for(string str:strs){
            string key = str;
            sort(key.begin(),key.end());
            stringMap[key].push_back(str);
        }
        for(multimap<string, vector<string>>::iterator it = stringMap.begin();it!=stringMap.end();it++){
            if(it->second.size()>1){
                for(auto ele:it->second){
                    anagrams.push_back(ele);
                }
            }
        }
        return anagrams;
    }
    
};