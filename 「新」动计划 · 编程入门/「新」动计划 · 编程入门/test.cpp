//#include<iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}


//2235
//https://leetcode.cn/problems/add-two-integers/description/?envType=study-plan-v2&envId=primers-list
//class Solution {
//public:
//    int sum(int num1, int num2) {
//        return num1 + num2;
//    }
//};


//2469
//https://leetcode.cn/problems/convert-the-temperature/?envType=study-plan-v2&envId=primers-list
//方法1
//#include<vector>
//class Solution {
//public:
//    vector<double> convertTemperature(double celsius) {
//        double kel = celsius + 273.15;
//        double hua = celsius * 1.80 + 32;
//        vector<double> vec;
//        vec.reserve(2);
//        vec.push_back(kel);
//        vec.push_back(hua);
//        return vec;
//    }
//};


//方法2
//#include<vector>
//class Solution {
//public:
//    vector<double> convertTemperature(double celsius) {
//        return { celsius + 273.15,celsius * 1.80 + 32 };
//    }
//};


//2413
//https://leetcode.cn/problems/smallest-even-multiple/?envType=study-plan-v2&envId=primers-list
//方法1
//class Solution {
//public:
//    int smallestEvenMultiple(int n) {
//        if (n <= 2)
//        {
//            return 2;
//        }
//        int mul = 2 * n;
//        int num2 = 2;
//        while (num2 != 0)
//        {
//            int temp = n % num2;
//            n = num2;
//            num2 = temp;
//        }
//        int j = mul / n;
//        return j;
//    }
//};


//方法2
//class Solution {
//public:
//    int smallestEvenMultiple(int n) {
//        return n % 2 == 0 ? n : 2 * n;
//    }
//};


//2236
//https://leetcode.cn/problems/root-equals-sum-of-children/?envType=study-plan-v2&envId=primers-list
//class Solution {
//public:
//    bool checkTree(TreeNode* root) {
//        return root->val == root->left->val + root->right->val;
//    }
//};


//1486
//https://leetcode.cn/problems/xor-operation-in-an-array/?envType=study-plan-v2&envId=primers-list
//方法1
//class Solution 
//{
//public:
//    int xorOperation(int n, int start) {
//        if (n == 1)
//        {
//            return start;
//        }
//        vector<int> vec;
//        vec.reserve(n);
//        int num1, num2, temp;
//        for (int i = 0; i < n; i++)
//        {
//            vec[i] = start + 2 * i;
//        }
//        for (int j = 0; j < n - 1; j++)
//        {
//            if (j == 0)
//            {
//                num1 = vec[j];
//                num2 = vec[j + 1];
//            }
//            else
//            {
//                num1 = temp;
//                num2 = vec[j + 1];
//            }
//            temp = num1 ^ num2;
//        }
//        return temp;
//    }
//};


//方法2
//class Solution {
//public:
//    int xorOperation(int n, int start) {
//        int temp = 0;
//        for (int i = 0; i < n; i++)
//        {
//            temp = temp ^ (start + 2 * i);
//        }
//        return temp;
//    }
//};


//1512
//https://leetcode.cn/problems/number-of-good-pairs/description/?envType=study-plan-v2&envId=primers-list
//class Solution {
//public:
//    int numIdenticalPairs(vector<int>& nums) {
//        int count = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            for (int j = i + 1; j < nums.size(); j++)
//            {
//                if (nums[i] == nums[j])
//                {
//                    count++;
//                }
//            }
//        }
//        return count;
//    }
//};


//1534
//https://leetcode.cn/problems/count-good-triplets/?envType=study-plan-v2&envId=primers-list
//#include<cmath>
//class Solution {
//public:
//    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
//        int count = 0;
//        for (int i = 0; i < arr.size() - 2; i++)
//        {
//            for (int j = i + 1; j < arr.size() - 1; j++)
//            {
//                for (int k = j + 1; k < arr.size(); k++)
//                {
//                    int num1 = arr[i];
//                    int num2 = arr[j];
//                    int num3 = arr[k];
//                    if ((abs(num1 - num2) <= a) && (abs(num2 - num3) <= b) && (abs(num1 - num3) <= c))
//                    {
//                        count++;
//                    }
//                }
//            }
//        }
//        return count;
//    }
//};


//709
//https://leetcode.cn/problems/to-lower-case/solutions/1151839/zhuan-huan-cheng-xiao-xie-zi-mu-by-leetc-5e29/?envType=study-plan-v2&envId=primers-list
//方法1
//#include<algorithm>
//class Solution {
//public:
//    string toLowerCase(string s) {
//        transform(s.begin(), s.end(), s.begin(), ::tolower);
//        return s;
//    }
//};


//方法2
//#include<algorithm>
//class Solution {
//public:
//    string toLowerCase(string s) {
//        for (auto& ch : s)
//        {
//            ch = tolower(ch);
//        }
//        return s;
//    }
//};


//258
//https://leetcode.cn/problems/add-digits/description/
//class Solution 
//{
//public:
//    int addDigits(int num) 
//    {
//        if (num < 10)
//        {
//            return num;
//        }
//        int sum = num / 10 + num % 10;
//        while (sum >= 10)
//        {
//            sum = num / 10 + num % 10;
//            num = sum;
//        }
//        return sum;
//    }
//};


//1281
//https://leetcode.cn/problems/subtract-the-product-and-sum-of-digits-of-an-integer/description/
//class Solution {
//public:
//    int subtractProductAndSum(int n) {
//        int mul = 1;
//        int sum = 0;
//        while (n)
//        {
//            int g = n % 10;
//            mul *= g;
//            sum += g;
//            n /= 10;
//        }
//        return (mul - sum);
//    }
//};


//231.2
//https://leetcode.cn/problems/power-of-two/description/?envType=study-plan-v2&envId=primers-list
//方法1
//class Solution {
//public:
//    bool isPowerOfTwo(int n) {
//        if (n == 1)
//        {
//            return true;
//        }
//        if (n % 2 != 0 || n <= 0)
//        {
//            return false;
//        }
//        int temp = n;
//        while (temp >= 2)
//        {
//            if (temp % 2 != 0)
//            {
//                return false;
//            }
//            temp /= 2;
//        }
//        return true;
//    }
//};


//方法2
//https://leetcode.cn/problems/power-of-two/solutions/796201/2de-mi-by-leetcode-solution-rny3/?envType=study-plan-v2&envId=primers-list
//class Solution {
//public:
//    bool isPowerOfTwo(int n) {
//        return n > 0 && (n & n - 1) == 0;
//    }
//};


//方法3
//https://leetcode.cn/problems/power-of-two/solutions/796201/2de-mi-by-leetcode-solution-rny3/?envType=study-plan-v2&envId=primers-list
//class Solution {
//public:
//    bool isPowerOfTwo(int n) {
//        return n > 0 && (n & -n) == 0;
//    }
//};


//方法4
//https://leetcode.cn/problems/power-of-two/solutions/796201/2de-mi-by-leetcode-solution-rny3/?envType=study-plan-v2&envId=primers-list
//class Solution {
//private:
//    static constexpr int BIG = 1 << 30;
//
//public:
//    bool isPowerOfTwo(int n) {
//        return n > 0 && BIG % n == 0;
//    }
//};


//326.3
//https://leetcode.cn/problems/power-of-three/description/?envType=study-plan-v2&envId=primers-list
//方法1
//class Solution 
//{
//public:
//    bool isPowerOfThree(int n) {
//        if (n <= 0 || n == 2)
//        {
//            return false;
//        }
//        if (n == 1)
//        {
//            return true;
//        }
//        int temp = n;
//        while (temp >= 3)
//        {
//            if (temp % 3 != 0)
//            {
//                return false;
//            }
//            temp /= 3;
//        }
//        if (temp == 1)
//        {
//            return true;
//        }
//        return false;
//    }
//};


//方法2
//class Solution {
//public:
//    bool isPowerOfThree(int n) {
//        while (n && (n % 3 == 0))
//        {
//            n /= 3;
//        }
//        return n == 1;
//    }
//};


//263.丑数
//https://leetcode.cn/problems/ugly-number/description/?envType=study-plan-v2&envId=primers-list
//方法1
//class Solution {
//public:
//    bool isUgly(int n) {
//        while (n >= 2)
//        {
//            if (n % 2 == 0)
//            {
//                n /= 2;
//            }
//            else if (n % 3 == 0)
//            {
//                n /= 3;
//            }
//            else if (n % 5 == 0)
//            {
//                n /= 5;
//            }
//            else
//            {
//                break;
//            }
//        }
//        if (n == 2 || n == 1)
//        {
//            return true;
//        }
//        return false;
//    }
//};


//方法2
//2 3 5逐个进行判断
//https://leetcode.cn/problems/ugly-number/solutions/3007807/li-yong-wei-yun-suan-you-hua-pythonjavac-nlqr/?envType=study-plan-v2&envId=primers-list
//class Solution 
//{
//public:
//    bool isUgly(int n) {
//        if (n <= 0)
//        {
//            return false;
//        }
//        while (n % 3 == 0)
//        {
//            n /= 3;
//        }
//        while (n % 5 == 0)
//        {
//            n /= 5;
//        }
//        return (n & (n - 1)) == 0;
//    }
//};


//1470.重新排列数组
//https://leetcode.cn/problems/shuffle-the-array/description/?envType=study-plan-v2&envId=primers-list
//方法1
//class Solution {
//public:
//    vector<int> shuffle(vector<int>& nums, int n) {
//        vector<int> vec;
//        vec.reserve(2 * n);
//        int n1 = 0;
//        int n2 = n;
//        int flag = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (flag == 0)
//            {
//                vec.push_back(nums[n1]);
//                n1++;
//                flag = 1;
//            }
//            else
//            {
//                vec.push_back(nums[n2]);
//                n2++;
//                flag = 0;
//            }
//        }
//        return vec;
//    }
//};


//1470.重新排列数组
//方法1
//class Solution {
//public:
//    vector<int> shuffle(vector<int>& nums, int n) {
//        vector<int> vec;
//        vec.reserve(2 * n);
//        for (int i = 0; i < nums.size() - n; i++)
//        {
//            vec.push_back(nums[i]);
//            vec.push_back(nums[i + n]);
//        }
//        return vec;
//    }
//};


//方法2