#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int best = 0;

        for (int num : s) {
            if (s.count(num - 1)) continue;

            int len = 1;
            while (s.count(num + len)) len++;
            best = max(best, len);
        }
        return best;
    }
};