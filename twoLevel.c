#include<string.h>
#include<stdlib.h>
#include<stdio.h>
struct
{
char dname[10],fname[10][10];
int fcnt;
}dir[10];
void main() {
    
    int i, j,ch, dcnt, k,num;
    char f[30], d[30];
    char check[30];

    int found=0,ffound=0;
    dcnt = 0;

    while (1) {
        
        printf("\n\tMENU");
        
        printf("\n-------------------------------------\n1. Create Directory\t2. Create File\t3. Delete File");
        printf("\n4. Search File\t\t5. Display\t6. Exit\t\nEnter your choice:  ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                
                
                printf("\nEnter name of directory: ");
                scanf("%s", dir[dcnt].dname);
                strcpy(f,dir[dcnt].dname);
                
             
                for (i = 0; i < dcnt; i++)
                {
                	if (strcmp(dir[dcnt].dname, dir[i].dname) == 0)
                	{
                		printf("\nDirectory already exist");
                		found=1;
                	}
                
                }
                if(found==1)
                break;
                else{
                dir[dcnt].fcnt = 0; 
                dcnt++; 
                printf("Directory created");
                printf("\n\nuser/S5CSB/hrishi/%s/",f);}
                break;

            case 2:
                
                printf("\nEnter name of the directory: ");
                scanf("%s", d);

                
                for (i = 0; i < dcnt; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        printf("Enter name of the file: ");
                        scanf("%s",dir[i].fname[dir[i].fcnt]);
                        num=dir[i].fcnt;
                        strcpy(f,dir[i].fname[dir[i].fcnt]);
                        
                        for(j=0;j<num;j++)
                        {
                        	if (strcmp(dir[i].fname[dir[i].fcnt],dir[i].fname[j])==0)
                        	{
                        		printf("\nFile Already exist!");
                        		ffound=1;
                        	}
                        
                        
                        }
                        if(ffound==1)
                        break;
                        else
                        {
                   
                        dir[i].fcnt++;
                        printf("File created");
                        printf("\n\nuser/S5CSB/hrishi/%s/%s",d,f);}
                        break;
                    }
                }
                if (i == dcnt)
                    printf("Directory %s not found", d);
                break;

            case 3:
                
                printf("\nEnter name of the directory -- ");
                scanf("%s", d);
                
                
                
             
                for (i = 0; i < dcnt; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        
                        if(dir[i].fcnt==0)
                        {
                        printf("No Files to delete in ");
                        printf("\n\n user/S5CSB/hrishi/%s",dir[i].dname);
                        printf("\n");
                        goto jmp;
                        }
                        else{
                        printf("Enter name of the file: ");
                        scanf("%s", f);

                        for (k = 0; k < dir[i].fcnt; k++) {
                            if (strcmp(f, dir[i].fname[k]) == 0) {
                               
                                dir[i].fcnt--;  
                                strcpy(dir[i].fname[k], dir[i].fname[dir[i].fcnt]);
                                printf("File  %s has been deleted",f);
                                goto jmp;

                            }
                        }
                        }
                        printf("File %s Not Found",f);
                        goto jmp;
                        
                    }
                }
               
               printf("Directory %s Not Found",d);
               jmp : break;

            case 4:
               
                printf("\nEnter name of the directory: ");
                scanf("%s", d);

             
                for (i = 0; i < dcnt; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        printf("Enter the name of the file: ");
                        scanf("%s", f);

                        
                        for (k = 0; k < dir[i].fcnt; k++) {
                            if (strcmp(f, dir[i].fname[k]) == 0) {
                                printf("File %s is found", f);
                                printf("\n\n user/S5CSB/hrishi/%s/%s",d,f);
                                goto jmp1;
                            }
                        }
                        printf("File %s Not Found", f);
                        goto jmp1;
                    }
                }
                printf("Directory %s Not Found", d);
                jmp1: break;

            case 5:
                
                if (dcnt == 0)
                    printf("\nNo Directory's ");
                else {
                    printf("\nDirectory\tFiles");
                    for (i = 0; i < dcnt; i++) {
                        printf("\n%s\t\t", dir[i].dname);
                        for (k = 0; k < dir[i].fcnt; k++)
                            printf("\t%s", dir[i].fname[k]);
                    }
                }
                break;

            case 6:
               
                break;
        }
    }
}

