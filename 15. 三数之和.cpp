class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            if (i && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0)
                {
                    r--;
                    continue;
                }
                if (sum < 0)
                {
                    l++;
                    continue;
                }
                
                ans.push_back({nums[i], nums[l], nums[r]});

                do {l ++;} while(l < r && nums[l] == nums[l - 1]);
                do {r --;} while(l < r && nums[r] == nums[r + 1]);
            }
        }

        return ans;
    }
};
