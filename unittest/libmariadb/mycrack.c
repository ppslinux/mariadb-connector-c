/*
 * =====================================================================================
 *
 *       Filename:  mycrack.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015-07-31 12:27:54 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include "my_test.h"
#include <time.h>
unsigned long GetTickCount()
{
	static signed long long begin_time = 0;
	static signed long long now_time;
	struct timespec tp;
	unsigned long tmsec = 0;
	if ( clock_gettime(CLOCK_MONOTONIC, &tp) != -1 )
	{
		now_time = tp.tv_sec * 1000 + tp.tv_nsec / 1000000;
	}
	if ( begin_time = 0 )
		begin_time = now_time;
	tmsec = (unsigned long)(now_time - begin_time);
	return tmsec;
}

static int insert_recoder(MYSQL *mysql)
{
  	int rc;
	int i= 0;
	char cmd[256];
	memset(cmd,0,256);

	for( i=0 ;i<100;i++)
	{
		snprintf(cmd,256, "insert into runwell_table(ID,runwell1,runwell2) VALUES(%d,'abcd','def')",i);
//		printf("cmd :%s\r\n",cmd);
		rc = mysql_query(mysql, cmd);
		check_mysql_rc(rc,mysql);
		memset(cmd,0,256);
	}
}



struct my_tests_st my_tests[] = {
  {"insert", insert_recoder, TEST_CONNECTION_DEFAULT, 0, NULL , NULL},
  {NULL, NULL, 0, 0, NULL, NULL}
};

int main(int argc, char *argv[])
{
  	if (argc > 1)
    	get_options(argc, argv);
  	get_envvars();
	unsigned long lasttick;
	
	lasttick = GetTickCount();
  	run_tests(my_tests);
	char cmd[128];
	snprintf(cmd,128,
			"Run for time %dms\n",
			(GetTickCount() - lasttick)
			);
	printf("%s",cmd);	
  	return(exit_status());

	return 0;
}
