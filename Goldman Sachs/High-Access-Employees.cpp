class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
vector<string> ans;
        int newminute=0,newhour;
        unordered_map<string,vector<int>>m;
        for(auto i:access_times)
        {
            m[i[0]].push_back(stoi(i[1]));
        }
        for(auto i:m)
        {
             sort(i.second.begin(),i.second.end());
            for(int j =0;j<i.second.size();j++)
            {
                int minute = i.second[j]%100;
                i.second[j] = i.second[j]/100;
                int hour = i.second[j]%100;
                if(minute==0){
                 newminute  = 59;
                newhour = hour;
                }else
                {
                    newminute = minute - 1;
                    newhour=hour+1;
                }
                int p = newhour*100+ newminute;
                cout<<p<<endl;
                if(j+2<=i.second.size()-1 &&i.second[j+1]<=p && i.second[j+2]<=p)
                {
                    ans.push_back(i.first);
                    break;
                }
                  
            }
        }
        return ans;
    }
};
// 3 or more time access within hr
// sorting and hashing 
// difference should be max 99 
// sorting based on time and use hashmap to track no. of time accessed

