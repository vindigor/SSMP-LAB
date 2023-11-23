#include <stdio.h>
#include <math.h>

#define SIZE 20

struct fileDetails {
char filename[20];
float filesize;
float nfBlocks;
int startBlock;
int endBlock;
} file[20];

int totalBlocks, availableBlocks;
float sizeOfBlock;

void main() {

int fileno=0;
int currentBlock=0;
char ch,ch1;

printf("Enter the total number of the memory blocks--> ");
scanf("%d", &totalBlocks);
printf("Enter the size of one block--> ");
scanf("%f", &sizeOfBlock);

availableBlocks = totalBlocks;

do {
printf("Enter the file name--> ");
scanf("%s", file[fileno].filename);
printf("Enter the size--> ");
scanf("%f", &file[fileno].filesize);

file[fileno].nfBlocks = ceil(file[fileno].filesize / sizeOfBlock);

if(file[fileno].nfBlocks <= availableBlocks){
file[fileno].startBlock = currentBlock;
file[fileno].endBlock = currentBlock+(file[fileno].nfBlocks - 1);
currentBlock = file[fileno].endBlock + 1;
availableBlocks -= file[fileno].nfBlocks;
fileno++;
} else
printf("no free block available to allocate this file.\n");
printf("Do you want to add more files?\n");
scanf(" %c", &ch);
if(ch != 'y'){
printf("do you want to display the detials?\n");
}
} while(ch == 'Y' || ch == 'y');
scanf(" %c", &ch1);
if (ch1== 'y')
{
printf("File Name|\t File Size|\t Blocks Allocation|\n-------------------------------------------------------------------\n");
for(int i=0; i<fileno; i++){
printf("%s \t %.0f \t\t ", file[i].filename, file[i].filesize);
for(int j=file[i].startBlock; j<=file[i].endBlock; j++)
printf("%d ", j);
printf("\n");
}
}

}
