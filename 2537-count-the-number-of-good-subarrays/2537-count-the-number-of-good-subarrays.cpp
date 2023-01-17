class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0;
        unordered_map<int,int>ch;

        for(int i = 0 , j = 0; i < nums.size(); i++){
            k-=ch[nums[i]]++;
            while(k<=0)
                k+=--ch[nums[j++]];
            res+=j;        
        }
        return res;
    }
};