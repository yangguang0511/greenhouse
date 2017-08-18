#include "file.h"

void cre_tab()
{
	MYSQL mysql;
	int res = 0;
	char sql[100] = {0};

	mysql_init(&mysql);

	if(mysql_real_connect(&mysql,"localhost","root","123","data_green",0,NULL,0) == NULL)
	{
		printf("connect error:%s\n",mysql_error(&mysql));
		return -1;
	}

	sprintf(sql,"insert in to data values('%s',%f,%f,%d,%f)",data.time,data.tem,data.hum,data.light,data.con);
	res = mysql_real_query(&mysql,sql,strlen(sql));
	if(res < 0)
	{
		printf("query error:%s\n",mysql_error(&mysql));
		return -1;
	}

	mysql_close(&mysql);
}

void read_tab()
{
	MYSQL mysql;
	MYSQL_RES *res;
	MYSQL_ROW *row;
	int res = 0;
	int i = 0;
	int light = 0;
	float tem = 0,hum = 0,con = 0;
	char buf[26] = {0};
	char sql[100] = {"select * from data"};

	mysql_init(&mysql);

	if(mysql_real_connect(&mysql,"localhost","root","123","data_green",0,NULL,0) == NULL)
	{
		printf("connect error:%s\n",mysql_error(&mysql));
		return -1;
	}
	
	res = mysql_real_query(&mysql,sql,strlen(sql));
	if(res < 0)
	{
		printf("query error:%s\n",mysql_error(&mysql));
		return -1;
	}
	
	res = mysql_store_result(&mysql);
	if(row != NULL)
	{
		for(i=0;i<mysql_num_rows(res);i++)
		{
			row = mysql_fetch_row(res);
			strcpy(buf,row[0]);
			tem = atof(row[1]);
			hum = atof(row[2]);
			light = atoi(row[3]);
			con = atof(row[4]);
		}
	}

	mysql_close(mysql);
}	
