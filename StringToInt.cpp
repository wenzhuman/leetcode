class Solution {
public:
    int atoi(const char *str) {
        if(!(*str)) return 0;
        int result = 0;
        bool isPlus = true;
        while(isspace(*str)){
            str++;
        }
        if(*str == '-'){
            isPlus = false;
            str++;
        }
        if(*str == '+'){
            str++;
        }
        while(isdigit(*str)){
            int oldResult = result;
            int charToInt = *str-48;
            if(isPlus){
                if(oldResult>INT_MAX/10|((oldResult==INT_MAX/10)&&charToInt>7)){
                    return INT_MAX;
                }
            }
            else{
                if(oldResult>INT_MAX/10|((oldResult==INT_MAX/10)&&charToInt>8)){
                    return INT_MIN;
                }
            }
            result = result*10+(charToInt);
            str++;
        }
            
        if(!isPlus){
            return result*(-1);
        }
        return result;
    }
};