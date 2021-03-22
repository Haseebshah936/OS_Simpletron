#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

void screen(int memory[], int accumulator, int i_c, int i_r, int opcode, int operand);
void readFile(int argc, char *path[], int memory[]);
int execute(int memory[], int *accumulator, int *i_c, int *i_r, int *opcode, int *operand);

int main(int argc ,char *argv[])
{

	if(argc != 2){
		fprintf(stderr , "No File Name Found Pass File Name After %s \n", argv[0]); 
		return -1;
	}
    int memory[100] = {0, 0, 0, 0};
    int accumulator = 0;
    int i_c = 0;
    int i_r = 0;
    int opcode = 0;
    int operand = 0;
    int state = 0;
    printf("Enter '0' To execute instruction by Instruction or '1' To execute all instruction: ");
    scanf("%d", &state);
    int exit = 1;
    
    screen(memory, accumulator, i_c, i_r, opcode, operand);
    readFile(argc, argv, memory);
    while(exit){
    	if( !system("cls")){
    		
    	}
    	else{
    		 system("clear");
    	}
        screen(memory, accumulator, i_c, i_r, opcode, operand);
        if(state == 0){
        	printf("Enter '0' To execute an Instruction or '1' To execute all instruction: ");
        	scanf("%d", &state);
        }
	exit = execute(memory, &accumulator, &i_c, &i_r, &opcode, &operand);
   }
    
    return 0;
}


