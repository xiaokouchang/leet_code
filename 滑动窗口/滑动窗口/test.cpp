//第209题
//长度最小的子数组
//https://leetcode.cn/problems/minimum-size-subarray-sum/description/
//方法1
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


//方法2
//class Solution 
//{
//public:
//    int minSubArrayLen(int target, vector<int>& nums) 
//    {
//        int n = nums.size();
//        int ret = INT_MAX;
//        for (int i = 0; i < n; i++)
//        {
//            int sum = 0;
//            for (int j = i; j < n; j++)
//            {
//                sum += nums[j];
//                if (sum >= target)
//                {
//                    ret = min(ret, j - i + 1);
//                    break;
//                }
//            }
//        }
//        return ret == INT_MAX ? 0 : ret;
//    }
//};


//第3题
//无重复字符的最长子串
//https://leetcode.cn/problems/longest-substring-without-repeating-characters/submissions/685477263/
//#include<algorithm>
//#include<string>
//#include<iostream>
//using namespace std;
//class Solution 
//{
//public:
//    string& lengthOfLongestSubstring(string s) 
//    {
//        int n = s.size();
//        string result;
//        int max_size = 0;
//        for (size_t i = 0; i < n; i++)
//        {
//            string::iterator p = find(result.begin(), result.end(), s[i]);
//            if (p != result.end())
//            {
//                result.erase(result.begin(), p + 1);
//            }
//            result.push_back(s[i]);
//            if (result.size() > max_size)
//            {
//                max_size = max((int)result.size(), max_size);
//                tmp = result;
//            }
//        }
//        return tmp;
//    }
//private:
//    string tmp;
//};
//int main()
//{
//    string tmp("abcabcbb");
//    Solution s;
//    string ret = s.lengthOfLongestSubstring(tmp);
//    cout << ret << endl;
//    return 0;
//}


//第1004题
//最大连续1的个数
//https://leetcode.cn/problems/max-consecutive-ones-iii/
//方法1
//class Solution 
//{
//public:
//    int longestOnes(vector<int>& nums, int k) 
//    {
//        int n = nums.size();
//        int left = 0;          //窗口左边界
//        int zeroCount = 0;     //窗口内0的数量
//        int maxLen = 0;        //最大连续1的长度
//        for (int right = 0; right < n; ++right)
//        {
//            //右指针遇到0,增加0的计数
//            if (nums[right] == 0) 
//            {
//                zeroCount++;
//            }
//            //当0的数量超过k时,移动左指针缩小窗口
//            while (zeroCount > k) 
//            {
//                if (nums[left] == 0) 
//                {
//                    zeroCount--;
//                }
//                left++;
//            }
//            //更新最大窗口长度
//            maxLen = max(maxLen, right - left + 1);
//        }
//        return maxLen;
//    }
//};


//方法2
//class Solution 
//{
//public:
//    int longestOnes(vector<int>& nums, int k) 
//    {
//        int n = nums.size();
//        int count = 0;
//        int left = 0;
//        int max_size = 0;
//        for (int right = 0; right < n; right++)
//        {
//            count += 1 - nums[right];//记录0的个数
//            while (count > k)
//            {
//                count -= 1 - nums[left];//减去左边零的个数,缩小窗口
//                left++;
//            }
//            max_size = max(max_size, right - left + 1);
//        }
//        return max_size;
//    }
//};


//第1658题
//https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/description/
//将x减到0的最小操作数
//方法1
//class Solution 
//{
//public:
//    int minOperations(vector<int>& nums, int x) 
//    {
//        int total = accumulate(nums.begin(), nums.end(), 0);
//        int target = total - x;
//        int n = nums.size();
//        //总和小于x,不可能满足条件
//        if (target < 0)
//        {
//            return -1;
//        }
//        //总和等于x,需要移除所有元素
//        if (target == 0)
//        {
//            return n;
//        }
//        int left = 0;
//        int current_sum = 0;
//        int max_len = -1; //记录满足条件的最长子数组长度
//        //滑动窗口找最长子数组和为target
//        for (int right = 0; right < n; ++right) 
//        {
//            current_sum += nums[right];
//            //窗口和超过target,收缩左边界
//            while (current_sum > target && left <= right) 
//            {
//                current_sum -= nums[left];
//                left++;
//            }
//            //找到和为target的子数组,更新最大长度
//            if (current_sum == target) 
//            {
//                max_len = max(max_len, right - left + 1);
//            }
//        }
//        //未找到满足条件的子数组,返回-1;否则返回n-max_len
//        return max_len == -1 ? -1 : n - max_len;
//    }
//};


//方法2
//total改变了方向,注意sum的初始化
//class Solution 
//{
//public:
//    int minOperations(vector<int>& nums, int x) 
//    {
//        int n = nums.size();
//        int total = x - accumulate(nums.begin(), nums.end(), 0);
//        if (total == 0) // 数组中所有数字加起来刚好等于x
//        {
//            return n;
//        }
//        if (total > 0) // 数组中所有数字加起来都小于x
//        {
//            return -1;
//        }
//        int max_len = -1;
//        int sum = total;
//        int left = 0;
//        for (int right = 0; right < n; right++) 
//        {
//            sum += nums[right];
//            while (sum > 0 && left <= right) 
//            {
//                sum -= nums[left];
//                left++;
//            }
//            if (sum == 0) 
//            {
//                max_len = max(max_len, right - left + 1);
//            }
//        }
//        return max_len == -1 ? -1 : n - max_len;
//    }
//};


//方法3
//不转化
//贪心策略
//#include <iostream>
//#include <vector>
//#include <climits> // 用于INT_MAX
//using namespace std;
//class Solution 
//{
//public:
//    int minOperations(vector<int>& nums, int x) 
//    {
//        int n = nums.size();
//        int left = 0; // 左指针:指向当前左侧待删除的下一个元素
//        int right = n - 1; // 右指针:指向当前右侧待删除的下一个元素
//        long long current_sum = 0; //当前首尾删除元素的总和,避免溢出
//        int min_ops = INT_MAX; //最少操作次数,初始为极大值
//        // 第一步:先贪心累加左侧元素,直到current_sum >= x 或 left越界
//        while (left < n && current_sum < x) {
//            current_sum += nums[left];
//            left++; //left指向的是已删除左侧元素的下一个,已删除元素数为left
//        }
//        //情况1:左侧累加和恰好等于x,更新最少操作次数(仅删除左侧元素)
//        if (current_sum == x) 
//        {
//            min_ops = left;
//        }
//        //第二步:回退左侧元素,同时累加右侧元素,寻找更优解(更少操作次数)
//        while (left > 0) 
//        {
//            //回退左指针:减去最后一个左侧累加的元素,left左移一位
//            left--;
//            current_sum -= nums[left];
//            //累加右侧元素,直到current_sum >= x 或 right < left(左右指针交叉,无元素可删)
//            while (right >= left && current_sum < x) 
//            {
//                current_sum += nums[right];
//                right--; //right指向的是已删除右侧元素的前一个,已删除元素数为(n-1)-right
//            }
//            //若当前和等于x,计算总操作次数并更新min_ops
//            if (current_sum == x) 
//            {
//                int current_ops = left + (n - 1 - right); //左侧删除数+右侧删除数
//                min_ops = min(min_ops, current_ops);
//            }
//        }
//        //最终判断:是否找到有效解
//        return (min_ops == INT_MAX) ? -1 : min_ops;
//    }
//};
//// 测试示例
//int main() {
//    Solution s;
//    // 示例1：nums = [1,1,4,2,3], x = 5 → 最少操作次数2（删除末尾2,3）
//    vector<int> nums1 = { 1,1,4,2,3 };
//    cout << "示例1结果：" << s.minOperations(nums1, 5) << endl;
//
//    // 示例2：nums = [3,2,20,1,1,3], x = 10 → 最少操作次数3（删除末尾3,1,1 或 开头3,2,5）
//    vector<int> nums2 = { 3,2,20,1,1,3 };
//    cout << "示例2结果：" << s.minOperations(nums2, 10) << endl;
//
//    // 示例3：无法满足条件 → 结果-1
//    vector<int> nums3 = { 1,2,3 };
//    cout << "示例3结果：" << s.minOperations(nums3, 10) << endl;
//    return 0;
//}


//方法4
//class Solution 
//{
//public:
//    int minOperations(vector<int>& nums, int x) 
//    {
//        int n = nums.size();
//        int right = n - 1;
//        int sum = 0;
//        // 先找到最长的后缀
//        while (right >= 0 && sum + nums[right] <= x) 
//        {
//            sum += nums[right--];
//        }
//        if (sum < x && right == -1) // 数组所有数字全部相加小于x
//        {
//            return -1;
//        }
//        //后缀范围[right+1,n-1],长度为n-1-(right+1)+1=n-right-1
//        int ret = sum == x ? n - right - 1 : INT_MAX;
//        for (int left = 0; left < n; left++) 
//        {
//            sum += nums[left];
//            // 缩小后缀长度,防止越界
//            while (sum > x && right + 1 < n) 
//            {
//                right++;
//                sum -= nums[right];
//            }
//            if (sum > x) 
//            {
//                break;
//            }
//            if (sum == x) 
//            {
//                //前缀范围[0,left],长度为left+1
//                //前缀+后缀总长度为n-right-1+left+1=n-right+left
//                ret = min(ret, n - right + left);
//            }
//        }
//        return ret == INT_MAX ? -1 : ret;
//    }
//};


//方法5
//方法4的right改为n-1
//class Solution 
//{
//public:
//    int minOperations(vector<int>& nums, int x) 
//    {
//        int n = nums.size();
//        int right = n;
//        int sum = 0;
//        // 先找到最长的后缀
//        while (right >= 0 && sum + nums[right - 1] <= x) 
//        {
//            right--;
//            sum += nums[right--];
//        }
//        if (sum < x && right == -1) // 数组所有数字全部相加小于x
//        {
//            return -1;
//        }
//        // 后缀范围[right,n-1],长度为n-1-right+1=n-right
//        int ret = sum == x ? n - right : INT_MAX;
//        for (int left = 0; left < n; left++) 
//        {
//            sum += nums[left];
//            // 缩小后缀长度,防止越界
//            while (sum > x && right + 1 < n) 
//            {
//                right++;
//                sum -= nums[right];
//            }
//            if (sum > x) 
//            {
//                break;
//            }
//            if (sum == x) 
//            {
//                // 前缀范围[0,left],长度为left+1
//                // 前缀+后缀总长度为n-right+left+1
//                ret = min(ret, n - right + left + 1);
//            }
//        }
//        return ret == INT_MAX ? -1 : ret;
//    }
//};


//第904题
//水果成篮
//https://leetcode.cn/problems/fruit-into-baskets/
//class Solution 
//{
//public:
//    int totalFruit(vector<int>& fruits) 
//    {
//        // 边界处理1:数组为空或长度为0,返回0
//        if (fruits.empty())
//        {
//            return 0;
//        }
//        int n = fruits.size();
//        // 边界处理2:数组长度≤2,直接返回全部,避免后续逻辑异常
//        if (n <= 2) 
//        {
//            return n;
//        }
//        int maxLen = 0;
//        int left = 0; // 窗口左边界(有符号int,避免溢出)
//        int type1 = fruits[0]; // 初始化第一种水果为数组第一个元素,避免-1带来的异常
//        int type2 = -1; // 第二种水果初始化为-1(标记未初始化)
//        int lastTypePos = 0; // 后一种水果的起始位置(初始为第一个元素下标)
//        // 右指针遍历(全程有符号int,确保下标计算安全)
//        for (int right = 0; right < n; ++right) 
//        {
//            int currFruit = fruits[right]; // 确保下标right在[0, n-1],无越界
//            // 情况1:当前水果是窗口内已有的类型(type1或已初始化的type2)
//            if (currFruit == type1 || (type2 != -1 && currFruit == type2)) 
//            {
//                // 仅当水果类型切换且右指针>0时,更新后一种水果的起始位置
//                if (right > 0 && currFruit != fruits[right - 1]) 
//                {
//                    lastTypePos = right;
//                }
//            }
//            // 情况2:当前水果是新类型,需要收缩窗口并更新水果类型
//            else 
//            {
//                // 第一步:更新最大长度(收缩前的窗口为有效窗口)
//                maxLen = max(maxLen, right - left);
//                // 第二步:安全收缩左边界,确保left不小于0(杜绝负数下标)
//                left = lastTypePos;
//                if (left < 0) 
//                {
//                    left = 0;
//                }
//                // 第三步:更新窗口内的两种水果类型(保留最近的一种,新增当前水果）
//                type1 = fruits[right - 1];
//                type2 = currFruit;
//                // 第四步:重置后一种水果的起始位置,确保为有效下标
//                lastTypePos = right;
//            }
//            // 补充初始化:第二种水果尚未初始化时(仅执行一次)
//            if (type2 == -1 && currFruit != type1) 
//            {
//                type2 = currFruit;
//                lastTypePos = right;
//            }
//            // 计算当前窗口长度,更新最大长度(确保下标计算不溢出)
//            int currWindowLen = right - left + 1;
//            if (currWindowLen > maxLen) 
//            {
//                maxLen = currWindowLen;
//            }
//        }
//        return maxLen;
//    }
//};