#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include<stdlib.h>
#include"heap.h"

int compress(int fdr, int fdw, table* th, tree* t);
int decompress(int fdr, int fdw);
tree initial(int fdr, table *th);
int main(int agrc, char* agrv[]){
	if(agrc < 4 || agrc > 4){
		printf("Usage: ./project operation filename1 filename2");
		printf("operation :\n\t-c1 huffman compression\n\t-uc1 huffman decompression\n");
		exit(1);
	}
	if(strcmp(agrv[1], "-c1") == 0){
		int fdr = open(agrv[2], O_RDONLY);
		if(fdr == -1){
			perror("can't open file");
			return errno;
		}
		#define SZ 257
		table th[SZ];
		InitTable(th, SZ);
		tree t2 = initial(fdr, th);
		close(fdr);
		fdr = open(agrv[2], O_RDONLY);
		if(fdr == -1){
			perror("can't open file");
			return errno;
		}
		int fdw = open(agrv[3], O_WRONLY | O_CREAT, S_IRUSR);
		if(fdw == -1){
			perror("Unable to creat file");
			return errno;
		}
		int z = compress(fdr, fdw, th, &t2);
		printf("size of original file %d\n", z);
		struct stat st;
		stat(agrv[3], &st);
		unsigned int size = st.st_size;
		printf("size of compressed file %d\n", size);
	}
	else if(strcmp(agrv[1], "-uc1") == 0){
		int fdr = open(agrv[2], O_RDONLY);
		if(fdr == -1){
			perror("can't open file");
			return errno;
		}
		int fdw = open(agrv[3], O_WRONLY|O_CREAT, S_IRWXU);
		if(fdw == -1){
			perror("can't open file");
			return errno;
		}
		decompress(fdr, fdw);
		struct stat st;
		stat(agrv[2], &st);
		unsigned int size = st.st_size;
		printf("size of compressed file %d\n", size);
		stat(agrv[3], &st);
		unsigned int size1 = st.st_size;
		printf("size of uncompressed file %d\n", size1);
	}
	return 0;
}
