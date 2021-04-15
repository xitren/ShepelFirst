/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   test1.c
 * Author: dmitry
 *
 * Created on 8 апреля 2021 г., 20:11
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Simple C Test Suite
 */

void test1()
{
    printf("test1 test 1\n");
}

void test2()
{
    printf("test1 test 2\n");
    printf("%%TEST_FAILED%% time=0 testname=test2 (test1) message=error message sample\n");
}

int main(int argc, char** argv)
{
    printf("%%SUITE_STARTING%% test1\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%% test1 (test1)\n");
    test1();
    printf("%%TEST_FINISHED%% time=0 test1 (test1) \n");

    printf("%%TEST_STARTED%% test2 (test1)\n");
    test2();
    printf("%%TEST_FINISHED%% time=0 test2 (test1) \n");

    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}
