#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#define LENGTH 5

double getMax(double array[])
{
	double max = array[0];

	for(int i = 1; i< LENGTH; i++)
	{
		if(array[i]>max)
		{
			max = array[i];
		}
	}
	return max;
}

double getAvg(double array[])
{
	double average = 0;

	for(int i = 0; i< LENGTH; i++)
		{
			average += array[i];
		}

	return average /5;

}
void allZeroMax_testcase(){
		CU_ASSERT(getMax((double[]){0.0,0.0,0.0,0.0,0.0})== 0.0);
	}

	void positiveMax_testcase() {
		CU_ASSERT(getMax((double[]){1.1, 5.2, 2.3, 3.4, 4.0}) == 5.2);
		CU_ASSERT(getMax((double[]){3.7, 4.9, 2.2, 6.5, 1.8}) == 6.5);
		CU_ASSERT(getMax((double[]){2.5, 3.6, 4.8, 1.9, 5.7}) == 5.7);
		CU_ASSERT(getMax((double[]){4.1, 2.7, 5.3, 3.8, 1.6}) == 5.3);
		CU_ASSERT(getMax((double[]){1.0,0.0,0.0,0.0,0.0}) == 5.9);
	}

	void negativeMax_testcase() {
		CU_ASSERT(getMax((double[]){1.1, -5.2, 2.3, -3.4, 4.0}) == 4.0);
		CU_ASSERT(getMax((double[]){-3.7, -4.9, -2.2, -6.5, -1.8}) == -1.8);
		CU_ASSERT(getMax((double[]){-2.5, 3.6, -4.8, 1.9, -5.7}) == 3.6);
		CU_ASSERT(getMax((double[]){-4.1, -2.7, -5.3, -3.8, -1.6}) == -1.6);
		CU_ASSERT(getMax((double[]){-1.0,0.0,0.0,0.0,0.0}) == 4.3);
	}

	void allZeroAvg_testcase(){
		CU_ASSERT(getAvg((double[]){0.0,0.0,0.0,0.0,0}) == 0.0);
	}

	void positiveAvg_testcase() {
		CU_ASSERT(getAvg((double[]){1.0, 2.0, 3.0, 4.0, 5.0}) == 3.0);
		CU_ASSERT(getAvg((double[]){10.0, 20.0, 30.0, 40.0, 50.0}) == 30.0);
		CU_ASSERT(getAvg((double[]){0.5, 1.5, 2.5, 3.5, 4.5}) == 2.5);
		CU_ASSERT(getAvg((double[]){0.1, 0.2, 0.3, 0.4, 0.5}) == 0.3);
		CU_ASSERT(getAvg((double[]){3.5, 7.5, 11.5, 15.5, 19.5}) == 11.5);
	}

	void negativeAvg_testcase() {
		CU_ASSERT(getAvg((double[]){1.0, -2.0, 3.0, -4.0, 5.0}) == 0.6);
		CU_ASSERT(getAvg((double[]){-10.0, 20.0, -30.0, 40.0, -50.0}) == -6.0);
		CU_ASSERT(getAvg((double[]){0.5, -1.5, 2.5, -3.5, 4.5}) == 0.5);
		CU_ASSERT(getAvg((double[]){3.5, -7.5, 11.5, -15.5, 19.5}) == 2.3);
		CU_ASSERT(getAvg((double[]){0.5,0.0,0.0,0.0,0}) == 0.1);
		}

void runAllTests(){

	CU_initialize_registry();
	CU_pSuite max = CU_add_suite("max_array", 0, 0);
	CU_pSuite avg = CU_add_suite("avg_array", 0, 0);


	CU_add_test(max, "allZeroMax_test", allZeroMax_testcase);
	CU_add_test(max, "positiveMax_test", positiveMax_testcase);
	CU_add_test(max, "negativeMax_test", negativeMax_testcase);

	CU_add_test(avg, "allZeroAvg_test", allZeroAvg_testcase);
	CU_add_test(avg, "positiveAvg_test", positiveAvg_testcase);
	CU_add_test(avg, "negativeAvg_test", negativeAvg_testcase);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
}

