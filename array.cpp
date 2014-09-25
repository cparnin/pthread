#include <iostream>
#include <time.h>
#include <sys/time.h>
using namespace std;

void test_1(int x[]);
void test_2(int y[]);

int main()
{
    struct timeval b,e;
    gettimeofday (&b, NULL);

    int num[2000000] = {0};
    for (int i = 0; i < 2000000; i++)
	num[i] = i+1;

    test_1(num);
    test_2(num);
    
    gettimeofday (&e, NULL);
    cout << "It took " << ( ( e.tv_sec - b.tv_sec ) + ( e.tv_usec - b.tv_usec ) * 1e-6) << " seconds." << endl << endl;

    return 0;
}

void test_1(int x[])
{
    int sum1 = 0;
    for (int i = 0; i < 1000000; i++)
	sum1 += x[i];
    cout << sum1 << endl;
}

void test_2(int y[])
{
    int sum2 = 0;
    for (int i = 1000000; i < 2000000; i++)
	sum2 += y[i];
    cout << sum2 << endl;
}
