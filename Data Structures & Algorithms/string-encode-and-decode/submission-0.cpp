class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(int i = 0 ; i < strs.size(); i++){
            int s = strs[i].size();
            string n = to_string(s) + "_" + strs[i];
            res = res + n;
        }

        return res;
    }

    vector<string> decode(string s) {
        if(s.size() == 0){
            return {};
        }

        vector<string> res;

        for(int i = 0 ; i < s.size(); i++){
            int j = i;
            for(; j < s.size(); j++){
                if(s[j] == '_')break;
            }

            int siz = stoi(s.substr(i,j));
            string new_str = s.substr(j+1,siz);
            res.push_back(new_str);
            i = j+siz;
            
        }

        return res;
    }
};
