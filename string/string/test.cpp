//字符串转整数
//https://leetcode.cn/problems/string-to-integer-atoi/description/
//class Solution 
//{
//public:
//    int myAtoi(string s) 
//    {
//        int n = s.size();
//        int i = 0;
//        //跳过空格
//        while (i < n && s[i] == ' ')
//        {
//            i++;
//        }
//        //只处理一次符号位
//        int sign = 1;
//        if (i < n && (s[i] == '+' || s[i] == '-'))
//        {
//            sign = (s[i++] == '-') ? -1 : 1;
//        }
//        //处理数字位
//        long long ret = 0;
//        while (i < n && isdigit(s[i]))
//        {
//            ret = ret * 10 + (s[i++] - '0');
//            if (ret > INT_MAX)
//            {
//                return sign == 1 ? INT_MAX : INT_MIN;
//            }
//        }
//        return ret * sign;
//    }
//};


//字符串相加
//https://leetcode.cn/problems/add-strings/description/?envType=problem-list-v2&envId=string
//class Solution 
//{
//public:
//    string addStrings(string num1, string num2) 
//    {
//        int i = num1.size() - 1;
//        int j = num2.size() - 1;
//        int carry = 0;//进位
//        string result;//进位
//        while (i >= 0 || j >= 0 || carry != 0)
//        {
//            int x = i >= 0 ? num1[i--] - '0' : 0;
//            int y = j >= 0 ? num2[j--] - '0' : 0;
//            int sum = x + y + carry;
//            carry = sum / 10;
//            result += (sum % 10) + '0';
//        }
//        reverse(result.begin(), result.end());
//        return result;
//    }
//};