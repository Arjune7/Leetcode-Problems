class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>ch;
        int curr_sum = 0;
        int count = 0;
        ch[0] = 1;
        
        for(int i = 0; i < nums.size(); i++){
            curr_sum+=nums[i];
            
            int res = curr_sum % k;
            if(res < 0)
                res+=k;
            
            if(ch.find(res)!=ch.end())
                count+=ch[res];
            
            ch[res]++;
        }
        return count;
    }
};