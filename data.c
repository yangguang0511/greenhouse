/***********************************
功能：各种传感器获取数据
************************************/

#include "file.h"

//获取大棚内温度(12~32)
float *temp(float *tem)
{
	srand((int) time(0));
	while(1)
	{
		*tem = 50.0 * rand()/(RAND_MAX + 1.0);
		sleep(1);
		return tem;
	}
}

//获取大棚内湿度(50~90)
float *humidity(float *hum)
{
	srand((int) time(0));
	while(1)
	{
		*hum = 90.0 * rand()/(RAND_MAX + 1.0);
		sleep(1);
		return hum;
	}
}

//获取大棚内光照强度(8000~12000)
int *light(int *lig)
{
	srand((int) time(0));
	while(1)
	{
		*lig = (int) (15000.0 * rand()/(RAND_MAX + 1.0));
		sleep(1);
		return lig;
	}
}

//获取大棚内的二氧化碳的浓度(10~50)
float *con_car_dio(float *con)
{
	srand((int) time(0));
	while(1)
	{
		*con = 50.0 * rand()/(RAND_MAX + 1.0);
		sleep(1);
		return con;
	}
}

// 获取传感器检测时间
char *l_time(char *tim)
{
	time_t timep;

	time(&timep);
	strcmp(tim,ctime(&timep));

	return tim;
}
