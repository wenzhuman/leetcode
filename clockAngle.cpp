#include<iostream>
using namespace std;
int narrowTheAbsoluteAngle(int angle);
int angleBetweenHands(string a) {
    const int AnglePerHour = 30;
    const int AnglePerMinute = 6;
    
    string hourStr = a.substr(0,3);
    int hour = atoi(hourStr.c_str());
    
    hour = hour%12;
    cout<<hour<<endl;
    string minutesStr = a.substr(3,6);
    int minutes = atoi(minutesStr.c_str());
    
    int absoluteHourAngle = hour*AnglePerHour;
    
    int absoluteMinuteAngle = minutes*AnglePerMinute;
    return narrowTheAbsoluteAngle(abs(absoluteMinuteAngle-absoluteHourAngle));

}
int narrowTheAbsoluteAngle(int angle){
    cout<<angle<<endl;
    if(angle<=180) return angle;
    else return 360-angle;
}
int main(){
    cout<<angleBetweenHands("01:23")<<endl;
    cout<<angleBetweenHands("12:23")<<endl;
}