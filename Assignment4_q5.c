/******************************************************************************
Madhuri Mahajan
5.Write a program that implements threads synchronization using pthread spinlock techniques.
*******************************************************************************/
#define _XOPEN_SOURCE 600
#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<bits/types.h>
#include<sys/types.h>



static pthread_spinlock_t spinlock;
volatile int slock;




void *spinlockThread(void *i)
{
int rc;
int count=0;



printf("Entered thread %d,getting Spin lock\n",(int *)i);



rc=pthread_spin_lock(&spinlock);



printf("%d Thread unlock the spin lock\n",(int *)i);
rc=pthread_spin_lock(&spinlock);



printf("%d thread complete\n",(int *)i);
return NULL;
}



int main(){
int rc=0;
pthread_t thread,thread1;



if(pthread_spin_init(&spinlock,PTHREAD_PROCESS_PRIVATE!=0))
perror("init");

printf("Main,get spin lock\n");
rc=pthread_spin_lock(&spinlock);



printf("create the thread\n");
rc=pthread_create(&thread,NULL,spinlockThread,(int *)1);



printf("Main,wait a bit holding the spin lock");
rc=pthread_spin_unlock(&spinlock);



if(rc==0)
printf("\nThread successfully unlocked");
else
printf("\nThread unsuccessfully unlocked");
printf("wait for thread to end\n");



return 0;
}