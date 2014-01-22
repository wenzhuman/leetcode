class Solution {
public:
    int romanToInt(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        map<char,int> romanMap;//bug: change map<string,int> to <char,int>
        romanMap['I'] = 1;//bug:change "I" to 'I' string to char
        romanMap['V'] = 5;
        romanMap['X'] = 10;
        romanMap['L'] = 50;
        romanMap['C'] = 100;
        romanMap['D'] = 500;
        romanMap['M'] = 1000;
        int result = 0;
        for(int i = 0;i<s.length()-1;i++){
            if(romanMap[s[i+1]]>romanMap[s[i]]){
                result -= romanMap[s[i]];
                
            }
            else result += romanMap[s[i]];
        }
        result += romanMap[s[s.length()-1]];
        return result;
    }
};