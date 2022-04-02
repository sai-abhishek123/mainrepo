#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 8080

int main(int argc, char const *argv[])
{
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	FILE *p;
	p=fopen("testcase.txt","r");
	int n;
	fscanf(p,"%d",&n);
	int a[n],i;
	for(i=0;i<n;i++)
	{
		fscanf(p,"%d",&a[i]);
	}
	char array[2048]={0};
	int j=0;
	for(i=0;i<n;i++)
	{
		j+=sprintf(&array[j],"%d ",a[i]);
	}
	char b[1024] = {0};
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	// Convert IPv4 and IPv6 addresses from text to binary form
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}
	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
	send(sock , array , strlen(array) , 0 );
	valread = read( sock , b, 1024);
	//printf("%s\n",b );
	return 0;
}