class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        if(nums.empty()) return 0;
        for(int i =1; i < (int)nums.size(); i++){
            if(nums[i]!= nums[i-1]){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};
