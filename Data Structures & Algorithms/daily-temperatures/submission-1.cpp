class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        stack<pair<int,int>>st;
        int n = tem.size();
        vector<int>res(n,0);
        for(int i = n-1 ; i >= 0 ; i--){
            if(st.empty()){st.push({tem[i],i}); continue;}

            while(!st.empty() && tem[i] >= st.top().first){
                st.pop();
            }

            if(st.empty()) {st.push({tem[i],i}); continue;}

            res[i] = st.top().second - i;

            if(st.empty() || tem[i] < st.top().first){
                st.push({tem[i],i});
            }
        }

        return res;
    }
};
