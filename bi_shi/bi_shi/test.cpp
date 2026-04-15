//数字统计
//https://www.nowcoder.com/practice/179d9754eeaf48a1b9a49dc1d438525a?tpId=290&tqId=39941&ru=/exam/oj
//方法1
//#include <iostream>
//using namespace std;
//int count(int num) 
//{
//    int cnt = 0;
//    while (num > 0) 
//    {
//        int ret = num % 10;
//        if (ret == 2) 
//        {
//            cnt++;
//        }
//        num /= 10;
//    }
//    return cnt;
//}
//int main() 
//{
//    int a, b;
//    while (cin >> a >> b) 
//    {
//        int i = 0;
//        int cnt = 0;
//        for (i = a; i <= b; i++) 
//        {
//            cnt += count(i);
//        }
//        cout << cnt << endl;
//    }
//    return 0;
//}


//// 计算 0 ~ n 中，数字2出现的总次数
long long count2(long long n) {
    if (n < 2) return 0;    // 小于2，不可能有2，直接返回0
    long long res = 0;      // 总次数
    long long base = 1;     // 从个位开始统计（base=1）

    // 循环遍历每一位：个位→十位→百位...直到超过n
    while (base <= n) {
        // 1. 拆分出高位、当前位、低位
        long long high = n / (base * 10);
        long long cur = (n / base) % 10;
        long long low = n % base;

        // 2. 分3种情况计算当前位的2的次数
        if (cur < 2) {
            // 情况1：当前位数字 < 2 → 次数 = 高位 * base
            res += high * base;
        }
        else if (cur == 2) {
            // 情况2：当前位数字 = 2 → 次数 = 高位*base + 低位 + 1
            res += high * base + low + 1;
        }
        else {
            // 情况3：当前位数字 > 2 → 次数 = (高位+1) * base
            res += (high + 1) * base;
        }

        base *= 10; // 切换到下一位（个位→十位→百位...）
    }
    return res;
}


