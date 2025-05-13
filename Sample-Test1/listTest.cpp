#include"pch.h"
#include<iostream>
/**
 * Definition for singly-linked list.*/

std::ostream& operator<< (std::ostream& os, ListNode* list)
{
    if (list == nullptr)
        return os;
    os << "[";
    while (list)
    {
        os << list->val;
        list = list->next;
        if (list)
        {
            os << ",";
        }
    }
    os << "]"<<std::endl;
    return os;
}

class Solution {
      
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* pNode;
        ListNode* root = nullptr;

        if (list1 == nullptr)
            return list2;

        if (list2 == nullptr)
            return list1;
        while (list1)
        {
            if (list1->val < list2->val)
            {
                pNode = list1;
                ListNode* tmp = list1->next;
                if (tmp)
                {
                    list1->next = nullptr;
                    list1 = tmp;
                }
                else
                {
                    pNode->next = list2;
                    return pNode;
                }
            }
            else
            {

            }
        }


       return pNode;
    }

    void test()
    {
        ListNode l1(1);
        ListNode l2(2);
        l1.next = &l2;
        ListNode l3(4);
        l2.next = &l3;

        ListNode k1(1);
        ListNode k2(3);
        k1.next = &k2;
        ListNode k3(4);
        k2.next = &k3;


        std::cout<<mergeTwoLists(&l1,&k1);
        
    }


};


TEST(ListTestCaseName, MerageList)
{
    Solution so;
    so.test();
    EXPECT_FALSE(false);
}