class Solution {
public:
    int fun(int n, vector<int>& res){
        if(n==0) return 1;
        if(n==1) return 1;
        if(res[n]!=-1) return res[n];
        int ans1 = fun(n-1,res);
        int ans2 = fun(n-2, res);
        res[n] = ans1+ans2;
        return res[n];
    }

    int climbStairs(int n) {
        vector<int> res(n+1,-1);
        return fun(n,res);
    }
};
