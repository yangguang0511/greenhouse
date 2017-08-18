#include "file.h"

#define PORT 6666

int main()
{
	int sock = 0;
	int newsock = 0;
	int ret = 0;
	int size = 0;
	struct sockaddr_in clientaddr,seraddr;

	memset(&clientaddr,0,sizeof(clientaddr));
	memset(&seraddr,0,sizeof(seraddr));
	seraddr.family = AF_INET;
	seraddr.port = PORT;
	seraddr.sin_addr.s_addr = INADDR_ANY;
	size = sizeof(seraddr);

	sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock < 0)
	{
		perror("sock");
		exit(-1);
	}

	ret = bind(sock,(struct sockaddr *)&seraddr,size);
	if(ret < 0)
	{
		perror("bind");
		exit(-1);
	}

	ret = listen(sock,5);
	if(ret < 0)
	{
		perror("listen");
		exit(-1);
	}

	newsock = accept(sock,(struct sockaddr *)&clientaddr,&size);
	if(newsock < 0)
	{
		perror("accept");
		exit(-1);
	}

	while(1)
	{
		ret = recv(newsock,&data,sizeof(data),0);
		if(ret < 0)
		{
			perror("recv");
			exit(-1);
		}
		//放入数据库（数据库函数）
		memset(&data,0,sizeof(data));
	}

	close(sock);
	close(newsock);

	return 0;
}
