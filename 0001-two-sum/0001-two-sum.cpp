#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numToIndex;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // If complement exists in map, we found the pair
            if (numToIndex.find(complement) != numToIndex.end()) {
                return {numToIndex[complement], i};
            }
            
            // Store current number and its index
            numToIndex[nums[i]] = i;
        }
        
        return {}; // No solution found (though problem guarantees one)
    }
};   