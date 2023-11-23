#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int count = 0;

int updateSYM(char sym[], int LOCCTR) {
	int flag = 0;
	char sym1[25], add[25];
	FILE *symtab = fopen("symtab.txt","a+");
	if(count== 0) {
		fprintf(symtab, "%s %x\n", sym, LOCCTR);
		count++;
		fclose(symtab);
		return -1;
	}	
	
	while(feof(symtab)!=1){
		fscanf(symtab, "%s %s\n", sym1, add);		
		if(strcmp(sym1, sym) == 0) {
			//printf("\n%s %x", sym,  (int)strtol(add, NULL, 16));
			flag = 1;
			break;
		}
	}
	
	if (flag == 1) {
	fclose(symtab);
	return 0;
	}
	else if(flag == 0) {
		fprintf(symtab, "%s %x\n", sym, LOCCTR);
		fclose(symtab);
		count++;
		return 1;	
	}
}

int searchOP(char opcode[], int LOCCTR) {
	int flag = 0;
	char op[25], code[25];
	FILE *optab = fopen("optab.txt","r");
	
	while(feof(optab)!=1){
		fscanf(optab, "%s %s\n", op, code);		
		if(strcmp(op, opcode) == 0) {
			//printf("\n%s %x", op,  (int)strtol(code, NULL, 16));
			flag = 1;
			return flag;
		}
	}
	return flag;
	fclose(optab);
}

void main() {
	int LOCCTR, size;
	char START[25];

	// Input
	FILE *input = fopen("input.txt","r");
	
	// Output
	FILE *intermediate = fopen("intermediate.txt","w");
	FILE *length = fopen("length.txt","w");
	
	char label[25], opcode[25], operand[25];
	printf("Loc\t Len\t Label\t Opcode\t Operand\n");
	while(feof(input)!=1){
		fscanf(input, "%s\t\t%s\t\t%s", label, opcode, operand);
		//printf("\n%s", label);
		//printf("\t%s", opcode);
		//printf("\t%s", operand);
		
		if(strcmp(opcode, "START") == 0) {
			strcpy(START, operand);
			LOCCTR = (int)strtol(operand, NULL, 16); 
			//printf("\nSTART : %d", LOCCTR);	
			
			fprintf(intermediate, "%s %s %x\n", label, opcode, LOCCTR);
		} else {			
			int opStatus = searchOP(opcode, LOCCTR);
			//printf("\nopcode status: %d", opStatus);
			
			
			if (strcmp(label, "$") != 0) {
				int symStatus = updateSYM(label, LOCCTR);
				//printf("\nlabel status: %d", symStatus);
				if(symStatus == 0) {
					printf("\nERROR : Duplicate Symbol");
					break;
				}
			} 
			
			if(opStatus == 1 || strcmp(opcode, "END") == 0) size = 3;
			else if(strcmp(opcode, "WORD") == 0) size = 3;
			else if(strcmp(opcode, "RESW") == 0) size = 3 * (int)strtol(operand, NULL, 16);
			else if(strcmp(opcode, "RESB") == 0) size = (int)strtol(operand, NULL, 16);
			else if(strcmp(opcode, "BYTE") == 0) size = strlen(operand) - 3;
			else if(opStatus == 0) {
				printf("\nERROR : Invalid Code");
				break;
			} 
			fprintf(intermediate, "%x %d %s %s %s\n", LOCCTR, size, label, opcode, operand);	
			printf("\n%x\t %d\t %s\t %s\t %s", LOCCTR, size, label, opcode, operand);
			//printf("\nIncrementing LOCCTR");
	
			
			if(strcmp(opcode, "END") == 0) break;
			
			LOCCTR += size;
		}			
	}
	printf("\n");
	fprintf(length, "%x\n", LOCCTR - (int)strtol(START, NULL, 16) );
	
	// Close Files
	fclose(input);
	fclose(intermediate);
	fclose(length);
}
