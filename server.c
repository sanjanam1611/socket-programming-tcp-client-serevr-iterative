#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main(int xy)
{
                struct sockaddr_in sin,cin;
                int sid,cid;
                int n,i;
                char line[22],but[32],o[20];
                unsigned int len;
                strcpy(line," ");
                sid=socket(PF_INET,SOCK_STREAM,0);
                if(sid==-1)
                {
                        perror("\nSOCKET FAILED\n");
                        close(sid);
                        return 0;
                }
                else
                        printf("\nSOCKET SUCCESS\n");
                memset(&sin,0,sizeof(sin));
                sin.sin_family=AF_INET;
                sin.sin_port=htons(your_portnumber);
                sin.sin_addr.s_addr=inet_addr("your address");
                if(bind(sid,(struct sockaddr *)&sin,sizeof(sin))<0)
                {
                        perror("\nBind failed\n");
                        close(sid);
                        return 0;
                }
                else
                        printf("\nBind succesful\n");
				 if(listen(sid,2)<0)
                {
                        perror("Listen failed");
                        close(sid);
                        return 0;
                }
                else
                        printf("\nListen sucessful\n");
                printf("\nServer started\t ");
                n=sizeof(cin);
                strcpy(o," ");
                for(i=0;i<xy;i++){
                if((cid=accept(sid,(struct sockaddr *)&cin,&n))<0)
                {
                        perror("Accept failed");
                        close(sid);
                        return 0;
                }
                else{
                        printf("\nAccept successful\n");

                        send(cid,but,strlen(o),0);
                        printf("\niteration number %d:\n",i+1);
                        }
				 while(strcmp(but,"BYE")!=0)
                {

                        strcpy(line,"                             ");
                        len=recv(cid,line,31,0);
                        if((len)<0)
                        {
                                perror("Receive failed");
                                return 0;
                        }

                        printf("client%d:%s\n server:",i+1,line);

                        strcpy(but,"                 ");
                        scanf("%s",&but);
                        send(cid,but,strlen(but),0);
                }
                strcpy(but,"                 ");
                }
				shutdown(sid,2);
                close(sid);
}
