class Solution {
public:
    string intToRoman(int num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.    
        /*map<char,int> romanMap;
        romanMap['I'] = 1;
        romanMap['V'] = 5;
        romanMap['X'] = 10;
        romanMap['L'] = 50;
        romanMap['C'] = 100;
        romanMap['D'] = 500;
        romanMap['M'] = 1000;*/
        //use unordered map to keep track of the insertion order
        map<int,char> intToRoman;
        intToRoman[1000] = 'M';
        intToRoman[500] = 'D';
        intToRoman[100] = 'C';
        intToRoman[50] = 'L';
        intToRoman[10] = 'X';
        intToRoman[5] = 'V';
        intToRoman[1] = 'I';
        string result;
        for(map<int,char>::reverse_iterator it = intToRoman.rbegin();it!=intToRoman.rend();it++){
            while(num/(it->first)){
                result.push_back(it->second);
                num = num-(it->first);
            }
            map<int,char>::reverse_iterator itahead = it ;
            advance(itahead,1);
            while(itahead!=intToRoman.rend()){
                if((itahead->first==it->first/10)|(itahead->first==it->first/5)){
                    if((itahead->first)+num>=it->first){
                        result.push_back(itahead->second);
                        result.push_back(it->second);
                        num +=itahead->first;
                        num -=it->first;
                    }
                }
                advance(itahead,1);
                if(itahead!=intToRoman.rend()&&(itahead->first!=it->first/10)&&(itahead->first!=it->first/5)) break;
            }
        }
        return result;
        
    }
};