#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


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

int main(){

int fd, i,j , k;
char line[20];
int rgb[3];

int int_buffer;

int size = 750000;
int * buffer = sys_random(size);

fd = open("image.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);
snprintf(line, sizeof(line), "P3 500 500 255\n");
write (fd, line, strlen(line));

/*
FILE* entropy;
entropy = fopen("/dev/urandom", "rb");
printf("entropy: %d\n",entropy);
*/

k = 0;

int random1, random2, random3;

	for(i=0; i<500; i ++){
		for(j=0; j<500; j++){
			printf("processing: %d/75000\n",k);
	/*
			random1 = fread(&int_buffer, sizeof(int), 1, entropy);
			random2 = fread(&int_buffer, sizeof(int), 1, entropy);
			random3 = fread(&int_buffer, sizeof(int), 1, entropy);
	*/		
			//printf("random1: %d\n",random1);
			
			int random1 = abs(buffer[k] % 255);
			k++;
			printf("processing: %d/75000\n",k);
			int random2 = abs(buffer[k] % 255);
			k++;
			printf("processing: %d/75000\n",k);
			int random3 = abs(buffer[k] % 255);
			k++;
			printf("processing: %d/75000\n",k);
			
			
			rgb[0] = random1;
			rgb[1] = random2;
			rgb[2] = random3;
			snprintf(line, sizeof(line), "%d %d %d\n", rgb[0], rgb[1], rgb[2]);
			write(fd, line, strlen(line));
		}
			 
	}
	printf("done!\n");
}
