class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //Insert the newInterval
        vector<vector<int>> temp;
        bool insert = false;    
        for(int i = 0; i < intervals.size(); i++){
            if(insert == false && intervals[i][0] >= newInterval[0]){
                temp.push_back(newInterval);
                insert = true;
            }
            temp.push_back(intervals[i]);
            
        }
        if(insert == false){
            temp.push_back(newInterval);
        }
        
        //Merge the overlapping intervals
        vector<vector<int>> res;
        int n = temp.size();
        int start1 = temp[0][0];
        int end1 = temp[0][1];
        for(int i = 1; i < n; i++){
            int start2 = temp[i][0];
            int end2 = temp[i][1];

            if(end1 >= start2){  //Overlapping intervals: update end1
                start1 = start1;
                end1 = max(end1, end2);
                continue;
            }
            res.push_back({start1, end1});  //Non-overlapping: push current merged interval to res
            start1 = start2;
            end1 = end2;

        }
        // Push the last merged interval
        res.push_back({start1, end1});
        return res;
        
    }
};
