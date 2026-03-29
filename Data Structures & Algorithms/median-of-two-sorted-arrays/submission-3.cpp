class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int leftSide = (nums1.size() + nums2.size() - 1) / 2;

        // nums1 preferably smaller to run bs on it
        if (nums1.size() > nums2.size()) swap(nums1, nums2);

        int l = 0;
        int r = nums1.size() - 1;
        int mid = -1;
        while (l <= r && l < nums1.size() && r != -1) {
            mid = (l + r) / 2;
            int mid2 = leftSide - mid;
            cout<<"l, r: "<<l<<", "<<r;

            if (mid2 != 0 && nums1[mid] < nums2[mid2-1])
                l = mid + 1;
            else if (mid != 0 && nums2[mid2] < nums1[mid - 1])
                r = mid - 1;
            else break; // the condition for median holds
        }
        if (r == -1) mid = r;
        else if (l == nums1.size()) mid = l;
        int mid2 = leftSide - mid;

        if ((nums1.size() + nums2.size()) % 2 == 1) {
            if (mid == -1) return nums2[leftSide];
            if (mid >= nums1.size()) return nums2[leftSide - nums1.size()];

            return min(nums1[mid], nums2[leftSide - mid]);
        } else {
            if (mid == -1)
                return med(nums2[leftSide], nums2[leftSide+1]);
            if (mid >= nums1.size())
                return med(nums2[leftSide - nums1.size()], nums2[leftSide - nums1.size() + 1]);
            
            if (mid2 != nums2.size() - 1 && nums1[mid] > nums2[mid2+1])
                return med(nums2[mid2], nums2[mid2+1]);
            else if (mid != nums1.size() - 1 && nums2[mid2] > nums1[mid+1])
                return med(nums1[mid], nums1[mid+1]);
        }

        return med(nums1[mid], nums2[mid2]);
    }

    double med(int a, int b) {
        return static_cast<double>(a + b) / 2;
    }
};

