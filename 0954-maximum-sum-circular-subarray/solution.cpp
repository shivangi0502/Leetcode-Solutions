class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int min_res = nums[0];
        int res = nums[0];
        int best_ending_max = nums[0];
        int best_ending_min = nums[0];
        int sum =0;
        for(int i =0;i<n;i++){
            sum+=nums[i];
        }
        for(int i=1;i<n;i++){
            best_ending_max = max(best_ending_max+nums[i], nums[i]);
            res = max(res,best_ending_max);
            best_ending_min = min(best_ending_min+nums[i], nums[i]);
            min_res = min(min_res,best_ending_min);  
        }
        if(res<0){
            return res;
        }
        int circular_res = sum-min_res;
        return max(res,circular_res);
    }
};
