#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  int n;
  printf("Parent %d\n",(int)getpid());
  pid_t pid = fork();
  //printf("child =%d\n",(int)pid);
  if(pid==0)
  {
   scanf("%d",&n);
   driver(n);
   wait(10);
  }
  printf("Child has exited,i am a parent\n");
  wait(NULL);
  printf("Parent is exiting\n");
  //printf("Fork = %d\n",(int)pid);
  return 0;
}
