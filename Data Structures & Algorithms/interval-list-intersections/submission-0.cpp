class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int m = firstList.size(), n = secondList.size();

        int i = 0, j = 0;
        while(i < m and j < n){
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];
            if(start1 <= start2){ //if pahle wale interval ka start dusre wale start ke interval se km hai to
                if(end1 >= start2){ //Ovelapping: find intersection interval
                    int s = start2; //max(start1, start2)
                    int e = min(end1, end2);
                    res.push_back({s,e});
                }
            }else{  //start2 <= start1
                if(end2 >= start1){  //Ovelapping: find intersection interval
                    int s = start1;
                    int e = min(end1, end2);
                    res.push_back({s,e});
                }
            }
            if(end1 <= end2){
                i++;
            }else{
                j++;    //if end2 <= end1 to j ko ek badha do
            }
        }
        return res;
        
    }
};