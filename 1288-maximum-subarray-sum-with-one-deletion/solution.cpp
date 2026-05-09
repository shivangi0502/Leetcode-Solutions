class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int no_delete = arr[0];
        int one_delete = INT_MIN;
        int res = arr[0];
        for(int i=1;i<n;i++){
            int prev_no_delete = no_delete;
            int prev_one_delete = one_delete;
            no_delete = max(no_delete+arr[i],arr[i]);
            int v2;
            if(prev_one_delete==INT_MIN){
                v2 = arr[i];
            }
            else{
                v2 = prev_one_delete +arr[i];
            }
            one_delete = max(v2,prev_no_delete);
            res = max(res,max(one_delete,no_delete));
        }
        return res;
        
    }
};
