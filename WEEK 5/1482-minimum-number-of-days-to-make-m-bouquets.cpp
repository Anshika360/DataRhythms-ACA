class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int flowers = 0;

        for(int bloom : bloomDay) {
            if(bloom <= day) {
                flowers++;

                if(flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowers = 1LL * m * k;

        if(totalFlowers > bloomDay.size())
            return -1;

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        while(left < right) {
            int mid = left + (right - left) / 2;

            if(canMake(bloomDay, m, k, mid))
                right = mid;      // try fewer days
            else
                left = mid + 1;   // need more days
        }

        return left;
    }
};