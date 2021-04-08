/*
 * File:   TestF_Memset.c
 * Author: dmitry
 *
 * Created on 8 апреля 2021 г., 15:10
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Simple C Test Suite
 */

void test1()
{
    printf("TestF_Memset test 1\n");
}

void test2()
{
    printf("TestF_Memset test 2\n");
    printf("%%TEST_FAILED%% time=0 testname=test2 (TestF_Memset) message=error message sample\n");
}

int main(int argc, char** argv)
{
    printf("%%SUITE_STARTING%% TestF_Memset\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%% test1 (TestF_Memset)\n");
    test1();
    printf("%%TEST_FINISHED%% time=0 test1 (TestF_Memset) \n");

    printf("%%TEST_STARTED%% test2 (TestF_Memset)\n");
    test2();
    printf("%%TEST_FINISHED%% time=0 test2 (TestF_Memset) \n");

    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}
