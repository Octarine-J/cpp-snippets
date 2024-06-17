#include <iostream>
#include <vector>


double find_median(std::vector<int>& nums1, std::vector<int>& nums2) {
    // trivial case
    if (nums1.empty() && nums2.empty()) {
        return 0;
    }

    // we'll form first part of partition from the smaller array
    bool first_smaller = nums1.size() <= nums2.size();
    const auto& A = first_smaller ? nums1 : nums2;
    const auto& B = first_smaller ? nums2 : nums1;

    int n = static_cast<int>(A.size());
    int m = static_cast<int>(B.size());
    int N = (m + n) / 2;  // partition size

    // will estimate the end of partition in array A (index) using binary search
    int l = 0, r = n - 1;

    while (true) {
        int ea = l <= r ? (l + r) / 2 : -1;  // ea = end of partition in A
        int eb = (ea < 0 || ea >= m) ? N - 1 : N - ea - 2;

        // next element after partition end
        double next;
        if (eb >= m - 1) {  // already took all elements from B
            next = A[ea + 1];
        } else if (ea >= n - 1) {  // already took all elements from A
            next = B[eb + 1];
        } else {
            next = std::min(B[eb + 1], A[ea + 1]);
        }

        // check if partition is correct
        if ((eb < 0 || B[eb] <= next) && (ea < 0 || A[ea] <= next)) {
            if ((n + m) % 2 == 1) {  // median is the mid element
                return next;
            } else {
                if (eb < 0) {
                    return (A[ea] + next) / 2.0;
                } else if (ea < 0) {
                    return (B[eb] + next) / 2.0;
                } else {
                    return (std::max(A[ea], B[eb]) + next) / 2.0;
                }
            }
        } else {
            if (eb >= 0 && B[eb] > next) {
                l = ea + 1;  // need to take more from A
            } else { // ea > next
                r = ea - 1;  // need to take less from A
            }
        }
    }
}

void ans(std::vector<int> nums1, std::vector<int> nums2) {
    auto res = find_median(nums1, nums2);
    std::cout << res << std::endl;
}

int main() {
    ans({2}, {1,3,4,5,6,7,8});
    ans({}, {2, 3});
    ans({}, {1, 2, 3});
    ans({1, 2, 3}, {});
    ans({1, 3}, {2});
    ans({1, 2}, {3, 4});
    ans({3, 4}, {1, 2});
    ans({999}, {1, 2, 3, 4});
    ans({1, 2, 3, 4}, {999});
    ans({1, 2, 3, 4, 5, 6, 7, 8}, {1, 2, 3, 4});  // [1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 7, 8]
    ans({1, 2, 3, 4}, {1, 2, 3, 4, 5, 6, 7, 8});
    ans({1}, {2, 3, 4, 5, 6, 7});
    ans({1, 5}, {2, 3, 4, 6, 7});
    ans({1, 5, 6}, {2, 3, 4, 7});
    ans({1, 2, 5, 6}, {3, 4, 7});
}

