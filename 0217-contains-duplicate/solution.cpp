class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> f;
        for(int num:nums){
            if(f.count(num)) return true;
            f.insert(num);
        }
        return false;
    }
};
