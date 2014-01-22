class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        map<int,int> intGroup;
        int groupIndex = 0;
        
        for(int integer : num){
            bool intMinus = false, intAdd = false;
            if(intGroup.find(integer-1)!=intGroup.end()){
                intMinus = true;
            }
            if(intGroup.find(integer+1)!=intGroup.end()){
                intAdd = true;
            }
             
            if(intMinus&&intAdd){
                 intGroup[integer] = intGroup[integer-1];
                 if(intGroup[integer-1]!=intGroup[integer+1]){
                    mergeTwoGroups(intGroup,integer-1,integer+1);
                 }
            }
            else if(intMinus){
                intGroup[integer] = intGroup[integer-1]; 
            }
            else if(intAdd){
                intGroup[integer] = intGroup[integer+1];
            }
            else{
                intGroup[integer] = groupIndex;
                groupIndex++;
            }
        }
        
        return findMaxGroups(intGroup, groupIndex);
    }
    void mergeTwoGroups(map<int,int> &intGroup,int int1,int int2){
        int newGroup = intGroup[int1];
        int oldGroup = intGroup[int2];
        for(auto it = intGroup.begin();it!=intGroup.end();it++){
            if(it->second == oldGroup){
                it->second = newGroup;
            }
        }
    }
    int findMaxGroups(map<int,int> &intGroup,int groupIndex){
        int groupElementsNum[groupIndex];
        
        for(int i = 0; i<groupIndex; i++){
            groupElementsNum[i]=0;
            
        }
        
        for(auto it = intGroup.begin();it!=intGroup.end();it++){
            int groupNum = it->second;
            groupElementsNum[groupNum]++;
        }
        
        int max = 1;
        for(int i = 0;i<groupIndex;i++){
            if(groupElementsNum[i]>max){
                max = groupElementsNum[i];
            }
        }
        return max;
    }
};