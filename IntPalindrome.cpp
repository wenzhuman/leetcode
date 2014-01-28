class Solution {
public:
    bool isPalindrome(int x) {
        int divide = 10;
        if(x<0) return false;
        
        while(x/divide>9){
            divide = divide * 10;
        }
        while(x>=10){
            int tail = x%10;
            int begin = x/divide;
            if(tail!=begin) return false;
            x = x - begin*divide;
            x = x/10;
            divide = divide/100;
        }
        return true;
    }
};