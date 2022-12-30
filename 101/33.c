
#include <stdio.h>
#include <stdlib.h>

void main()
{
	int s = 10;
	int *p_s = &s;
	printf("*p_s = %d\n", *p_s-1);
	printf("p_s = %p\n", p_s);
	printf("&p_s = %p\n", &p_s);
	for (int i=10;i > 0; i--)
	{
		int *p_ss =&s;
		*p_ss=*p_ss-1;	
		printf("*p_ss = %d\n", *p_ss);
	}
 int *pp_ss = &*p_s;
printf("s = %p\n", pp_ss);
printf("s = %d\n", s);
printf("s = %d\n", s);
printf("s = %d\n", s);
   int A[10] = {1,2,3,4,5,6,7,8,9,10};
   int *iter, *end;
   int even[10];
   int evenCounter = 0;

   for (iter=A, end=&A[10]; iter<end; iter++)
   {
       //printf("%d\n", *iter);
       if (*iter%2 ==0)
       {
           even[evenCounter++]=*iter;
        }
    }
}


/*
//Имена файлов и права доступа
#define INPUT_FILE  "/home/tech-3/Рабочий стол/11.txt"
 

void main() {
    FILE *file;
    char buffer[128];
 
    file = fopen(INPUT_FILE, "w");
    fprintf(file, "Hello, World!");
    fclose(file);
    file = fopen(INPUT_FILE, "r");
    fgets(buffer, 127, file);
    printf("%s\n", buffer);
    fclose(file);
 }
*/
