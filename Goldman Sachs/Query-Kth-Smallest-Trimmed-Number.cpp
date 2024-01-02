    class Solution {
    public:
        vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
            int n=nums.size();
            int m = nums[0].size();
            vector<vector<pair<string,int>>>v(m+1,vector<pair<string,int>>(n));
            for (int i=1;i<=m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    v[i][j].first=nums[j].substr(m-i,i);
                    v[i][j].second=j;
                }
                sort(v[i].begin(),v[i].end());
            }
            vector <int>res;
            for(int i=0;i<queries.size();i++)
            {
                int k=queries[i][1];
                res.push_back(v[k][queries[i][0]-1].second);
            }
            return res;
        }
    };