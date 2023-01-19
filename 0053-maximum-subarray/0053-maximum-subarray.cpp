class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int curr_sum = 0;
        
        for(int i = 0 ; i < nums.size(); i++){
            curr_sum+=nums[i];
            if(curr_sum < 0){
               max_sum = max(curr_sum,max_sum);
               curr_sum = 0;
            }
            else
                max_sum = max(curr_sum,max_sum);
        }
        return max_sum;
    }
};