class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int t = nums.size();
        int flag = 0 , sum = 0;
        for(int i = 0; i< t ; i++) flag += nums[i];
        for(int i = 0; i < t; i++)
        {
            if(sum == (flag - sum - nums[i])) return i;
            sum += nums[i];
        }
        return -1;
    }
};
