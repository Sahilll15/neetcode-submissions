#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        std::vector<int> ans;

        for (int i = 0; i < numbers.size(); i++) {
            for (int j = i + 1; j < numbers.size(); j++) {
                if (numbers[i] + numbers[j] == target) {
                    ans.push_back(i+1);
                    ans.push_back(j+1);
                    return ans;  
                }
            }
        }
        return ans;
    }
};
