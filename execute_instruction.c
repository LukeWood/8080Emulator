#include <stdlib.h>
#include "processor_globals.h"

int execute_instruction(unsigned char*bin, int size);

int execute_instruction(unsigned char*bin, int size){
  unsigned char current_instruction = bin[pc];

  putchar(current_instruction);
	return 1;
}
