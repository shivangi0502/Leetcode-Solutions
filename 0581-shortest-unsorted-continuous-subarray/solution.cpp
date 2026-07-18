class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int first = -1;
        int last = -1;
        int min_val = INT_MAX;
        int max_val=INT_MIN;
        for(int i=0;i<n;i++){
            max_val = max(max_val,nums[i]);
            if(nums[i]<max_val){
                last = i;
            }
        }
        for(int i=n-1;i>=0;i--){
            min_val = min(min_val,nums[i]);
            if(nums[i]>min_val){
                first = i;
            }
        }
        if(last==-1) return 0;
        return last-first+1;

    }
};
