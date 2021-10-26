#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main()
{
        struct sockaddr_in cin;
        int cid,n,byrc;
        char echobuf[32],buf[32];
        unsigned int len;
        cid=socket(PF_INET,SOCK_STREAM,0);
        if(cid==-1)
                perror("SOCKET ERROR");
        memset(&cin,0,sizeof(cin));
        cin.sin_family=AF_INET;
        cin.sin_port=htons(your port number);
        cin.sin_addr.s_addr=inet_addr("your address");
        if(connect(cid,(struct sockaddr*)&cin,sizeof(cin))<0)
        {
                perror("\nconnect failed\n");
                close(cid);
                return 0;
        }
        else
                {
                printf("\nWaiting for server\n");
                byrc=recv(cid,echobuf,31,0);
                printf("\nConnect success\n");

        printf("\nClient \n Enter the message\ntype BYE to end chat\n");
        strcpy(buf,"");
		while(strcmp(buf,"BYE")!=0)
        {
                strcpy(buf,"                      ");
                printf("\nClient:\n");
                scanf("%s",&buf);
                len=strlen(buf);
                send(cid,buf,len,0);
                strcpy(echobuf,"                     ");
                if((byrc=recv(cid,echobuf,31,0))<0)
                        perror("\nReceive failed\n");
                printf("server:%s\n",echobuf);
        }}
        close(cid);
}
