/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool sortIntervalFunction (Interval interval1,Interval interval2) { 
        return (interval1.start<interval2.start); 
    }
    
class Solution {
public:
    
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.empty()) return intervals;
        sort(intervals.begin(),intervals.end(),sortIntervalFunction);
        vector<Interval> results;
        results.push_back(intervals[0]);
        for(int i = 1;i<intervals.size();i++){
            int start = intervals[i].start;
            int end = intervals[i].end;
            int startPos = -1, endPos = -1;
            for(int k = 0;k<results.size();k++){
             
                if(results[k].start<=start&&results[k].end>=start){
                    startPos = k;
                    results[k].end = max(end,results[k].end);
                }
                
                if(results[k].start<=end&&results[k].end>=end){
                    endPos = k;
                    results[k].start = min(start,results[k].start);
                } 
                if(results[k].start>end){
                    break;  
                } 
            }
            if(startPos<0&&endPos<0){
                results.push_back(intervals[i]);
            }
        }
        return results;
    }
    
};