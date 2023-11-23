#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct fileDetails {
char fname[20];
float fsize;
float nfBlocks;
int indexBlock[100];
} file[20];

int totalBlocks, availableBlocks;
int block[100];
float sizeOfBlock;

void main() {

int file_no=0;
int currentBlock;
char ch,ch1;

printf("Enter the total number of the memory blocks--> ");
scanf("%d", &totalBlocks);
printf("Enter the size of one block--> ");
scanf("%f", &sizeOfBlock);

availableBlocks = totalBlocks;

do {
printf("Enter the file name--> ");
scanf("%s", file[file_no].fname);
printf("Enter the size--> ");
scanf("%f", &file[file_no].fsize);

file[file_no].nfBlocks = ceil(file[file_no].fsize / sizeOfBlock);

if(file[file_no].nfBlocks <= availableBlocks){
for(int i=0; i<=file[file_no].nfBlocks; ){
currentBlock = rand() % totalBlocks;
if(block[currentBlock] != 1){
file[file_no].indexBlock[i] = currentBlock;
block[currentBlock] = 1;
i++;
}
}
availableBlocks -= file[file_no].nfBlocks + 1;
file_no++;
} else
printf("no free block available to allocate this file.\n\n");
printf("Do you want to add more files?\n");
scanf(" %c", &ch);
if(ch != 'y')
printf("do you want to display the detials?\n");
} while(ch == 'Y' || ch == 'y');
scanf(" %c", &ch1);
if (ch1== 'y')
{
printf("\nFile Name \t File Size \t Index Block \t Blocks Allocation\n-------------------------------------------------------------------\n");
for(int i=0; i<file_no; i++){
printf("%s \t %.0f \t\t %d \t\t ", file[i].fname, file[i].fsize, file[i].indexBlock[0]);
for(int j=1; j<=file[i].nfBlocks; j++)
printf("%d ", file[i].indexBlock[j]);
printf("\n");
}
}

}
