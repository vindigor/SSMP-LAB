#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
 FILE *f;
 f=fopen("input.txt","r");
 char name[10];
 char line[100],temp[10],objcode[100],SAS[20],lens[10];
 int SA,len,i=0,j,n,c,locctr;
 
 printf("Enter program name: ");
    scanf("%s", name);
    for (i = 2, j = 0; i < 8, j < strlen(name); i++, j++)
    {
        if (name[j] != line[i])
        {
            printf("Invalid program name.\n");
            break;
        }
    }
printf("\nobj code   Loc\n");
 while(fgets(line,sizeof(line),f)) break;
 printf("****************");
 while(fgets(line,sizeof(line),f))
 {
  if(line[0]!='E')
  {
   c=0;
   n=strlen(line);
   for(i=0;i<n;i++)
   {
    if(line[i]=='^') 
    {
     c++;
     if(c==4) break;
     line[i]=' ';
    }
   }
   //for(i=0;i<n;i++) printf("%c",line[i]);
   printf("\n");
   sscanf(line,"%s%s%s%s",temp,SAS,lens,objcode);
   SA=strtol(SAS,NULL,16); 
   locctr=SA;
   len=strtol(lens,NULL,16);
   //printf("%s/%02X/%02X/%s\n",temp,SA,len,objcode);
   n=strlen(objcode);
   printf("\n");
   c=0;
   for(i=0;i<n;i++)
   {
    if(objcode[i]=='^')
    {
     objcode[i]='\n';
     //printf("->len=%d bytes\n",c/2);
     printf("     %X\n",locctr);
     locctr+=c/2;
     c=0;
     i++;
    }
    c++;
    printf("%c",objcode[i]);
   }
   //printf("->len=%d bytes\n",c/2);
   printf("     %X\n",locctr);
  }
 }
}
