/*数据采集和发送*/
#include "file.h"

#define PORT 6666
#define IP "192.168.0.102"

//数据采集
void datarecv()
{
	char time[26] = 0;
	float tem = 0,hum = 0,con = 0;
	int lig = 0;

	time = l_time(time);
	tem = *(temp(&tem));
	hum = *(humidity(&hum));
	con = *(con_car_dio(&con));
	lig = *(light(&lig));

	strcmp(data.time,time);
	data.tem = tem;
	data.hum = hum;
	data.con = con;
	data.light = lig;

//	printf("%s %g %g %g %d\n",data.time,data.tem,data.hum,data.con,data.light);
}

//数据发送
int main()
{
	int sock = 0;
	int ret = 0;
	int size = 0;
	struct sockaddr_in seraddr;

	mseraddr.family = AF_INET;
	seraddr.port = PORT;
	mseraddr.sin_addr.s_addr = inet_addr(IP);
	size = sizeof(myaddr);

	sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock < 0)
	{
		perror("socket");
		exit(-1);
	}

	ret = connect(sock,(struct sockaddr *)&seraddr,size);
	if(ret < 0)
	{
		perror("connect");
		exit(-1);
	}

	while(1)
	{
		ret = send(sock,&data,sizeof(data),0);
		if(ret < 0)
		{
			perror("send");
			exit(-1);
		}
		sleep(1);
	}

	close(sock);

}
