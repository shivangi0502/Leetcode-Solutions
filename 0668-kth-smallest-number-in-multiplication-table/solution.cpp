class Solution {
public:

    int help(int m, int n, int guess){
        int count = 0;
        for(int i=1;i<=m;i++){
            count+=min(guess/i,n);
        }
        return count;
    }

    int findKthNumber(int m, int n, int k) {
        
        
        int low = 1;
        int high = m*n;
        int res = -1;
        while(low<=high){
            int guess = low+(high-low)/2;
            int ans = help(m,n,guess);
            if(ans>=k){
                res = guess;
                high = guess-1;
            }
            else{
                low =  guess+1;
            }
        }
        return res;
    }
};
