#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < (int)nums.size(); i++) {
            int need = target - nums[i];
            if (m.count(need)) return {m[need], i};
            m[nums[i]] = i;
        }
        return {};
    }
};