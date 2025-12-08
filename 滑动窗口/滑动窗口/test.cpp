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

