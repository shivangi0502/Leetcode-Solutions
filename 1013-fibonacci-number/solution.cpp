class Solution {
public:
    int fib(int n) {
        
        if(n==0) return 0; //base case
        if(n==1) return 1; 
        int ans1 = fib(n-1); //trust
        int ans2 = fib(n-2);
        return ans1+ans2; //combine
    }
};
