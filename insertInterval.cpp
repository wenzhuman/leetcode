/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int beginIndex = -2,endIndex = -2;
        int first = false, second = false;
        for(int i = 0; i<intervals.size();i++){
            if(newInterval.start >= intervals[i].start&&newInterval.start <= intervals[i].end){
               beginIndex = i; 
               break;
            }
            if(newInterval.start < intervals[i].start){
               beginIndex = i;
               break;
            }
        
        }

        for(int i = 0; i<intervals.size();i++){
            if(newInterval.end >= intervals[i].start&&newInterval.end <= intervals[i].end){
               endIndex = i; 
               break;
            }
            if(newInterval.end < intervals[i].start){
               endIndex = i-1; 
               break;
            }
        }
        //cout<<"begin"<<beginIndex<<endl;
        //cout<<"end"<<endIndex<<endl;
        mergeIntervals(intervals,beginIndex,endIndex,newInterval);
        return intervals;
    }

    void mergeIntervals(vector<Interval> &intervals,int beginIndex,int endIndex,Interval newInterval){
        //cout<<"merge"<<endl;

        if(endIndex==-1){
            intervals.insert(intervals.begin(),newInterval);
            return;
        }
        
        if(endIndex==-2&&beginIndex>=0){
            if(beginIndex+1<intervals.size()){
                intervals.erase(intervals.begin()+beginIndex+1,intervals.end());
            }
            if(intervals[beginIndex].start>newInterval.start){
                intervals[beginIndex].start = newInterval.start;
            }
            if(intervals[beginIndex].end < newInterval.end){
                intervals[beginIndex].end = newInterval.end;
            }
            //cout<<"merge end"<<endl;
            return;
        }

        if(beginIndex==-2){
            intervals.insert(intervals.end(),newInterval);
            return;
        }
        
        if(beginIndex < endIndex){
            if(intervals[beginIndex].end<intervals[endIndex].end){
                intervals[beginIndex].end = intervals[endIndex].end;
                if(intervals[beginIndex].end< newInterval.end){
                intervals[beginIndex].end = newInterval.end;
                }
            }
            
            if(intervals[beginIndex].start>newInterval.start){
                intervals[beginIndex].start = newInterval.start;
            }
            
            if(beginIndex+1<intervals.size()){
                intervals.erase(intervals.begin()+beginIndex+1,intervals.begin()+endIndex+1);
            }
            //cout<<"merge end"<<endl;
            return;
        }
        if(beginIndex>endIndex){
            intervals.insert(intervals.begin()+beginIndex,newInterval);
        }
        if(beginIndex == endIndex){
            if(intervals[beginIndex].start > newInterval.start){
                intervals[beginIndex].start = newInterval.start;
            }
            if(intervals[beginIndex].end < newInterval.end){
                intervals[beginIndex].end = newInterval.end;
            }
            
        }
        
    }
};