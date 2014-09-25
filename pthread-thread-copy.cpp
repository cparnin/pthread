#include <iostream>
#include <pthread.h>
#include <sys/time.h>

using namespace std;

void *test_1(void *x);
void *test_2(void *y);

struct MyArray
{
    int num [2000000];
    int sum1;
    int sum2;
};

int main()
{
    struct timeval b,e;

    MyArray one;

    for (int i = 0; i < 2000000; i++)
    	one.num[i] = i+1;

    int return1, return2;

    pthread_t t1, t2;
 
    gettimeofday( &b, NULL );

    return1 = pthread_create (&t1, NULL, test_1, (void*) &one);
    return2 = pthread_create (&t2, NULL, test_2, (void*) &one);

    pthread_join (t1, NULL);
    pthread_join (t2, NULL);

    gettimeofday( &e, NULL );

    cout << "Main version of sum1: " << one.sum1 << endl;

    cout << "It took " << ( ( e.tv_sec - b.tv_sec ) + ( e.tv_usec - b.tv_usec ) * 1e-6 ) << " seconds." << endl << endl;

    return 0;
}

void *test_1(void* x)
{
    MyArray *y = (MyArray*)x;
    //MyArray *y = new MyArray;

    int tempSum = 0;

    for (int i = 0; i < 1000000; i++)
	tempSum += (*y).num[i];
    (*y).sum1 = tempSum;
    cout << (*y).sum1 << endl;
    return NULL;
}

void *test_2(void* y)
{
    int tempSum = 0;

    MyArray *x = (MyArray*)y;
    for (int i = 1000000; i < 2000000; i++)
	tempSum += (*x).num[i];
    (*x).sum2 = tempSum;
    cout << (*x).sum2 << endl;
    return NULL;    
}
