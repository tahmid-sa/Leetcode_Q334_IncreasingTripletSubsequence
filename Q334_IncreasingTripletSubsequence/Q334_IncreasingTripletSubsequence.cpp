#include <iostream>
#include <vector>
#include <utility>

using namespace std;

bool increasingTriplet(vector<int>& nums) {
    int n = nums.size();
    int i;

    vector<int> pre(n, 0), suff(n, 0);
    pre[0] = nums[0];

    for (i = 1; i < n; i++) {
        pre[i] = min(pre[i - 1], nums[i]);
    }

    suff[n - 1] = nums[n - 1];
    for (i = n - 2; i >= 0; i--) {
        suff[i] = max(suff[i + 1], nums[i]);
    }

    for (i = 1; i < n - 1; i++) {
        if (nums[i] > pre[i - 1] && nums[i] < suff[i + 1]) {
            return true;
        }
    }

    return false;
}

int main()
{
    vector<int> nums = { 5, 4, 3, 2, 1 };
    cout << increasingTriplet(nums) << endl;

    return 0;
}
