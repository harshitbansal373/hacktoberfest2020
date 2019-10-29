#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include"heap.h"

#define MAX 257

void preorder(tree* t, int* arr, int* n){
	if(*t == NULL)
		return;
	if((*t)->left == (*t)->right)
		arr[(*n)++] = 1;
	else
		arr[(*n)++] = 0;
	preorder(&((*t)->left), arr, n);
	preorder(&((*t)->right), arr, n);
}
void writeleaves(tree* t, int fdw){
	if(*t == NULL)
		return;
	if((*t)->left == NULL && (*t)->right == NULL){
		write(fdw, &((*t)->d.ch), sizeof(char));
	}
	writeleaves(&((*t)->left), fdw);
	writeleaves(&((*t)->right), fdw);
}
void header(int fdw, int* arr, int n){
	int i;
	int bits = 0;
	unsigned char w;
	for(i = 0; i < n; i++){
		if(arr[i] == 1){
			w = w | 0x01;
		}
		else if(arr[i] == 0)
			w = w & 0xfe;
		bits++;
		if(bits == 8){
			write(fdw, &w, sizeof(char));
			bits = 0;
			w = '\0';
		}
		else
			w = w << 1;
	}
	char last = bits  + '0';
	if(bits < 8){
		while(bits < 7){
			w = w & 0xfe;
			w = w << 1;
			bits++;
		}
		write(fdw, &w, sizeof(char));
	}
	char no = '\0';
	write(fdw, &last, sizeof(char));
	write(fdw, &no, sizeof(char));
}
/*void header(int fdw, tree* t, char w){
	unsigned char eof = 256;
	static int i = 0;
	if(*t == NULL)
		return;
	if((*t)->isleaf == 1){
		w = w | 0x01;
		i++;
		if(i == 8){
			write(fdw, &w, sizeof(char));
			i = 0;
			w = '\0';
		}
		else{
			w = w << 1;
		}
	}
	else if((*t)->isleaf == 0){
	w = w & 0xfe;
	i++;
	if(i == 8){
		write(fdw, &w, sizeof(char));
		i = 0;
		w = '\0';
	}
	else{
		w = w << 1;
	}
	}
	header(fdw, &((*t)->left), w);
	header(fdw, &((*t)->right), w);
	if(i < 8){
		while(i < 8){
			w = w & 0xfe;
			i++;
		}
		write(fdw, &w, sizeof(char));
	}
	write(fdw, &eof, sizeof(char));
}
void header2(int fdw, tree* t){
	if(*t == NULL)
		return;
	if((*t)->isleaf == 1){
		write(fdw, &((*t)->d.ch), sizeof(char));
	}
	header2(fdw, &((*t)->left));
	header2(fdw, &((*t)->right));
	write(fdw, '\0', sizeof(char));
}*/
int compress(int fdr, int fdw, table* th, tree* t){
	int index, j = 0, len;
	unsigned char ch, str[1000], wrtbyte;
	int arr[1024];
	int n = 0;
	preorder(t, arr,&n);
	header(fdw, arr, n);
	writeleaves(t, fdw);
	int c = 0;
	int bits = 0;
	while((n = read(fdr, &ch, sizeof(char)))){
		c++;
		index = (int)ch;
		strcpy((char*)str, th[index].str);
		len = strlen((char*)str);
		j = 0;
		while(j < len){
			if(str[j] == '1'){
				wrtbyte = wrtbyte | 0x01;
			}
			else if(str[j] == '0'){
				wrtbyte = wrtbyte & 0xfe;
			}
			bits++;
			if(bits == 8){
				write(fdw, &wrtbyte, sizeof(char));
				bits = 0;
				wrtbyte = '\0';
			}
			else{
				wrtbyte = wrtbyte << 1;
			}
			j++;
		}
	}
	char last = bits + '0';
	if(bits < 8){
		while(bits < 7){
			wrtbyte = wrtbyte & 0xfe;
			wrtbyte = wrtbyte << 1;
			bits++;
		}
		if(wrtbyte != '\0')
			write(fdw, &wrtbyte, sizeof(char));
	}	
	write(fdw, &last, sizeof(char));
	return c;
}
tree initial(int fdr, table *th){
	data d[MAX];
		tree t1, t2, t3, t4;
		heap h;
		InitHeap(&h);
		int i, c2 = 0;
		for(i = 0; i < MAX; i++)
			d[i].count = 0;
		unsigned char ch;
		int index;
		while(read(fdr, &ch, sizeof(char))){
			index = (int)ch;
			d[index].ch = ch;
			d[index].count++;
		}
		for(i = 0; i < MAX; i++){
			if(d[i].count != 0){
				t1 = CreateTreeOfOneNode(d[i]);
				InsertInHeap(&h, &t1);
				c2++;
			}
		}
		while(!IsHeapEmpty(&h)){
			if(!IsHeapEmpty(&h))
				t2 = RemoveFromHeap(&h);
			if(!IsHeapEmpty(&h))
				t3 = RemoveFromHeap(&h);
			else{
				break;
			}
			t4 = CreateTreeFromTwoTree(&t2, &t3);
			InsertInHeap(&h, &t4);
		}
		char str[1024];
		CreateTable(th, &t2, str, 0);
	return t2;
}
