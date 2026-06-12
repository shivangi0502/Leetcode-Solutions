class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> a(n);
        for(int i=0;i<times.size();i++){
            int s = times[i][0];
            int d = times[i][1];
            int w = times[i][2];
            a[s-1].push_back({d-1,w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> res(n,INT_MAX);
        res[k-1] = 0;
        pq.push({0,k-1});
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            int time = p.first;
            int node = p.second;
            if(time>res[node]){
                continue;
            }
            for(int j = 0;j<a[node].size();j++){
                int neigh = a[node][j].first;
                int wt = a[node][j].second;
                if(time+wt<res[neigh]){
                    res[neigh] = time+wt;
                    pq.push({time+wt,neigh});
                }
            }
        }
        int ans = *max_element(res.begin(),res.end());
        if(ans==INT_MAX) return {-1};
        return ans;
    }
};
