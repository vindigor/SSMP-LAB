#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct single{
	char dname[10],fname[10][10];
	int count;
};
void main(){
	struct single dir;
	int i,op;
	char find[30],con='y',str[10];;
	dir.count = 0;
	printf("\nEnter directory-name:");
	scanf("%s", dir.dname);
	do{
		printf("\n  File Operation Menu\n");
		printf("___________________________\n");
		printf("1. Create\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("4. Display\n");
		printf("\nEnter your choice: ");
		scanf("%d",&op);
			if(op==1)
				{
				int flag5=1;
				printf("\nEnter the name of the file -- ");
				scanf("%s",str);
				for(i=0;i<=dir.count;i++){
					if(strcmp(str, dir.fname[i])==0){
						flag5=0;
						break;
					}
				}
				if (flag5==0){	
					printf("File already exists.\n");
				}
				else{
					strcpy(dir.fname[dir.count],str);
					dir.count++;
				}
				}
			else if(op==2)
				{
				printf("\nEnter the name of the file: ");
				scanf("%s",find);
				int flag=0;
				for(i=0;i<dir.count;i++){
					if(strcmp(find, dir.fname[i])==0){
						printf("File %s is deleted ",find);
						strcpy(dir.fname[i],dir.fname[dir.count-1]);
						flag=1;
					} 
				}
				if(flag==0)
					printf("File %s not found",find);
				else
					dir.count--;
				}
			else if(op==3) 
				{
				printf("\nEnter file-name to be searched:");
				scanf("%s",find);
				int flag1=0;
				for(i=0;i<dir.count;i++){
					if(strcmp(find, dir.fname[i])==0){
						printf("File %s found ", find);
						flag1=1;
					}
				}
				if(flag1==0)
					printf("File %s not found",find);
				}
			else if(op==4) 
				{
				if(dir.count==0)
					printf("\nDirectory Empty");
				else{
					printf("\nFile\n_________");
					for(i=0;i<dir.count;i++){
						printf("\n%s/%s\n",dir.fname[i],dir.dname);
					}
				}
				}
	printf("\ndo you want to continue: ");
	scanf("%s",&con);
	}while(con=='y');
}
