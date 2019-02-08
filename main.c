#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "line.h"

void db(char * say,double a){
	printf("%s:%f\n",say,a);
}

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

void line_helper(int array[][500][3], int x1, int y1, int x2, int y2, int x3, int y3, int octants, int color[], double m){
	
	double slope;

	while(x3 != x2 && y3 != y2){
		slope = ((double)y1 - (double)y3)/((double)x3 - (double)x1);
		switch(octants){
			case 1: 
					if(slope > m){
						//db("slope",slope);
					    //db("y3",y3);
						//db("x3",x3);
						array[y3][x3][0] = color[0];
						array[y3][x3][1] = color[1];
						array[y3][x3][2] = color[2];
						x3 ++;
						//y3 --;
					}else{
					    //db("slope",slope);
					    //db("y3",y3);
						//db("x3",x3);
						array[y3][x3][0] = color[0];
						array[y3][x3][1] = color[1];
						array[y3][x3][2] = color[2];
						x3 ++;
						y3 --;
					}		
			break;
			case 2: //up right
					if(slope > m){
						db("slope",slope);
						//db("y3",y3);
						//db("x3",x3);
						array[y3][x3][0] = color[0];
						array[y3][x3][1] = color[1];
						array[y3][x3][2] = color[2];
						x3 ++;
						y3 --;
					}else{
						db("slope",slope);
						//db("y3",y3);
						//db("x3",x3);
						array[y3][x3][0] = color[0];
						array[y3][x3][1] = color[1];
						array[y3][x3][2] = color[2];
						//x3 ++;
						y3 --;
					}		
			break;
			case 3: //up left
					if(slope < m){
						db("slope",slope);
						//db("y3",y3);
						//db("x3",x3);
						array[y3][x3][0] = color[0];
						array[y3][x3][1] = color[1];
						array[y3][x3][2] = color[2];
						x3 --;
						y3 --;
					}else{
						db("slope",slope);
						//db("y3",y3);
						//db("x3",x3);
						array[y3][x3][0] = color[0];
						array[y3][x3][1] = color[1];
						array[y3][x3][2] = color[2];
						//x3 --;
						y3 --;
					}
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

int drawLine(int array[][500][3], int x1 , int y1, int x2, int y2, int color[]){
	int octants;
	
	if(x2 == x1 && y2 == y1){
				array[y1][x1][0] = color[0];
				array[y1][x1][1] = color[1];
				array[y1][x1][2] = color[2];
	}else{
				//{double m = 1;}
			double m = ((double)y1 - (double)y2) / ((double)x2 - (double)x1);
			db("m",m);
			
				if(y2 <= y1){
					if(x2 >= x1){
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
				
				db("octants",(double)octants);
				
				array[y1][x1][0] = color[0];
				array[y1][x1][1] = color[1];
				array[y1][x1][2] = color[2];
				switch(octants){
						case 1: line_helper(array,x1,y1,x2,y2,x1 + 1,y1 - 1,octants,color,m);
						break;
						case 2: line_helper(array,x1,y1,x2,y2,x1 + 1,y1 - 1,octants,color,m);
						break;
						case 3: line_helper(array,x1,y1,x2,y2,x1 - 1,y1 - 1,octants,color,m);
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
}

void initialize(int array[][500][3], int color[]){

	//char line[20];
	int i, j;
	
	//snprintf(line, sizeof(line), "P3 500 500 255\n");
	//write (file, line, strlen(line));
	
	for(i=0; i < 500; i ++){
		for(j=0; j < 500; j++){
			array[i][j][0] = color[0];
			array[i][j][1] = color[1];
			array[i][j][2] = color[2];
		}		 
	}
}

void push(int array[][500][3],int file){
	char line[20];
	int i,j;

	snprintf(line, sizeof(line), "P3 500 500 255\n");
	write (file, line, strlen(line));
	for(i=0; i < 500; i ++){
			for(j=0; j < 500; j++){
				snprintf(line, sizeof(line), "%d %d %d\n", array[i][j][0], array[i][j][1], array[i][j][2]);
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

fd = open("image.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);

//initialize 

initialize(array,rgb);

//do stuff

//make line red
rgb[0] = 255;
rgb[1] = 0;
rgb[2] = 0;

//drawLine(array, 100, 100, 400, 50, rgb);
//drawLine(array, 50, 100, 100, 50, rgb);
//drawLine(array, 200, 300, 250, 30, rgb);
//drawLine(array, 200, 100, 200, 0, rgb);
drawLine(array, 250, 250, 50, 50, rgb);
drawLine(array, 250, 250, 200, 30, rgb);
//drawLine(array, 100, 100, 400, 50, rgb);
//drawLine(array, 100, 100, 50, 50, rgb);
//drawLine(array, 100, 100, 100, 50, rgb);

push(array,fd);

}
