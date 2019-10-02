/*
 * flash_tests.h
 *
 *  Created on: 1 Oct 2019
 *      Author: Arion
 */


#ifndef FLASH_TESTS_H_
#define FLASH_TESTS_H_


#define TEST_NOT_PERFORMED    	0
#define TEST_RUNNING	     	1
#define TEST_FINISHED		    2
#define TEST_FAILED			    -1


#define SCORE_CORE_FEATURES	 	-1L >>> 56; // 8 most critical features
#define SCORE_BASIC_FEATURES	-1L >>> 48; // 16 most important features
#define SCORE_LEGACY_FEATURES	-1L >>> 32; // all legacy features
#define SCORE_EXT_FEATURES	 	-1L >>> 16; // all legacy and extension features
#define SCORE_ALL_FEATURES	    -1L;


#define FEATURE_INIT 			1 << 0
#define FEATURE_READ			1 << 1
#define FEATURE_WRITE			1 << 2
#define FEATURE_ERASE			1 << 3

#define FEATURE_FS_INIT			1 << 4
#define FEATURE_FS_READ_BK		1 << 5
#define FEATURE_FS_WRITE_BK		1 << 6
#define FEATURE_FS_ERASE_BK		1 << 7
#define FEATURE_FS_TRANSFER		1 << 8
#define FEATURE_FS_RECOVER		1 << 9

#define FEATURE_LOG_INFO		1 << 10
#define FEATURE_LOG_WARN		1 << 11
#define FEATURE_LOG_ERROR		1 << 12
#define FEATURE_LOG_CRITICAL	1 << 13

/*
 * Struct that contains information about the result of a test.
 *
 * The status field should change accordingly during the test.
 * Possible values: TEST_NOT_PERFORMED, TEST_RUNNING, TEST_FINISHED, TEST_FAILED
 *
 * The score field contains information about how well the test was passed.
 * Each feature should have a bit assigned, the most critical one being
 * assigned to the LSB. Unused bits must be set to 1.
 */
typedef struct test_result {
	uint8_t status;
	uint64_t score;
} test_result;



test_result test_features(uint8_t features);
test_result benchmark_features(uint8_t features);
test_result profile_features(uint8_t features);


uint8_t is_test_result_satisfying(test_result result, uint64_t standard);

#endif /* FLASH_TESTS_H_ */