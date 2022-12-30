#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


void main()
{
/*
if (_mkdir("08") == 0) 
{
        printf("Folder created\n");
    } 
else {
        perror("Error");
    }

*/


struct stat st = {0};

if (stat("/home/tech-3/Рабочий стол/101/2", &st) == -1) {

    mkdir("/home/tech-3/Рабочий стол/101/2", 0777);
	printf("Folder created\n");
}
else {
        perror("Error\n");
    }

char user[50] = {"Эх, была, не была..."};

printf("%s\n",user);
printf("Length: %d\n", (int)(sizeof(user)));
printf("Length of array: %d\n", (int)( sizeof(user) / sizeof(user[0]) ));
int t = 0;
for (int(i)=0;user[i]!='\0'; i++)
	{
	t++;
	printf("%c - %d = %d\n", user[i],(int)(sizeof(user[i])),t);
		
	};

printf("%d\n", (int) (strlen(user)));
/*
for(int i=0; i<strlen(text); i++)
{
  if(text[i]=='a')
    text[i] = 'e';
}
*/
}
