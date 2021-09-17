#include <iostream>

using namespace std;

struct Branch
{
    int Data;
    Branch *Left;
    Branch *Right;
};

void add(int aData, Branch *&aBranch)
{
    if (!aBranch)
    {
        aBranch = new Branch;
        aBranch->Data = aData;
        aBranch->Left = 0;
        aBranch->Right = 0;
        return;
    }
    else

        if (aBranch->Data > aData)
    {
        add(aData, aBranch->Right);
    }
    else
    {
        add(aData, aBranch->Left);
    }
}

void print(int aDate, Branch *&aBranch)
{
    
}


void add_elem(int aData, Branch *&aBranch)
{
    if (!aBranch)
    {
        aBranch = new Branch;
        aBranch->Data = aData;
        aBranch->Left = 0;
        aBranch->Right=0;
        return;
    }
    else
    if (aData < aBranch->Data)
    {
        add_elem(aData, aBranch->Right);
    }
    else
    if (aData > aBranch->Data)
    {
        add_elem(aData, aBranch->Left);
    }
}

Branch *del(int aData, Branch *&aBranch)
{
    if (aBranch == NULL)
    {
        return aBranch;
    }
    if (aData == aBranch->Data)
    {
        Branch *buf;
        if (aBranch->Right == NULL)
        {
            buf = aBranch->Left;
        }
        else
        {
            Branch *ptr = aBranch->Right;
            if (ptr->Left == NULL)
            {
                ptr->Left = aBranch->Left;
                buf = ptr;
            }
            else
            {
                Branch *pmin = ptr->Left;
                while (pmin->Left !=NULL)
                {
                    ptr = pmin;
                    pmin = ptr->Left;
                }
                ptr->Left = pmin->Right;
                pmin->Left = aBranch->Left;
                pmin->Right = aBranch->Right;
                buf = pmin;
            }
        }
        delete aBranch;
        return buf;
    }
    else
    {
        if (aData < aBranch->Data)
        {
            aBranch->Left = del(aData, aBranch->Left);
        }
        else
        {
            aBranch->Right = del(aData, aBranch->Right);
        }
    }
    return aBranch;  
}

void pr_obh(Branch *aBranch)
{  
    if (!aBranch)
    return;

    cout << aBranch->Data << endl;
    pr_obh(aBranch->Left);
    pr_obh(aBranch->Right);
}