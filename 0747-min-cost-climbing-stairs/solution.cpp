class Solution {
public:

    int fun(vector<int>& cost, int n, vector<int>& memo){
        if(n>=cost.size()) return 0;
        if(memo[n]!=-1) return memo[n];
        int ans1 = cost[n] + fun(cost,n+1,memo);
        int ans2 = cost[n] + fun(cost,n+2,memo);
        memo[n] =  min(ans1,ans2);
        return memo[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n,-1);
        int res1 = fun(cost,0,memo);
        int res2 = fun(cost,1,memo);
        return min(res1,res2);

    }
};
