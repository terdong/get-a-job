#ifndef __MYLIST_H__
#define __MYLIST_H__

template<typename T>
class CMyList
{
public:
    CMyList():pHead(NULL){}
	~CMyList()
    {
        while(pHead)
        {
            Element* pElement = pHead->pNext;
            delete pHead;
            pHead = pElement;
        }
    }

    void push(T pData);
    T pop();
protected:
    typedef struct _Element{
        _Element* pNext;
        T pData;
        _Element(T a_pData)
        {
            //pNext = a_pNext;
            pNext = NULL;
            pData = a_pData;
        }
    }Element;

    Element* pHead;
    Element* pNext;
};

template<typename T>
void CMyList<T>::push( T pData )
{
    if(pHead == NULL)
    {
        pHead = new Element(pData);
        pNext = pHead;
    }
    else
    {
        Element* pElement = pNext;
        pNext = new Element(pData);
        pElement->pNext = pNext;
    }
}

template<typename T>
T CMyList<T>::pop()
{
    Element* pElement = pHead->pNext;
    T pData = pHead->pData;
    delete pHead;
    pHead = pElement;
    return pData;
}



#endif // __MYLIST_H__