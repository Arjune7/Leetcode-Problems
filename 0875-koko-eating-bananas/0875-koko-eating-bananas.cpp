class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 1;
        for(int p : piles){
            high = max(high,p);
        }

        while(low < high){
            int mid = (low+high)/2;
            int total = 0;
            for(int p : piles){
                total += (p+mid-1) / mid;
            }
            if(total > h)
                low = mid + 1;
            else
                high = mid;
        }

        return high;
    }
};