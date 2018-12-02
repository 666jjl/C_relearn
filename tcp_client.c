//
//  client.c
//  C_Test
//
//  Created by junjie 李 on 2018/9/9.
//  Copyright © 2018年 junjie 李. All rights reserved.
//

#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
//#include <arpa/inet6.h>


#define PORT 9990
#define SIZE 1024

int main(int argc, char **argv)
{
    struct sockaddr_in6 dest;
    int ret;
    int sockfd;
    char buf[SIZE] = {0};
    if (argc != 3) {
        printf
            ("参数格式错误！正确用法如下：\n/t/t%s IP地址 端口\n/t比如:/t%s ::1 7777\n此程序用来从某个 IP 地址的服务器某个端口接收最多 1023 个字节的消息\n",
             argv[0], argv[0]);
        exit(0);
    }
    /* 创建一个 socket 用于 tcp 通信 */
    sockfd = socket(AF_INET6, SOCK_DGRAM, 0);   //创建和服务器连接套接字
    if(sockfd < 0)
    {
        perror("socket");
        exit(errno);
    }
    printf("connect remote port : %s\n", argv[2]);
    printf("connect remote dest = %s\n", argv[1]);
    bzero(&dest, sizeof(dest));
    
    dest.sin6_family = AF_INET6;  /* Internet地址族 */
    dest.sin6_port = htons(atoi(argv[2]));  /* 端口号 */
    //dest.sin6_dest = in6dest_any;   /* IP地址 */
    if( inet_pton(AF_INET6, argv[1], &dest.sin6_addr) < 0 ){
        perror(argv[1]);
        exit(errno);
    }
    
    ret =  connect(sockfd,  (struct sockaddr *)&dest, sizeof(dest));  //连接服务器
    if(ret != 0)
    {
        perror("connect");
        printf("errno=%d\n",errno);
        exit(errno);
    }
    
    printf("成功连接到一个服务器\n");
    
    
    bzero(buf,SIZE);
    while(1)        //向服务器发送数据，并接收服务器转换后的大写字母
    {
        printf("请输入你相输入的：");
        scanf("%s", buf);
        send(sockfd, buf, strlen(buf), 0);
        
        recv(sockfd, buf, strlen(buf), 0);
        
        printf("buf = %s\n", buf);
        if(strncmp(buf, "end", 3) == 0)     //当输入end时客户端退出
        {
            break;
        }
    }
    close(sockfd);
    
    return 0;
}


