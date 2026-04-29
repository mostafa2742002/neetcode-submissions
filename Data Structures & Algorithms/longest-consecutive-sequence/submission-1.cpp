class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;

        sort(nums.begin(),nums.end());

        int res = 1, curr = 1;

        for(int i = 1 ; i < n ; i++){
            if( nums[i] - 1 != nums[i-1] ) {
                curr = (nums[i] == nums[i-1] ? curr : 1);
                continue;
            }

            curr++;
            res = max(curr, res);
            
        }

        return res;
    }
};
