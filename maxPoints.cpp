/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    struct Line
    {
        int a;
        int b;
        int c;
        Line():a(0),b(0),z(0){}
        Line(int x, int y, int z):a(x),b(y),z(c){}
    };
    int maxPoints(vector<Point> &points) {
        
    }

    Line computerLine(Point A, Point B){
       // Ax+By+C = 0
        int a = A.y - B.y;
        int b = B.x - A.x;
        int c = -a*A.x-b*A.y;
        int gcd =  GCD(GCD(a,b),GCD(a,b));
        //normalize the positive and negative
        if(a<0){
            a = -a;
            b = -b;
            c = -b;
        }
    }

    int GCD(int a, int b){
        if(a<b){
            int temp = b;
            b = a;
            a = temp;
        }
        int minus = a - b;
        while(minus>b){
            minus = minus - b;
        }
        if(minus!=0){
            return GCD(b, minus);
        }
        else{
            return b;
        }
    }
};