#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main(){
	void *handle;
	int (*add)(int,int),(*subtract)(int,int),(*multiply)(int,int),
	    (*divide)(int,int);
	char *error;

	handle = dlopen("./lib/libtest.so",RTLD_LAZY);
	if(!handle){
		fputs(dlerror(),stderr);
		exit(1);
	}

	add = dlsym(handle,"add");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s",error);
		exit(1);
	}
	subtract = dlsym(handle,"subtract");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s",error);
		exit(1);
	}
	multiply = dlsym(handle,"multiply");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s",error);
		exit(1);
	}
	divide = dlsym(handle,"divide");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s",error);
		exit(1);
	}

	printf("add = %d\n",(*add)(3,2));
	printf("subtract = %d\n",(*subtract)(3,2));
	printf("multiply = %d\n",(*multiply)(3,2));
	printf("divide = %d\n",(*divide)(3,2));
}
