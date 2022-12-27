class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        int n = capacity.size();
        int m = rocks.size();
        int ans = 0;

        vector<int> diff;
        for (int i = 0; i < n; i++)
            diff.push_back(capacity[i] - rocks[i]);

        sort(diff.begin(), diff.end());

        for (int i = 0; i < n; i++)
        {
            if (additionalRocks >= diff[i])
            {
                additionalRocks -= diff[i];
                diff[i] = 0;
                ans++;
            }
        }

        return ans;
    }
};