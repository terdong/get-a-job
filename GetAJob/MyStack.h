#ifndef __MYSTACK_H__
#define __MYSTACK_H__

class CMyStack
{
public:
	CMyStack();
	~CMyStack();
	void push( void* data);
    void* pop();
protected:
    typedef struct _Element{
        _Element* pNext;
        void*    pData;
    }Element;

    Element* pHead;
};

#endif // __MYSTACK_H__