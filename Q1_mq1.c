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
char buff1='m';
int msg_prio;
int status;

void main(void)
{


FILE *fp;
fp = fopen("dictionary.txt","w");
if(fp==NULL)
{
printf("Error\n");
exit(EXIT_FAILURE);
}

    mq1_attr.mq_flags=0;
    mq1_attr.mq_maxmsg=32;
    mq1_attr.mq_msgsize=32;
    mq1_attr.mq_curmsgs=0;

    mq1=mq_open("mq1",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR,&mq1_attr);

   status= mq_send(mq1,&buff1,10,0);

   if(status==0)
   {

       printf("Messege sent successfully\n");
   }
   else
   {
        printf("Messege sent failed..Error\n");
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


