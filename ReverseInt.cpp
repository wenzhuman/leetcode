class Solution {
public:
    int reverse(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int left = 0,rest = 0;
        int newX = 0;
        if(x == 0) return 0;
        else while(x)
        {
            left = x%10;
            x /=10;
            newX = newX*10+left;
        }
        return newX;
    }
};