#ifndef __TESTCASE_H__
#define __TESTCASE_H__

#define FOR_COUNT_N(N) for(int i=0; i<N; ++i)

#define FOR_COUNT_10 for(int i=0; i<10; ++i)

extern void doPrintConsole(std::string a_str);

extern void TestContainer();

extern void TestRemoveStr(char** a_str, char* a_remove);

extern double TestFactorial(double num);

extern void TestDoCombine(const char* instr, int length, int level, int start);

extern void TestCommonMeasure();

extern void TestEndianness();

void TestNumOnesInBinary(int number);

void TestCheckBinaryPower(int number);
void TestCheckBinaryPower2(int number);

void TestEncrypt(std::string a_src, char** a_dst, unsigned int a_key);
void TestDecrypt( char** a_dst, unsigned int a_key);

#define foo(a,b) ( (size_t) &((a)NULL)->b )

#endif // __TESTCASE_H__