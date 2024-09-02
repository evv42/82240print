#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(int argc, char** argv){

	if(argc != 2)return 1;

	int x,y,n;
	unsigned char *data = stbi_load(argv[1], &x, &y, &n, 1);

	if(data == NULL)return 2;

	//init printer
	putchar(27);
	putchar(255);
	fflush(stdout);
	sleep(2);
	
	//graphics LF
	putchar(4);
	fflush(stdout);
	sleep(1);
	
	unsigned char* line = malloc(166);
	memset(line, 0, 166);
	
	for(int cur_lin=0; cur_lin<(y+8); cur_lin+=8){
		for(int i=7; i>=0; i--){
			for(int cur_x=0; cur_x < (166 > x ? x:166); cur_x++){
				line[cur_x] = line[cur_x] << 1;
				line[cur_x] |= data[((cur_lin+i)*x)+cur_x] > 127 ? 0:1;
			}
		}
		//send the processed line to the printer
		putchar(27);
		putchar(166);
		fflush(stdout);
		for(int i=0; i<166; i++){
			putchar(line[i]);fflush(stdout);usleep(25000);
			
		}
		//graphics LF
		putchar(4);
		fflush(stdout);
		sleep(3);
	}
	
	return 0;
}
