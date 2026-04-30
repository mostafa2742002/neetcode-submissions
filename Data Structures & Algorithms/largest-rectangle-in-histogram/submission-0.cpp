class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int>pre(n,-1),post(n,-1);

        stack<pair<int,int>>st;

        for(int i = n - 1 ; i >= 0 ; i--){
            if(st.empty()){
                st.push({heights[i],i});
                continue;
            }

            while(!st.empty() && heights[i] <= st.top().first) st.pop();

            if(!st.empty())post[i] = st.top().second;
            st.push({heights[i],i});
        }

        st = {};

        for(int i = 0 ; i < n ; i++){
            if(st.empty()){
                st.push({heights[i],i});
                continue;
            }

            while(!st.empty() && heights[i] <= st.top().first) st.pop();

            if(!st.empty()) pre[i] = st.top().second;
            st.push({heights[i],i});
        }

        int res = 0;

        for(int i = 0 ; i < n ; i ++){
            int pr  = (pre[i] == -1 ? 0 : pre[i] + 1);
            int po = (post[i] == -1 ? n - 1  : post[i] - 1);

            int r = abs(pr - po) + 1;
            cout << pr << " " << po << " " << r << " " << heights[i] * r << endl;
            res = max(res , (heights[i] * r));
        }

        return res;

    }
};
