/*
128. Longest Consecutive Sequence
Solved
Medium
Topics
Companies
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;
        for (int i : nums)
            mp[i]++;

        int ans = 0, cnt = 0, diff = 1;
        for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
            if (next(itr) != mp.end() && next(itr)->first - itr->first == diff)
                cnt++;
            else {
                ans = max(ans, cnt + 1);
                cnt = 0;
            }
        }
        return ans;
    }
};


//optimal code 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Sort the vector
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());

        int ans = 1, cnt = 0, n = nums.size();

        // Iterate through the sorted vector
        for (int i = 1; i < n; i++) {
            // If the current element is consecutive to the previous one, increment the count
            if (nums[i] - nums[i-1] == 0) continue;
            else if (nums[i] - nums[i-1] == 1) cnt++;
            else {
                // If the consecutive sequence breaks, update the answer and reset the count
                ans = max(ans, cnt + 1);
                cnt = 0;
            }
        }

        // Update the answer with the final count
        ans = max(ans, cnt + 1);
        return ans;
    }
};
