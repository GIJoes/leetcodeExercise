//
// pch.h
//

#pragma once

#include "gtest/gtest.h"

typedef struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
}ListNode;


ListNode* ReverseList(ListNode* head);
ListNode* ConstructList(const std::vector<int>& nVec);
bool CmpList(const ListNode* l1, const ListNode* l2);
void uniqueNumbers(std::vector<int>nVec);
int exchangeProduct(const int n);
int computer(const int a, const int b);
ListNode* reverseBetween(ListNode* head, int m, int n);
int GetLastWordLength(const std::string&str);
int GetcharCount(const std::string&str,char c);
void PaddingOctStr(const std::string& str);
bool IsPrime(long long n);
std::string ReverseWords(const std::string&s);
void ReverseStr(std::string& s,int start,int end);
int GetUniqueLength(std::vector<int>&nums);
int removeElement(std::vector<int>& nums, int val);

template<typename T>
T GetMax(const T&a,const T&b);

