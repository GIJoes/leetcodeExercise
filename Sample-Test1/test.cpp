#include "pch.h"
template<typename T>
T Add(const T& a, const T& b)
{
	return a + b;
}

//find duplate num in an arry
//arry contains nums 1~n,length more than n
void FindDuplateNum(const int arr[],int len,int*duplate)
{

}

void test11()
{
	int* p = new int(12);
	delete[]p;
}

int CharToInt(const char c)
{
	int n = 0;
	if (c >= '0' && c <= '9')
		n = int(c - '0');
	if (c >= 'a' && c <= 'f')
		n = int(c - 'a')+10;
	if (c >= 'A' && c <= 'F')
		n = int(c - 'A')+10;
	return n;
}

long OxToDigit(const std::string& str)
{
	long num = 0;
	if (str.size() < 2)
		return num;
	std::string preStr = str.substr(0,2);
	if (preStr != "0x")
		return num;
	size_t pos = str.find("0x");
	pos += 2;
	std::string numberStr = str.substr(2,str.length()-2);
	for (size_t i = 0; i < numberStr.length(); i++)
	{
		if (numberStr[i] >= '0' && numberStr[i] <= '9' || numberStr[i] >= 'a' && numberStr[i] <= 'f' || numberStr[i] >= 'A' && numberStr[i] <= 'F')
			continue;
		else
		{
			return 0;
		}
	}
	int ex = 1;
	for (int i = numberStr.length()-1; i >= 0; i--)
	{
		num += CharToInt(numberStr[i]) * ex;
		ex *= 16;
	}

	return num;

}


TEST(TestCaseName, TestName) {
	test11();
	EXPECT_EQ(Add(0.1f, 0.2f), 0.3f);
	EXPECT_EQ(Add(100,100), 200);
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
	EXPECT_EQ(OxToDigit("0xAA"), 170);
	EXPECT_EQ(OxToDigit("0xZZ"), 0);
	EXPECT_EQ(OxToDigit("AA"), 0);
	EXPECT_EQ(OxToDigit("0x123"), 291);
	EXPECT_EQ(OxToDigit("0x2C"), 44);
}


TEST(TestCaseName, uniqueNumbers) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
	uniqueNumbers({2,2,1});
}

TEST(TestCaseName, exchangeProduct) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
	EXPECT_EQ(exchangeProduct(1), 0);
	EXPECT_EQ(exchangeProduct(2), 1);
	EXPECT_EQ(exchangeProduct(3), 1);
	EXPECT_EQ(exchangeProduct(4), 2);
	EXPECT_EQ(exchangeProduct(5), 2);
	EXPECT_EQ(exchangeProduct(10), 5);
	EXPECT_EQ(exchangeProduct(81), 40);

}

TEST(TestCaseName, computerNN)
{
	EXPECT_EQ(computer(2, 3), 2);
	EXPECT_EQ(computer(3,2), 3);
}

TEST(TestCaseName, ReverseList)
{
	EXPECT_TRUE(CmpList(ReverseList(ConstructList({1,2,3})), ConstructList({ 3,2,1 })));
}

TEST(TestCaseName, GetLastWordLength)
{
	EXPECT_EQ(GetLastWordLength("hello nowcoder"), 8);
	EXPECT_EQ(GetLastWordLength("hello"), 5);
	EXPECT_EQ(GetLastWordLength(""), 0);
	std::string str;
	std::getline(std::cin, str);
	std::cout << GetLastWordLength(str)<<std::endl;
}

TEST(TestCaseName, PaddingOctStr)
{
	std::string str;
	getline(std::cin, str);
	PaddingOctStr(str);
	EXPECT_TRUE(true);
}
TEST(TestCaseName, PrintPrime)
{
	long long n = 0;
	std::map<int, int>map1;
	if (std::cin >> n) {
		long long x = n;
		for (long long i = 2; i <= n; i++) {
			while (IsPrime(i) && (x % i == 0)) {
				std::cout << i << " ";
				x = x / i;
			}
			if (IsPrime(x))
			{
				std::cout << x << std::endl;
				break;
			}
		}
	}
	EXPECT_TRUE(true);
}

TEST(TestCaseName, ReverseWords)
{
	EXPECT_EQ(ReverseWords("the sky is blue"), std::string("blue is sky the"));
	EXPECT_EQ(ReverseWords("  hello world  "), std::string("world hello"));
	EXPECT_EQ(ReverseWords("a good   example"), std::string("example good a"));
}

TEST(TestCaseName, GetUniqueLength)
{
	std::vector<int>nums{ 1, 1, 1, 2};
	EXPECT_EQ(GetUniqueLength(nums), 3);

}

//LeetCode
TEST(LeetCode, removeElement)
{
	std::vector<int>params{ 3,2,2,3};
	EXPECT_EQ(removeElement(params,3), 3);
}

TEST(LeetCode, reRead)
{
	for (size_t i = 1; i < 10; i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}

	std::cerr << "what'fuck your problem!\n";


	EXPECT_TRUE(true);
}

static int partion(int* nums, int length)
{
	if (nums == nullptr || length < 1)
		return -1;

	int pork = nums[0];
	int start = 0;
	int end = length - 1;


}
int initialiation = 1;

struct abc {
	char a;
	char b;
	int c;
	double d;
	char e;
};
TEST(LeetCode, initialiation)
{
	int initialiation = initialiation;
	std::cout << "initialiation=" << initialiation << std::endl;
	std::cout << sizeof(abc) << std::endl;
	EXPECT_FALSE(false);
}