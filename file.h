#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <mysql/mysql.h>

struct data_sys
{
	char time[26];
	float tem;
	float hum;
	int light;
	float con;
}data;
float *temp(float *tem);
float *humidity(float *hum);
int *light(int *lig);
float *con_car_dio(float *con);
char *l_time(char *tim);


#endif

