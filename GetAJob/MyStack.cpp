#include "stdafx.h"

CMyStack::CMyStack()
:pHead(NULL)
{}

CMyStack::~CMyStack()
{
    while(pHead)
    {
        Element* pNext = pHead->pNext;
        delete pHead;
        pHead = pNext;
    }
}

void CMyStack::push( void* data )
{
    Element* pElement = new Element;
    pElement->pData = data;
    pElement->pNext = pHead;
    pHead = pElement;
}

void* CMyStack::pop()
{
    Element* pElement = pHead;
    if(pHead)
    {
        void* pData = pElement->pData;
        pHead = pElement->pNext;
        delete pElement;
        return pData;
    }

    return NULL;
    
}
