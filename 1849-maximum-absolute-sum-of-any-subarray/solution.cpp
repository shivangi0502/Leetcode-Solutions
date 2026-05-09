class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int best_ending_max = nums[0];
        int best_ending_min = nums[0];
        int res = abs(nums[0]);
        for(int i=1;i<n;i++){
            best_ending_max = max(best_ending_max + nums[i], nums[i]);
    
            best_ending_min = min(best_ending_min + nums[i],nums[i]);
            
            res = max({res,abs(best_ending_min),abs(best_ending_max)});

        }
        return res;
        
    }
};
