#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/stat.h>  
#include <fcntl.h>
#include <mqueue.h>
#include<string.h>
#include<stdlib.h>

mqd_t mq1;
struct mq_attr mq1_attr;
char buff2;
int msg_prio;
ssize_t len;
int status;


void main(void)
{

    mq1_attr.mq_flags=0;
    mq1_attr.mq_maxmsg=32;
    mq1_attr.mq_msgsize=32;
    mq1_attr.mq_curmsgs=0;

    mq1=mq_open("/mq1",O_RDONLY|O_CREAT,S_IRUSR|S_IWUSR,&mq1_attr);


    len=mq_receive(mq1,&buff2,10,&msg_prio);
    if(len!=-1)
    {
        printf("Received Message=%s\nMsg prio=%d\n",buff2,msg_prio);
        printf("Length of Recevied message=%d\n",len);
    }
    else
    {
        printf("Messege received failed..Error\n");
        perror("Error\n");
        exit(EXIT_FAILURE);
    }


        status=mq_close(mq1);
    if(status==0)
   {

       printf("Messege que closed successfully\n");
   }
   else
   {
        printf("Messege que not closed..Error\n");
        perror("Error\n");
        exit(EXIT_FAILURE);
   }

}


