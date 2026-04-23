class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res_sum = 0;
        int max_diff = INT_MAX;
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int total = nums[i]+nums[j]+nums[k];
                int abs_diff = abs(total-target);
                
                if(abs_diff<max_diff){
                    max_diff = abs_diff;
                    res_sum = total;
                }
                if(total==target){
                    return res_sum;
                }
                if(total<target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return res_sum;
            
    }
};
