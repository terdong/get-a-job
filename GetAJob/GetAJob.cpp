// GetAJob.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

using namespace std;

struct Rectangle
{
    int top;
    int left;
    int bottom;
    int right;
};

int _tmain(int argc, _TCHAR* argv[])
{

    char* forEncryptString = "하이";
    char desString[128] = {0,};
    char* pDesString = desString;
    cout << "source = " << forEncryptString << endl;
    TestEncrypt(forEncryptString, &pDesString, 123);

    cout << "encrypt = " << pDesString << endl;

    TestDecrypt(&pDesString, 123);

    //TestEndianness();

    //TestNumOnesInBinary(9);

    //for( int i=1; i<100; ++i)
    //TestCheckBinaryPower2(i);

    //int offset = foo(struct Rectangle*, bottom);
    //printf("offset = %X\n", offset);

    //TestContainer();

    //char temp_str[] = "test";
    //char* src = temp_str;
    //TestRemoveStr(&src,"es");

    //cout << temp_str << endl;

    //cout << "testFactorial = " << TestFactorial(10) << endl;

    //string str = "zxvc";
    //int length = str.length();
    //const char* instr = str.c_str();
    //TestDoCombine(instr, length, 0, 0);

	return 0;
}

