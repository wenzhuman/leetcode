class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int size = digits.size();
        int pos = size-1;

        digits[pos]+=1;
        
        while(digits[pos] == 10&&pos>0){
            digits[pos] = 0;
            pos--;
            digits[pos]+=1;
        }
        if(digits[pos]==10){
            digits[pos] = 0;
            vector<int> newDigits(1,1);
            for(auto ele:digits){
                newDigits.push_back(ele);
            }
            return newDigits;
        }
        return digits;
    }
};