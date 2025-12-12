//第209题
//长度最小的子数组
//https://leetcode.cn/problems/minimum-size-subarray-sum/description/
//#include<vector>
//#include<iostream>
//using namespace std;
//class Solution 
//{
//public:
//    int minSubArrayLen(int target, vector<int>& nums) 
//    {
//        int n = nums.size();
//        int sum = 0;
//        int ret = nums.size();
//        int left = 0;
//        //右边扩张
//        for (int right = 0; right < n; right++)
//        {
//            sum += nums[right];
//            while (sum >= target)
//            {
//                ret = min(ret, right - left + 1);//每次更新ret
//                sum -= nums[left];
//                left++;//左边收缩
//            }
//        }
//        if (sum < target && left == 0)
//        {
//            return 0;
//        }
//        return ret;
//    }
//};


//第1004题
//最大连续1的个数
//https://leetcode.cn/problems/max-consecutive-ones-iii/
//class Solution {
//public:
//    int longestOnes(vector<int>& nums, int k) {
//        int n = nums.size();
//        int left = 0;          // 窗口左边界
//        int zeroCount = 0;     // 窗口内0的数量
//        int maxLen = 0;        // 最大连续1的长度
//
//        for (int right = 0; right < n; ++right) {
//            // 右指针遇到0，增加0的计数
//            if (nums[right] == 0) {
//                zeroCount++;
//            }
//
//            // 当0的数量超过k时，移动左指针缩小窗口
//            while (zeroCount > k) {
//                if (nums[left] == 0) {
//                    zeroCount--;
//                }
//                left++;
//            }
//
//            // 更新最大窗口长度
//            maxLen = max(maxLen, right - left + 1);
//        }
//
//        return maxLen;
//    }
//};