//283
//https://leetcode.cn/problems/move-zeroes/description/
//方法1
//赋值
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//        int left = 0;
//        int right = 0;
//        for (left = 0; left < nums.size(); left++)
//        {
//            if (nums[left] != 0)
//            {
//                nums[right] = nums[left];
//                if (left != right)
//                {
//                    nums[left] = 0;
//                }
//                right++;
//            }
//        }
//    }
//};


//方法2
//交换元素
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//        int left = 0;
//        int right = 0;
//        for (left = 0; left < nums.size(); left++)
//        {
//            if (nums[left] != 0)
//            {
//                swap(nums[left], nums[right]);
//                right++;
//            }
//        }
//    }
//};


//1089
//https://leetcode.cn/problems/duplicate-zeros/
//方法1
//class Solution {
//public:
//    void duplicateZeros(vector<int>& arr) {
//        //先找到最后一个数
//        int cur = 0;
//        int dest = -1;
//        int n = arr.size();
//        while (cur < n)
//        {
//            if (arr[cur]) dest++;
//            else dest += 2;
//            if (dest >= n - 1) break;
//            cur++;
//        }
//        //处理边界情况
//        if (dest == n)
//        {
//            arr[n - 1] = 0;
//            cur--;
//            dest -= 2;
//        }
//        //从后向前完成复写操作
//        while (cur >= 0)
//        {
//            if (arr[cur]) arr[dest--] = arr[cur--];
//            else
//            {
//                arr[dest--] = 0;
//                arr[dest--] = 0;
//                cur--;
//            }
//        }
//    }
//};


//方法2
//class Solution {
//public:
//    void duplicateZeros(vector<int>& arr) {
//        int count = 0;//统计0的个数
//        int n = arr.size();
//        for (auto e : arr)
//        {
//            if (e == 0)
//            {
//                count++;
//            }
//        }
//        int i = n - 1;
//        int j = n + count - 1;
//        while (i >= 0 && j >= 0)
//        {
//            if (arr[i] == 0)
//            {
//                if (j < n)
//                {
//                    arr[j] = 0;
//                }
//                j--;
//                if (j < n)
//                {
//                    arr[j] = 0;
//                }
//            }
//            else
//            {
//                if (j < n)
//                {
//                    arr[j] = arr[i];
//                }
//            }
//            i--;
//            j--;
//        }
//    }
//};


//方法3
//class Solution {
//public:
//    void duplicateZeros(vector<int>& arr) {
//        int cur = 0;
//        int dest = -1;
//        int flag1 = 0;
//        int flag2 = 0;
//        int n = arr.size();
//        // 1, 0, 2, 3, 0, 4, 5, 0
//        while (dest < n) {
//            if (dest + 1 >= n) {
//                flag2 = 1;
//                break;
//            }
//            if (arr[cur] == 0) {
//                // int temp = ;
//                if (dest + 2 >= arr.size()) {
//                    dest += 1;
//                    flag1 = 1;
//                }
//                else {
//                    dest += 2;
//                }
//            }
//            else {
//                dest += 1;
//            }
//            if (dest < n) {
//                cur += 1;
//            }
//        }
//        while (cur > 0) {
//            cur--;
//            if (flag2 == 1) {
//                flag2 = 0;
//            }
//            else {
//                dest--;
//            }
//            if (arr[cur] == 0) {
//                if (flag1 == 1) {
//                    arr[dest] = 0;
//                    flag1 = 0;
//                }
//                else {
//                    arr[dest] = 0;
//                    dest--;
//                    arr[dest] = 0;
//                }
//            }
//            else {
//                arr[dest] = arr[cur];
//            }
//        }
//    }
//};