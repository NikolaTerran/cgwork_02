#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "line.h"

int* sys_random(int size){
	int *buffer;
	buffer = malloc(sizeof(int) * size );
	
	printf("initiating...this may take several minites\n");
	
	FILE* file = fopen("/dev/urandom", "r");
	fread(buffer, sizeof(int), size ,file);
	
	//close(file);
	//printf("wut\n");
	return buffer;
}

void line_helper(int x1, int y1, int x2, int y2, int x3, int y3, int octants, int * color, int m){
	
	double slope;
	
	while(x3 != x2 && y3 != y2){
		switch(octants){
			case 1: slope = (y3 - y1)/(x3 - x1);
					if(slope >= m){
						array[x3][y3][0] = color[0];
						array[x3][y3][1] = color[1];
						array[x3][y3][2] = color[2];
						line_helper(x1,y1,x2,y2,x3 + 1,y3 + 1,color,m);
					}else{
						array[x3][y3 - 1][0] = color[0];
						array[x3][y3 - 1][1] = color[1];
						array[x3][y3 - 1][2] = color[2];
						line_helper(x1,y1,x2,y2,x3 + 1,y3,color,m);
					}		
			break;
			case 2: //up right
			break;
			case 3: //up left
			break;
			case 4: //left up
			break;
			case 5: //left down
			break;
			case 6: //down left
			break;
			case 7: //down right
			break;
			case 8: //right down
			break;
		}
	}
}

int drawLine(int x1 , int y1, int x2, int y2, int * color){
	int octants;
	
	double m = (y1 - y2) / (x2 - x1);
	
	if(y2 < y1){
		if(x2 > x1){
			if( m <= 1 ){
			     octants = 1;
			}else{
			     octants = 2;
			}
		}else{
			if( m <= -1 ){
			     octants = 3;
			}else{
			     octants = 4;
			}
		}
	}else{
	   if(x2 < x1){
			if( m <= 1 ){
			     octants = 5;
			}else{
			     octants = 6;
			}
		}else{
			if( m <= -1 ){
			     octants = 7;
			}else{
			     octants = 8;
			}
		}
	}
	
	array[x1][y1][0] = color[0];
	array[x1][y1][1] = color[1];
	array[x1][y1][2] = color[2];
	switch(octants){
			case 1: line_helper(x1,y1,x2,y2,x1 + 1,y1 + 1,color,m);
					 
			//right up
			break;
			case 2: //up right
			break;
			case 3: //up left
			break;
			case 4: //left up
			break;
			case 5: //left down
			break;
			case 6: //down left
			break;
			case 7: //down right
			break;
			case 8:// right down
			break;
			}
}

void initialize(int file, int * colour){

	char line[20];
	int i, j;
	
	snprintf(line, sizeof(line), "P3 500 500 255\n");
	write (file, line, strlen(line));
	
	for(i=0; i < 500; i ++){
		for(j=0; j < 500; j++){
			snprintf(line, sizeof(line), "%d %d %d\n", colour[0], colour[1], colour[2]);
			write(file, line, strlen(line));
		}		 
	}
}



int main(){

int fd, i, j , k;
int rgb[3];

rgb[0] = 255;
rgb[1] = 255;
rgb[2] = 255;

int array[500][500][3];
array = malloc(sizeof(int) * 500 * 500 * 3);

fd = open("image.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);

initialize(fd, rgb);

}
