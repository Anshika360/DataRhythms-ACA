class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        int m = potions.size();
        vector<int> ans;

        for(int spell : spells) {
            long long required = (success + spell - 1) / spell;

            int left = 0, right = m - 1;
            int index = m;

            while(left <= right) {
                int mid = left + (right - left) / 2;

                if(potions[mid] >= required) {
                    index = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            ans.push_back(m - index);
        }

        return ans;
    }
};