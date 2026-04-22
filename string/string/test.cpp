//8.字符串转整数
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


//43. 字符串相乘
//https://leetcode.cn/problems/multiply-strings/
//class Solution
//{
//public:
//    string multiply(string num1, string num2)
//    {
//        if (num1 == "0" || num2 == "0")
//        {
//            return "0";
//        }
//        int m = num1.size();
//        int n = num2.size();
//        vector<int> vec(m + n, 0);
//        for (int i = m - 1; i >= 0; i--) 
//        {
//            int digit1 = num1[i] - '0';
//            for (int j = n - 1; j >= 0; j--) 
//            {
//                int digit2 = num2[j] - '0';
//                int mul = digit1 * digit2;
//                int sum = mul + vec[i + j + 1];
//                vec[i + j + 1] = sum % 10;
//                vec[i + j] += sum / 10;
//            }
//        }
//        string result;
//        for (auto e : vec)
//        {
//            if (!(result.empty() && e == 0))
//            {
//                result.push_back(e + '0');
//            }
//        }
//        return result;
//    }
//};


//125.回文串
//https://leetcode.cn/problems/valid-palindrome/
//方法1
//class Solution {
//public:
//    string Isstring(string s) {
//        int n = s.size();
//        int i = 0;
//        string ret;
//        while (i < n) {
//            if (isalpha(s[i]) || isdigit(s[i])) {
//                if (isupper(s[i])) {
//                    ret += tolower(s[i]);
//                }
//                else {
//                    ret += s[i];
//                }
//            }
//            i++;
//        }
//        return ret;
//    }
//    bool isPalindrome(string s) {
//        string ret = Isstring(s);
//        int n = ret.size();
//        if (n <= 1) {
//            return true;
//        }
//        int left = 0;
//        int right = n - 1;
//        while (left < right) {
//            if (ret[left] == ret[right]) {
//                left++;
//                right--;
//            }
//            else {
//                return false;
//            }
//        }
//        return true;
//    }
//};


//方法2
//class Solution {
//public:
//    bool isPalindrome(string s) {
//        int n = s.size();
//        int left = 0;
//        int right = n - 1;
//        while (left < right) {
//            if (!isalnum(s[left]))
//            {
//                left++;
//            }
//            else if (!isalnum(s[right]))
//            {
//                right--;
//            }
//            else if (tolower(s[left]) == tolower(s[right]))
//            {
//                left++;
//                right--;
//            }
//            else
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//};


//387.字符串中的第一个唯一字符
//https://leetcode.cn/problems/first-unique-character-in-a-string/description/
//方法1
//class Solution {
//public:
//    int firstUniqChar(string s) {
//        vector<int> vec(128, 0);
//        for (auto e : s)
//        {
//            vec[e] += 1;
//        }
//        int i = 0;
//        for (i = 0; i < s.size(); i++)
//        {
//            if (vec[s[i]] == 1)
//            {
//                return i;
//            }
//        }
//        return -1;
//    }
//};


//方法2
//class Solution {
//public:
//    int firstUniqChar(string s) {
//        map<char, int> m;
//        for (auto e : s)
//        {
//            m[e]++;
//        }
//        int i = 0;
//        for (i = 0; i < s.size(); i++)
//        {
//            if (m[s[i]] == 1)
//            {
//                return i;
//            }
//        }
//        return -1;
//    }
//};


//415.字符串相加
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


//541. 反转字符串 II
//https://leetcode.cn/problems/reverse-string-ii/description/?envType=problem-list-v2&envId=string
//class Solution 
//{
//public:
//    string reverseStr(string s, int k)
//    {
//        int n = s.size();
//        int i = 0;
//        for (i = 0; i < n; i += 2 * k)
//        {
//            reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
//        }
//        return s;
//    }
//};


//557. 反转字符串中的单词 III
//https://leetcode.cn/problems/reverse-words-in-a-string-iii/description/
//class Solution 
//{
//public:
//    string reverseWords(string s)
//    {
//        int n = s.size();
//        int left = 0;
//        int right = 0;
//        for (right = 0; right < n; right++)
//        {
//            if (right + 1 < n && s[right + 1] == ' ' || s[right + 1] == '\0')
//            {
//                reverse(s.begin() + left, s.begin() + right + 1);
//                left = right + 2;
//            }
//        }
//        return s;
//    }
//};


//917.仅仅反转字母
//https://leetcode.cn/problems/reverse-only-letters/description/
//方法1
//class Solution {
//public:
//    string reverseOnlyLetters(string s) {
//        int n = s.size();
//        int i = 0;
//        int j = n - 1;
//        string tmp(s);
//        while (i < j)
//        {
//            if (!isalpha(s[i]))
//            {
//                i++;
//            }
//            else if (!isalpha(s[j]))
//            {
//                j--;
//            }
//            else
//            {
//                swap(tmp[i], tmp[j]);
//                i++;
//                j--;
//            }
//        }
//        return tmp;
//    }
//};


//方法2
//class Solution
//{
//public:
//    bool Isalpha(char c)
//    {
//        if (c >= 'a' && c <= 'z')
//        {
//            return true;
//        }
//        if (c >= 'A' && c <= 'Z')
//        {
//            return true;
//        }
//        return false;
//    }
//    string reverseOnlyLetters(string s)
//    {
//        int n = s.size();
//        if (n == 0)
//        {
//            return s;
//        }
//        int i = 0;
//        int j = n - 1;
//        string tmp(s);
//        while (i < j)
//        {
//            while (i < j && !Isalpha(s[i])) 
//            {
//                i++;
//            }
//            while (i < j && !Isalpha(s[j])) 
//            {
//                j--;
//            }
//            swap(tmp[i], tmp[j]);
//            i++;
//            j--;
//        }
//        return tmp;
//    }
//};

