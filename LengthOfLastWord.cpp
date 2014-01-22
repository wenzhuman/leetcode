class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int length = 0 ;
        bool start = false;
        for(int i = 0;s[i]!=NULL;i++){
            if(s[i]!=' '){
                
                if(!start) {length++;}
                else {
                    length = 1;start=false;
                }
                
            }
            else{
                start = true;
            }
        }
        return length;
    }
};