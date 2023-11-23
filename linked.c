#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct fileDetails {
	char fname[20];
	float fsize;
	float nfBlocks;
	int fileBlock[100];
} file[20];
int totalBlocks, availableBlocks;
int block[100];
float sizeOfBlock;

void main() {
	
	int fileno=0;
	int currentBlock;
	char ch,ch1;
	
	printf("Enter the total number of the memory blocks--> ");
	scanf("%d", &totalBlocks);
	printf("Enter the size of one block--> ");
	scanf("%f", &sizeOfBlock);
	
	availableBlocks = totalBlocks;
	
	do {
		printf("\nEnter the file name--> ");
		scanf("%s", file[fileno].fname);
		printf("Enter the size--> ");
		scanf("%f", &file[fileno].fsize);
		
		file[fileno].nfBlocks = ceil(file[fileno].fsize / sizeOfBlock);
		
		if(file[fileno].nfBlocks <= availableBlocks){
			for(int i=0; i<file[fileno].nfBlocks; ){
				currentBlock = rand() % totalBlocks;
				if(block[currentBlock] != 1){
					file[fileno].fileBlock[i] = currentBlock;
					block[currentBlock] = 1;
					i++;
				}
			}
			availableBlocks -= file[fileno].nfBlocks;
			fileno++;
		} else
			printf("There are no free blocks to allocate this file.\n");
		printf("Do you want to add more files?\n");
		scanf(" %c", &ch);
		if(ch != 'y')
		printf("do you want to display the detials?\n");
	} while(ch == 'Y' || ch == 'y');
	scanf(" %c", &ch1);
	if (ch1== 'y')
	{
	printf("\nFile Name|\t File Size|\t Blocks Allocation|\n-----------------------------------------------------\n");
	for(int i=0; i<fileno; i++){
		printf("%s \t %.0f \t\t ", file[i].fname, file[i].fsize);
		for(int j=0; j<file[i].nfBlocks; j++)
			printf("%d ", file[i].fileBlock[j]);
		printf("\n");
	}
	}
	
}
