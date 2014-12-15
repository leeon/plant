#include <iostream>


void diff_array_with_ptr()
{

    printf("\n%s Run:%s():\n", __TIME__,__FUNCTION__);

    int aVal [] = {1,2,3};
    int *ptr = aVal;

    // about the meaning
    printf("%lu\n", sizeof(aVal));
    printf("%lu\n", sizeof(ptr));

    // a convertion
    printf("%p\n", ptr);
    printf("%p\n", aVal);
    printf("%p\n", &aVal[0]);
    printf("%p\n", &aVal);



}


void diff_constptr_with_ptrconst()
{
    printf("\n%s Run:%s():\n", __TIME__,__FUNCTION__);

    int a = 10;
    int b = 11;
    const int *p1 = &a;
    int * const p2 = &a;
    // *p1 = 12; // err
    p1 = &b;
    *p2 = 12;
    // p2 = &b;  //err
}


void test_array()
{
    int a[]  = {1,2,3};

    printf("%d\n", a[1]);
    printf("%d\n", *(a + 1));
}


int main(int argc, char const *argv[])
{

    diff_array_with_ptr();

    diff_constptr_with_ptrconst();
    
    test_array();
    
    return 0;
}