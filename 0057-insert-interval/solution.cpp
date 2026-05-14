class Solution {
public:
    vector<vector<int>> merge_intervals(vector<vector<int>>& res){
        
        int n = res.size();
        vector<vector<int>> res2;
        int start1 = res[0][0];
        int end1 = res[0][1];
        for(int i=1;i<n;i++){
            int start2 = res[i][0];
            int end2 = res[i][1];
            //merge condition check
            if(end1>=start2){
                start1 = start1;
                end1 = max(end1,end2);
                continue;
            }
            res2.push_back({start1,end1});
            start1 = start2;
            end1 = end2;
        }
        res2.push_back({start1,end1});
        return res2;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool inserted = false;
        int n = intervals.size();
        if(n==0){
            res.push_back(newInterval);
            return res;
        }
        
        for(int i=0;i<n;i++){
            
            if(inserted == false && intervals[i][0]>newInterval[0]){
                res.push_back(newInterval);
                inserted = true;
            }
            res.push_back(intervals[i]);
            
        }
        if(inserted==false){
            res.push_back(newInterval);
            inserted = true;
        }
        res = merge_intervals(res);
        return res;
        
    }
};
