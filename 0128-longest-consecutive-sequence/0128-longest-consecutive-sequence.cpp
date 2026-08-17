class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxlen= 1;
        int len=1;
        if(nums.size() == 0){
            return 0;
        }

        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1] + 1 ){
                len++;
                maxlen = max(len, maxlen);
            }
            else if(nums[i] == nums[i-1]){
                continue;
            }

            else{
                len=1;
            }
        }
        return maxlen;
        
    }
};