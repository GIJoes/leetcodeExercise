//
// pch.cpp
//

#include "pch.h"
#include<stack>
ListNode* ReverseList(ListNode* head)
{
	if(head==nullptr)
	return nullptr;
	std::stack<ListNode*>stackList;
	ListNode* plist = head;
	while (plist)
	{
		stackList.push(plist);
		plist = plist->next;
	}

	plist = nullptr;
	ListNode* pHead = nullptr;
	while (!stackList.empty())
	{
		ListNode* pNode = stackList.top();
		if (plist == nullptr)
			plist = pNode;
		else
		{
			plist->next = pNode;
			plist = plist->next;
		}
		if (pHead == nullptr)
			pHead = plist;
		stackList.pop();
	}
	plist->next = nullptr;

	return pHead;
}
ListNode* ConstructList(const std::vector<int>& nVec)
{
	ListNode* pHead = nullptr;
	ListNode* pList = pHead;
	for (const auto var:nVec)
	{
		ListNode* pNode=new ListNode(var);
		if(pList==nullptr)
		pList = pNode;
		else
		{
			pList->next = pNode;
			pList = pList->next;
		}
		if (pHead == nullptr)
		{
			pHead = pList;
		}


	}
	return pHead;
}
bool CmpList(const ListNode* l1, const ListNode* l2)
{
	if (l1 == nullptr && l2 == nullptr)
		return true;
	else if (l1 != nullptr && l2 != nullptr && l1->val == l2->val)
		return CmpList(l1->next,l2->next);
	else
		return false;
}
void uniqueNumbers(std::vector<int>nVec)
{
	std::set<int>nSet;
	for (size_t i = 0; i < nVec.size(); i++)
	{
		nSet.insert(nVec[i]);
	}
	for each (const auto var in nSet)
	{
		std::cout << var << std::endl;
	}
}

int exchangeProduct(const int n)
{
	if (n < 2)
		return 0;
	if (n == 2)
		return 1;
	int nProduct = n / 3;
	int nleft = n % 3;
	return nProduct +exchangeProduct(nProduct+ nleft);
}

int computer(const int a, const int b)
{
	//return a * b / a * b;
	//return a / b * b / a;
	return  a / b * b + a % b;
}
bool SizeIsEnough(ListNode* head, int m)
{
	int i = 0;
	ListNode* pNode = head;
	while (pNode != nullptr && i++ < m)
	{
		pNode = pNode->next;
	}

	return i == m;
}
ListNode* reverseBetween(ListNode* head, int m, int n)
{
	if (!SizeIsEnough(head, m) || !SizeIsEnough(head, n))
		return nullptr;
	int i = 1;
	ListNode* pNode1 = head;
	ListNode* pNode2 = head;
	while (i<(n-m))
	{
		pNode2 = pNode2->next; 
		i++;
	}
	i = 1;
	while (i<m)
	{
		pNode1 = pNode1->next;
		pNode2 = pNode2->next;
	}



}

int GetLastWordLength(const std::string& str)
{
	if(str.empty())
	return 0;

	size_t pos = str.rfind(' ');
	if (pos == std::string::npos)
	{
		return str.length();
	}
	return str.substr(pos+1,str.length()-pos).length();
}

int GetcharCount(const std::string& str, char c)
{

	return 0;
}

void PaddingOctStr(const std::string& str)
{
	const int exlen = 8;
	if (str.empty())
		return;
	if (str.length() >= exlen)
	{
		std::cout << str.substr(0, exlen)<<std::endl;
		if (str.length() > exlen)
			return PaddingOctStr(str.substr(exlen, str.length() - exlen));
		else
			return;
	}

	return PaddingOctStr(str + "0");
}

bool IsPrime(long long n) {
	for (long long i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

std::string ReverseWords(const std::string& str)
{
	if (str.length() < 2)
		return str;
	std::string s(str);

	ReverseStr(s, 0, s.length() - 1);
	std::stringstream ss;
	ss << s;
	std::string word;
	std::string resStr;
	while (ss>>word)
	{
		ReverseStr(word, 0, word.length() - 1);
		resStr.append(word).append(" ");
	}

	resStr = resStr.substr(0,resStr.length()-1);
	return resStr;


	/*for (int i = 0, j = 0; i < s.length() && j < s.length();)
	{
		while (s[i] == ' ')
			i++;
		j = i;
		while (s[j] != ' ' && j < s.length())
			j++;
		ReverseStr(s, i, j - 1);
		i = j + 1;
	}
	return s;*/

}

void ReverseStr(std::string& s, int start, int end)
{
	if (start >= end || s.length() < 2 || end < 0)
		return;
	for (int iStart = start, iEnd = end; iStart < iEnd; iStart++, iEnd--)
	{
		char tmp = s[iStart];
		s[iStart] = s[iEnd];
		s[iEnd] = tmp;
	}
}
static void MoveVector(std::vector<int> nums,int start,int end)
{
	if(start>end||end>nums.size()-1)
	return;
	while (start<end&&end< nums.size())
	{
		nums[start++] = nums[end++];
	}
}
int GetUniqueLength(std::vector<int>& nums)
{
	if (nums.empty())
		return 0;
	size_t i = 0, j = i + 1;
	for (; i < nums.size()&&j<nums.size(); i++,j++)
	{
		if (nums[i] == nums[j])
		{
			i = j;
			j++;
			while (nums[j]==nums[i]&&j<nums.size()-1)
			{
				j++;
			}
			MoveVector(nums,i+1,j);
		}
		else
		{
			i++; j = i + 1;
		}
	}
	for (size_t index = 0; index < i+1; index++)
	{
		std::cout << nums[index] << std::endl;
	}
	return i+1;
}

int removeElement(std::vector<int>& nums, int val)
{
	int i = 0;
	int j = nums.size() - 1;
	while (i < j)
	{
		if (nums[i] == val)
		{
			int tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
			j--;
		}
		else
		{
			i++;
		}
	}
	return i+1;
}


template<typename T>
inline T GetMax(const T& a, const T& b)
{
	return a>b?a:b;
}
