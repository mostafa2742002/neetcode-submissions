class Solution {
public:
    static bool valid(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;

        for(int i = 0 ; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        vector<pair<int,int>> n;

        for(auto &i: mp){
            n.push_back({i.first,i.second});
        }

        sort(n.begin(), n.end(), valid);

        vector<int>res;

        for(int i = 0 ; i < k ; i++){
            res.push_back(n[i].first);
        }

        return res;

    }
};