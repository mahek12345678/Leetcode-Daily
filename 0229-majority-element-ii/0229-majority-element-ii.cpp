class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1= nums.size()/3;
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int limit= nums.size()/3;
        for(auto it:mp){
            if(it.second > limit){
                ans.push_back(it.first);
            }
        }
        return ans;
        
    }
};