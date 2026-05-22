class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;

        for(int i=0;i<nums.size();i++){
            if(map.count(nums[i])) return true;
            map[nums[i]]++;
        }

        return false;
    }
};