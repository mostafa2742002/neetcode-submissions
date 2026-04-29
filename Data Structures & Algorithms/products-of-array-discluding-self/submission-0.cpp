class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> pre(n+1,1), post(n+1,1);
        

        pre[0] = nums[0];
        for(int i = 1 ; i < nums.size(); i++){
            pre[i] = pre[i-1] * nums[i];
        }   

        post[n-1] = nums[n-1];
        for(int i = n - 2; i >= 0 ; i--){
            post[i] =  post[i+1] * nums[i];
        }

        nums[0] = post[1];
        nums[n-1] = pre[n-2];
        for(int i = 1 ; i < n -1 ; i++){
            nums[i] = pre[i-1] * post[i+1];
        }   

        return nums;
    }
};
