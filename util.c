#include <stdio.h>
#include <stdlib.h>
//#include <ncurses.h>
#include "simple.h"

void screen(int memory[], int accumulator, int i_c, int i_r, int opcode, int operand)
{
    printf("\nRegister:\n");

    if (accumulator > 0)
        printf("Accumulator\t\t+%4d\n", accumulator);
    else  if (accumulator < 0)
        printf("Accumulator\t\t %05d\n", accumulator);
    else
        printf("Accumulator\t\t+0000\n");

    if (i_c != 0)
        printf("InstructionCounter\t    +%0d\n", i_c);
    else
        printf("InstructionCounter\t  +00\n");

    if (i_r != 0)
        printf("InstructionRegister\t  %0d\n", i_r);
    else
        printf("InstructionRegister\t+0000\n");

    if (opcode != 0)
        printf("OperationCode\t\t   +%0d\n", opcode);
    else
        printf("OperationCode\t\t   00\n");

    if (operand != 0)
        printf("Operand\t\t\t   +%0d\n\n", operand);
    else
        printf("Operand\t\t\t   00\n\n");

    printf("\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9");
    for (int i = 0; i < 100; i++)
    {
        if (i % 10 == 0)
        {
            if (memory[i] == 0)
                printf("\n%-4d+%-7s", i, "0000");
            else if(memory[i] > 0)
                printf("\n%-4d+%-7d", i, memory[i]);
            else
            	printf("\n%-4d%-8d", i, memory[i]);
        }
        else
        {
            if (memory[i] == 0)
                printf("+%-7s", "0000");
            else if (memory[i] > 0)
                printf("+%-7d", memory[i]);
            else
            	 printf("%-7d", memory[i]);
        }
    }
    printf("\n");
}

void readFile(int argc, char *path[], int memory[]){
	FILE *filePointer = fopen(path[1], "r");
	printf("File Name: %s\n",path[1]);
	int i=0;
	if(filePointer == NULL){
		printf("File Not exist\n");
	}else{			
		while(!feof(filePointer)){
			fscanf(filePointer,"%d", &memory[i]);
			i++;
		}
	}
	/*for(int j=0; j<i; j++){
		printf("Index %d Value %d\n",j,memory[j]);
	}*/
	fclose(filePointer);
	
}

int execute(int memory[], int *accumulator, int *i_c, int *i_r, int *opcode, int *operand){
	*i_r = memory[*i_c];
	*i_c = *i_c+1;
	*opcode = (int)*i_r/100;
	*operand = (int)*i_r%100;
	char hold;
	switch(*opcode){
		case READ:
			printf("Enter a number in memory: ");
			scanf("%d",&memory[*operand]);		
			break;
		case WRITE:
			printf("Value stored at %d is: %d\n",*operand,memory[*operand]);
			printf("Enter Y to continue: ");
			fflush(stdin);
			scanf("%s",&hold);
			break;
	 	case LOAD:
			*accumulator = memory[*operand];
			break;
		case STORE:
			memory[*operand] = *accumulator;
			break;
		case ADD:
			*accumulator = *accumulator + memory[*operand];
			break;
 		case SUBTRACT:
			*accumulator = *accumulator - memory[*operand];
			break;
 	 	case DIVIDE:
			*accumulator = *accumulator / memory[*operand];
			break;
		case MULTIPLY:
			*accumulator = *accumulator * memory[*operand];
			break;
	 	case BRANCH:
			*i_c = *operand;
			break;
 	 	case BRANCHNEG:
			if(*accumulator < 0){
				*i_c = *operand;
			}
			break;
  		case BRANCHZERO:
			if(*accumulator == 0){
				*i_c = *operand;
			}
			break;
		case HALT:
			return 0;
			break;
		default: 
			printf("No such instruction exist in simpletron\n");
			return 0;
			break;
	}
		
	return 1;
}







































