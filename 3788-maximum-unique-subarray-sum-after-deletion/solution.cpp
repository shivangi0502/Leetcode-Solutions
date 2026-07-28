class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        
        if (maxi <= 0) {
            return maxi;
        }

        unordered_set<int> f;
        int sum = 0;
        for (int num : nums) {
            if (num > 0 && !f.count(num)) {
                sum += num;
                f.insert(num);
            }
        }

        return sum;
    }
};
