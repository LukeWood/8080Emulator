#include <stdio.h>
#include <stdlib.h>
#include "processor_globals.h"

#include "execute_instruction.c"

void execute_program(unsigned char* buffer,int size);
int execute_instruction(unsigned char* bin, int size);

// Honestly Ignore This it just reads in the binary and passes it off to execute program
int main(int argc, char** argv){
	if(argc == 1){
		printf("Pass a file name as an argument.\n");
		return 1;
	}

	FILE *f = fopen(argv[1],"rb");
	if(f == NULL){
		printf("No file named %s.\n",argv[1]);
		return 1;
	}

	fseek(f,0L,SEEK_END);
	int fsize = ftell(f);
	fseek(f,0L,SEEK_SET);

	unsigned char *bin = malloc(fsize);
	fread(bin,fsize,1,f);
	fclose(f);

	execute_program(bin,fsize);
	
	return 0;
}

//takes the binary file and the length of the array of chars and executes each instruction
void execute_program(unsigned char* bin, int size){
	//initialize all vars
	pc = 0;
	r1=r2=r3=r4=r5=r6=0;
	while(pc < size){
		pc+=execute_instruction(bin,size);
	}

}
