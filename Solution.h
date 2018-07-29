#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m, n, tmp;
		vector<int> temp;

		m = nums1.size(); n = nums2.size();
		
		if (m > n)
		{
			temp = nums1; nums1 = nums2; nums2 = temp;
			tmp = m; m = n; n = tmp;
		}

		if (n == 0) 0.0;

		int i, j, mid;
		int imin, imax, left_max, right_min;

		imin = 0; imax = m;
		mid = (n + m + 1) / 2;
		while (imin <= imax)
		{
			i = (imin + imax) / 2;
			j = mid - i;

			if (i < m && nums2[j - 1] > nums1[i])
			{
				// i is too small
				imin = i + 1;
			}
			else if (i > 0 && nums1[i - 1] > nums2[j])
			{
				// i is too big
				imax = i - 1;
			}
			else {
				// i is perfect
				if (i == 0) left_max = nums2[j - 1];
				else if (j == 0) left_max = nums1[i - 1];
				else left_max = max(nums1[i - 1], nums2[j - 1]);

				if ((n + m) % 2 == 1) return left_max;

				if (i == m) right_min = nums2[j];
				else if (j == n) right_min = nums1[i];
				else right_min = min(nums1[i], nums2[j]);

				return (left_max + right_min) / 2.0;
			}
		}


		return 0.0;
	}
};