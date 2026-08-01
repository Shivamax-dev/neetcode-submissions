class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res; //define a array of arrays

        int n = intervals.size();  //ex of intervals:[[1,3],[2,6],[8,10],[15,18]]

        sort(intervals.begin(), intervals.end()); //Soriting the given intervals. Sorted intervals: [[1,3],[2,6],[8,10],[15,18]]

        int start1 = intervals[0][0]; 
        int end1 = intervals[0][1];
    
        for(int i = 1; i < n; i++){
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            if(end1 >= start2){ //overlaping intervals so merge them
                start1 = start1;
                end1 = max(end1, end2);
                continue; //jb tk koi n koi overlapping aa rha hai
            }
            // push
            res.push_back({start1, end1});
            start1 = start2;
            end1 = end2;
        }
        
        res.push_back({start1, end1});
        return res;
        
    }
};
