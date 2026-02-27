#define _CRT_SECURE_NO_WARNINGS 1 
//重复读取多组相同类型的数据(多组输入)
//方法1
//while循环+scanf的返回值,scanf的返回值是scanf成功读到的数字个数。
//当输入的数不是两个数时或者在VS编译器中按3次ctrl+z结束循环。
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	while (scanf("%d %d", &a, &b) == 2)
//	{
//		//题目要求
//	}
//	return 0;
//}


//方法2
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	char c = 0;
//	//while (scanf("%d %d %c", &a, &b, &c))
//	//不能写成这样,%d会自动跳过所有空白字符(空格、换行\n、制表符\t)
//	//%c前面的空格会让scanf继续跳过空白,因此c永远无法接收到换行符\n
//	//输入1 2\n时,scanf读完1(a)、2(b)后,会跳过\n,等待你手动输入下一个字符给c,
//	//导致c=='\n'永远不成立
//	while (scanf("%d %d%c", &a, &b, &c))
//	{
//		if (c != '\n')
//		{
//			break;
//		}
//		//题目要求
//	}
//	return 0;
//}


//交换两个整数的值
//方法1---直接输出
//#include<stdio.h>
//int main()
//{
//	int num1 = 10;
//	int num2 = 20;
//	printf("%d %d\n", num2, num1);
//	return 0;
//}


//方法2---临时变量
//#include<stdio.h>
//int main()
//{
//	int num1 = 10;
//	int num2 = 20;
//	int temp = num2;
//	num2 = num1;
//	num1 = temp;
//	printf("%d %d\n", num1, num2);
//	return 0;
//}


//方法3---加减法
//#include<stdio.h>
//int main()
//{
//	int num1 = 10;
//	int num2 = 20;
//	num1 = num1 + num2;
//	num2 = num1 - num2;
//	num1 = num1 - num2;
//	printf("%d %d\n", num1, num2);
//	return 0;
//}


//方法4---异或
//#include <stdio.h>
//int main()
//{
//    int num1 = 10;
//    int num2 = 20;
//    num1 = num1 ^ num2;
//    //把两块拼图板靠近,让它们的图案信息相互交织,产生一种混合的图案信息,存储在拼图板A上。
//    num2 = num1 ^ num2;
//    //再次让两块拼图板相互作用,拼图板B从混合信息中提取出拼图板A原来的图案信息,然后更新自己的图案。
//    num1 = num1 ^ num2;
//    //拼图板A从混合信息中提取出拼图板B原来的图案信息,更新自己的图案,完成交换。
//    printf("%d %d\n", num1, num2);
//    return 0;
//}


//方法5
//编写一个函数,使用指针作为参数,交换两个整数的值。
//#include<stdio.h>
//void change(int* num1, int* num2)
//{
//	int temp = *num1;
//	*num1 = *num2;
//	*num2 = temp;
//}
//int main()
//{
//	int num1 = 10;
//	int num2 = 20;
//	printf("交换前:%d %d\n", num1, num2);
//	change(&num1, &num2);
//	printf("交换后:%d %d\n", num1, num2);
//	return 0;
//}


//给定两个数,求这两个数的最大公约数和最小公倍数
//辗转相除法
//#include<stdio.h>
//int main()
//{
//	long long num1 = 0, num2 = 0;
//	scanf("%lld %lld", &num1, &num2);
//	//确保m >= n
//	if (num1 < num2)
//	{
//		num1 = num1 + num2;
//		num2 = num1 - num2;
//		num1 = num1 - num2;
//	}
//	long long mul = num1 * num2;
//	//求m和n的最大公因数
//	while (num2 != 0)
//	{
//		int temp = num1 % num2;
//		num1 = num2;
//		num2 = temp;
//	}
//	long long gcd = num1;//此时num1为最大公因数
//	//求m和n的最小公倍数
//	long long lcm = mul / num1;
//	printf("最大公因数:%lld,最小公倍数:%lld\n", gcd, lcm);
//	return 0;
//}


//更相减损术求最大公约数
//#include <stdio.h>
//int gcd(int num1, int num2) 
//{
//    int count = 0; //记录共同的2的因子数
//    //步骤3:处理偶数因子
//    while ((num1 % 2 == 0) && (num2 % 2 == 0))
//    {
//        num1 /= 2;
//        num2 /= 2;
//        count++;
//    }
//    //步骤4-5:更相减损
//    while (num1 != num2)
//    {
//        if (num1 > num2)
//        {
//            num1 -= num2;//num1 = num1 - num2
//        }
//        else
//        {
//            num2 -= num1;//num2 = num2 - num1
//        }
//    }
//    //步骤6:计算最终结果
//    return num1 * (1 << count); // 等价于m × 2^k
//}
//int main() 
//{
//    int num1, num2;
//    printf("请输入两个正整数：");
//    scanf("%d %d", &num1, &num2);
//    int ret = gcd(num1, num2);
//    printf("最大公约数为:%d\n", ret);
//    return 0;
//}


//优化版:当较大数远大于较小数时,一次减去多个较小数
//#include <stdio.h>
//int gcd(int num1, int num2) 
//{
//    int count = 0;
//    while ((num1 % 2 == 0) && (num2 % 2 == 0))
//    {
//        num1 /= 2;
//        num2 /= 2;
//        count++;
//    }
//    while (num1 != num2)
//    {
//        if (num1 > num2)
//        {
//            if (num1 / num2 > 1)
//            {
//                num1 -= num2 * (num1 / num2 - 1); // 一次减多个n
//            }
//            else
//            {
//                num1 -= num2;
//            }
//        }
//        else 
//        {
//            if (num2 / num1 > 1)
//            {
//                num2 -= num1 * (num2 / num1 - 1); // 一次减多个m
//            }
//            else
//            {
//                num2 -= num1;
//            }
//        }
//    }
//    return num1 * (1 << count);
//}
//int main()
//{
//    int num1, num2;
//    printf("请输入两个正整数：");
//    scanf("%d %d", &num1, &num2);
//    int ret = gcd(num1, num2);
//    printf("最大公约数为:%d\n", ret);
//    return 0;
//}


//查找数组中的最大值
//编写一个函数, 使用指针遍历数组, 找出数组中的最大值。
//*(arr + i) == arr[i] == i[arr] == *(i + arr)
//#include<stdio.h>
//int MAX(int* arr, int sz)
//{
//	int max = 0;
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if (max < *(arr + i))
//		{
//			max = *(arr + i);
//		}
//	}
//	return max;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = MAX(arr, sz);
//	printf("%d\n", ret);
//	return 0;
//}


//查找数组中的最大值
//编写一个函数, 在1-100之间随机生成10个整数,使用指针遍历数组,找出数组中的最大值。
//*(arr + i) == arr[i] == i[arr] == *(i + arr)
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//int MAX(int* arr, int sz)
//{
//	int max = 0;
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if (max < *(arr + i))
//		{
//			max = *(arr + i);
//		}
//	}
//	return max;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	srand((unsigned int)(time)(NULL));
//	int i = 0;
//	//rand() % 100表示随机生成0~99之间的数
//	//rand() % 100 + 1表示随机生成1~100之间的数
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = rand() % 100 + 1;
//	}
//	int ret = MAX(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//	printf("\n");
//	printf("%d\n", ret);
//	return 0;
//}


//求字符串长度
//第1种方法
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[] = "hello world!";
//	int len = strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


//第2种方法
//#include<stdio.h>
//int* my_strlen(char* arr)
//{
//	char* temp = arr;
//	while (*temp != '\0')
//	{
//		temp++;
//	}
//	return temp - arr;
//}
//int main()
//{
//	char arr[] = "hello world!";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


//计数器
//#include<stdio.h>
//int my_strlen(char* arr)
//{
//	int count = 0;
//	while (*arr != '\0')
//	{
//		count++;
//		arr++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "hello world!";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


//字符串反转
//编写一个函数,接收一个字符串指针,将该字符串反转。
//#include<stdio.h>
//void back(char* arr)
//{
//	int sz = strlen(arr);
//	char* start = arr;
//	char* end = arr + sz - 1;
//	while (start < end)
//	{
//		char temp = *start;
//		*start = *end;
//		*end = temp;
//		start++;
//		end--;
//	}
//}
//int main()
//{
//	char arr[] = "Hello World!";
//	back(arr);
//	printf("%s\n", arr);
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//    int a = 7;
//    int b = 2;
//    float c = 2.0f;
//    printf("%d\n", a / b);
//    printf("%f\n", a / c);
//    return 0;
//}
//3 3.500000


//#include <stdio.h>
//int main()
//{
//	int a, b, c;
//	a = 5;
//	c = ++a;//a 6 c 6
//	b = ++c, c++, ++a, a++;
//	//c 8 a 8 b 7
//	b += a++ + c;
//	//b = b+ 16 // 23
//	// a  9 
//	//c 8
//	printf("a = %d b = %d c = %d\n:", a, b, c);
//	return 0;
//}
//9 23 8


//#include <stdio.h>
//
//int main()
//{
//    printf("%5d\n", 123456);
//    return 0;
//}
//123456


//#include <stdio.h>
//int main() 
//{
//	int x = 3;
//	int y = 3;
//	switch (x % 2) 
//	{
//	case 1:
//		switch (y)
//		{
//		case 0:
//			printf("first");
//		case 1:
//			printf("second");
//			break;
//		default: 
//			printf("hello");
//		}
//	case 2:
//		printf("third");
//	}
//	return 0;
//}
//hellothird


//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0;
//	for (a = 1, b = 1; a <= 100; a++)
//	{
//		if (b >= 20) break;
//		if (b % 3 == 1)
//		{
//			b = b + 3;//4 7 10 13 16 19 22 
//			continue;
//		}
//		b = b - 5;
//	}
//	printf("%d\n", a);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 1;i <= 9;i++)
//	{
//		int j = 0;
//		for (j = 1;j <= i;j++)
//		{
//			printf("%d * %d = %2d ", j, i, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//求10个整数的最大值
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0;i < 10;i++)
//	{
//		arr[i] = i;
//	}
//	int max = arr[0];
//	for (i = 1;i < 10;i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("%d\n", max);
//	return 0;
//}


//计算1/1-1/2+1/3-1/4+1/5……+1/99-1/100的值,打印出结果
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	double sum = 0;
//	int flag = 1;
//	for (i = 1;i <= 100;i++)
//	{
//		if (flag == 1)
//		{
//			sum += 1.0 / i;
//			flag = 0;
//		}
//		else
//		{
//			sum += -1.0 / i;
//			flag = 1;
//		}
//	}
//	printf("%lf\n", sum);
//	return 0;
//}


//编写程序数一下1到100的所有整数中出现多少个数字9
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1;i <= 100;i++)
//	{
//		if ((i+1) % 10 == 0)
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}


//写一个代码:打印100~200之间的素数
//#include<stdio.h>
//#include<math.h>
//int prime(int num)
//{
//	int i = 0;
//	int flag = 1;
//	for (i = 2;i <= sqrt(num);i++)
//	{
//		if (num % i == 0)
//		{
//			flag = 0;
//			break;
//		}
//	}
//	if (flag == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int i = 0;
//	for (i = 101;i <= 200;i+=2)
//	{
//		int ret = prime(i);
//		if (ret == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	return 0;
//}


//打印1000年到2000年之间的闰年
//#include<stdio.h>
//int sort(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int i = 0;
//	for (i = 1000;i <= 2000;i++)
//	{
//		int ret = sort(i);
//		if (ret == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int i = 0;
//	int ret = rand() % 100 + 1;
//	int num = 0;
//	while (1)
//	{
//		printf("请输入你要猜的数字:>\n");
//		scanf("%d", &num);
//		if (num > ret)
//		{
//			printf("数字太大,请重新猜\n");
//		}
//		else if (num < ret)
//		{
//			printf("数字太小,请重新猜\n");
//		}
//		else
//		{
//			printf("恭喜你,猜对了\n");
//			break;
//		}
//	}
//	return 0;
//}


//求10个数的平均值
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	double sum = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0; i < 10; i++)
//	{
//		sum += arr[i];
//	}
//	sum /= 10;
//	printf("%f\n", sum);
//	return 0;
//}


//交换数组
//#include<stdio.h>
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 0 };
//	int i = 0;
//	printf("交换前:>\n");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//	for (i = 0; i < 10; i++)
//	{
//		int temp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = temp;
//	}
//	printf("交换后:>\n");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//	return 0;
//}


