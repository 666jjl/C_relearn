#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
int main(int argc,char *argv[])
{
	int mysocket,len;
	int i=0;
	struct sockaddr_in6 addr;
	int addr_len;
	char msg[1600];

	if (argc != 3) {
        printf
            ("参数格式错误！正确用法如下：\n
            	/t/t%s IP地址 端口\n
            	/t比如:/t%s ::1 7777\n
            	此程序用来从某个 IP 地址的服务器某个端口接收最多 1023 个字节的消息\n",
             argv[0], argv[0]);
        exit(0);
    }

	if((mysocket=socket(AF_INET6,SOCK_DGRAM,0))<0)
	{
		perror("error:");
		return(1);
	}
	else
	{
		printf("socket created ...\n");
		printf("socket id :%d \n",mysocket);
		printf("rmote ip : %s\n",argv[1]);
		printf("remote port :%d \n",argv[2]);
	}
 
	addr_len=sizeof(struct sockaddr_in6);
	bzero(&addr,sizeof(addr));
	addr.sin6_family=AF_INET6;
	addr.sin6_port=htons(REMOTEPORT);
	inet_pton(AF_INET6,REMOTEIP,&addr.sin6_addr);
 
	//while(1)
	//{
		bzero(msg,sizeof(msg));
		memset(msg,'1',1580);
		for(i=0;i<5;i++){
			if(sendto(mysocket,msg,sizeof(msg),0,(struct sockaddr *)&addr,addr_len)<0)
			{
				printf("error");
				return(1);
			}
		}
		
		//len=recvfrom(mysocket,msg,sizeof(msg),0,(struct sockaddr *)&addr,(socklen_t*)&addr_len);
		//printf("%d:",i);
		//i++;
		//printf("Received message : %s\n",msg);
	//}
}
