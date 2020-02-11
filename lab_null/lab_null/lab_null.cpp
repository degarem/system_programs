#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("Integer datatypes:\n");
    printf("%d <= char <= %d\n", CHAR_MIN, CHAR_MAX); printf("char in byte=%d\n ", sizeof(char));
    printf("%e <= float <= %e\n", FLT_MIN, FLT_MAX); printf("float in byte=%d\n ", sizeof(float));
    printf("%e <= double <= %e\n", DBL_MIN, DBL_MAX); printf("double in byte=%d\n ", sizeof(double));
    printf("%e <= long double <= %e\n",  LDBL_MIN, LDBL_MAX); printf("long double in byte=%d\n ", sizeof(long double));
    printf("%d <= int <= %d\n", INT_MIN, INT_MAX); printf("int in byte=%d\n ", sizeof(int));
    printf("%ld <= long <= %ld\n", LONG_MIN, LONG_MAX); printf("long in byte=%ld\n ", sizeof(long));
    printf("%d <= signed char <= %d\n", SCHAR_MIN, SCHAR_MAX); printf("signed char in byte=%d\n ", sizeof(signed char));
    printf("%d <= short <= %d\n", SHRT_MIN, SHRT_MAX); printf("short in byte=%d\n ", sizeof(short));
    printf("0 <= unsigned char <= %d\n", UCHAR_MAX); printf("unsigned char in byte=%d\n ", sizeof(unsigned char));
    printf("0 <= unsigned int <= %u\n", UINT_MAX); printf("unsigned int in byte=%u\n ", sizeof(unsigned int));
    printf("0 <= unsigned long <= %lu\n", ULONG_MAX); printf("unsigned long in byte=%lu\n ", sizeof(unsigned long));
    printf("0 <= unsigned short <= %d\n", USHRT_MAX); printf("unsigned short in byte=%d\n ", sizeof(unsigned short));

    return 0;
}