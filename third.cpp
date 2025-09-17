// Author: Saikat_deb | Created: 2025-09-17 21:26
#include <bits/stdc++.h>
using namespace std;

// 3sum
vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (i > 0 and nums[i] == nums[i - 1])
            continue;
        int j = i + 1, k = n - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k and nums[j] == nums[j - 1])
                    j++;
                while (j < k and nums[k] == nums[k + 1])
                    k--;
            } else if (sum < 0) {
                j++;
            } else {
                k--;
            }
        }
    }
    return ans;
}

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    unordered_map<char, int> mp;
    int l = 0, r = 1;
    mp[s[0]] = 0;
    while (l < r and r < n) {
        if (mp.find(s[r]) == s.end()) {
            mp[s[r]] = r;
            mx = max(mx, r - l);
            r++;
        } else {
            if (mp[s[r]] >= l) {
                l = mp[s[r]] + 1;
                mp[s[r]] = r;
                mx = max(mx, r - l);
                r++;
            } else {
                mp[s[r]] = r;
                mx = max(mx, r - l);
                r++;
            }
        }
    }
}

int findMin(vector<int> &nums) {
    int l = 0, r = a.size() - 1;
    int mn = INT_MAX, t = INT_MIN;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        mn = min(mn, nums[mid]);
        if (nums[mid] < nums[r]) {
            if (t > nums[mid] and t < nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        } else {
            if (t > nums[l] and t < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
    }
    return mn;
}

void solve() {}

void solve2() {
    // rotated sorted 1
    vector<int> a = {7, 8, 9, 11, 13, 1, 2, 3, 4, 5, 6};
    int t = 2;
    int l = 0, r = a.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == t) {
            cout << mid << "\n";
            break;
        } else if (a[mid] < a[r]) {
            if (t > a[mid] and t < a[r])
                l = mid + 1;
            else
                r = mid - 1;
        } else {
            if (t > a[l] and t < a[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
    }
    cout << l << " " << r << "\n";
    // cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(9);
    solve();
    return 0;
}
