#include "stdafx.h"

using namespace std;

extern void doPrintConsole( std::string a_str )
{
    cout << a_str.c_str() << endl;
}


extern void TestContainer()
{
    CMyStack stack;
    FOR_COUNT_10
    {
        stack.push(new int(i));
        cout << "push = " << i << endl;
    }

    FOR_COUNT_10
    {
        void* pData = stack.pop();
        cout << "pop = " << *((int*)pData) << endl;
        delete pData;
    }

    CMyList<int> list;
    FOR_COUNT_10
    {
        list.push(i);
        cout << "push = " << i << endl;
    }

    FOR_COUNT_10
    {
        cout << "pop = " << (int)list.pop() << endl;
    }
}

extern void TestRemoveStr( char** a_str, char* a_remove )
{

    const int srcLength = strlen(*a_str);

    char* src_str = *a_str;

    bool bFlags[128] = {0,};
    char temp_str[128] = {0,};

    strcpy_s(temp_str, srcLength + 1, src_str);

    //FOR_COUNT_N(128)
    //{
    //    //cout << i << " = " << bFlags[i] << endl;
    //}

    int removeLength = strlen(a_remove);
    FOR_COUNT_N(removeLength)
    {
        bFlags[a_remove[i]] = true;
    }


    int nFlag = 0;
    //string temp_str = a_str;
    for (unsigned int i=0; i <= strlen(src_str); ++i)
    {
        if(bFlags[temp_str[i]] == 0)
        {
            temp_str[nFlag++] = temp_str[i];
        }
    }
    temp_str[nFlag] = '\0';
    cout << temp_str << endl;

    int tempLength = strlen(temp_str);
    strcpy_s(src_str, tempLength + 1, temp_str);
}

extern double TestFactorial( double num )
{
    if( num > 1)
    {
        return TestFactorial(num - 1) * num;
    }
    return 1;
}

extern void TestDoCombine(const char* instr, int length, int level, int start)
{
    string outstr;
    for(int i = start; i < length; ++i)
    {
        char temp_char[] = {instr[i],'\0'};
        outstr.append(temp_char);
        doPrintConsole(outstr);

        if( i < length - 1)
        {
            TestDoCombine(instr, length, length + 1, i + 1);
        }
    }
}

extern void TestCommonMeasure()
{
    for(int i=0; i<100; ++i)
    {
        if( i%3==0 && i%4==0 && i%6==0)
        {
            cout << "commonMeasure = " << i << endl;
        }
    }
}

extern void TestEndianness()
{
    union {
        int theInteger;
        char singleByte;
    }endianTest;

    endianTest.theInteger = 1;
    bool bResult = endianTest.singleByte == 1 ? true : false;
    cout << "endianTest singleByte = " << bResult << endl;
}

void TestNumOnesInBinary( int number )
{
    int tempNum = number;
    int binaryCount = 0;
    int typeBinary = 1;
    while(tempNum != 0)
    {
        //cout << (tempNum & typeBinary) << endl;
        if ((tempNum & 1) == 1)
        {
            ++binaryCount;
        }
        tempNum = tempNum >> 1;
    }
    cout << "NumOnesInBinary Count = " << binaryCount << endl;

}

void TestCheckBinaryPower( int number )
{
    int tempNum = number;
    int binaryPowerSample = 1;
    if( number < 2)
        return;
    while(tempNum != 0)
    {
        if((tempNum | binaryPowerSample) == binaryPowerSample)
        {
            cout << number << " is binaryPower " << endl;
            return;
        }
        binaryPowerSample = binaryPowerSample << 1;
        if( tempNum < binaryPowerSample)
        {
            break;
        }
    }
    //cout << number << " is Not binaryPower " << endl;
}

void TestCheckBinaryPower2( int number )
{
    int tempX = number;
    int tempY = number - 1;
    if( (tempX & tempY) == 0 )
        cout << number << " is binaryPower " << endl;
}

void TestEncrypt( std::string a_src, char** a_dst, unsigned int a_key )
{
    char* dst = *a_dst;

    string::const_iterator iter;
    int i = 0;
    for( iter = a_src.begin(); iter != a_src.end(); ++iter)
    {
        dst[i++] = *iter ^ a_key;
    }
    //*dst = a_src.c_str()
    
}

void TestDecrypt( char** a_src, unsigned int a_key )
{
    string strSrc(*a_src);

    char dst[128] = {0,};

    string::const_iterator iter;
    int i = 0;
    for( iter = strSrc.begin(); iter != strSrc.end(); ++iter)
    {
        dst[i++] = *iter ^ a_key;
    }
    cout << "decrypt = " << dst << endl;
    //strcpy_s(*a_src, strlen(dst) + 1, dst);
}

