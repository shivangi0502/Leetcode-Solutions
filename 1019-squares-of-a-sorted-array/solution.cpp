class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> neg;
        vector<int> pos;
        // formed 2 arrayas for negative and positive elements
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
            }
        }
        //only positive elements are present
        if(neg.size()==0){
            for(int i=0;i<pos.size();i++){
                pos[i]=pos[i]*pos[i];
            }
            return pos;
        }
        //only negative elements are present
        if(pos.size()==0){
            for(int i=0;i<neg.size();i++){
                neg[i]=neg[i]*neg[i];
                
            }
            reverse(neg.begin(),neg.end());
            return neg;
        }
        //both negative and positive are present
        int i =0, j=0, id =0;
        int n = neg.size();
        int m = pos.size();
        vector<int> res(n+m);
        for(int i =0;i<n;i++){
            neg[i] = neg[i]*neg[i];
        }
        reverse(neg.begin(), neg.end());

        for(int i=0; i<m;i++){
            pos[i]= pos[i]*pos[i];
        }

        while(i<n && j<m){
            if(neg[i]<=pos[j]){
                res[id]=neg[i];
                id++; i++;
            }
            else{
                res[id]=pos[j];
                id++; j++;
            }
        }
        //only positive elemnts remaining
        while(i<n){
            res[id] = neg[i];
            id++; i++;
        }
        while(j<m){
            res[id] = pos[j];
            id++; j++;
        }
        return res;
        
    }
};
