add.o : add.c
		gcc -c $<
subtract.o : subtract.c
		gcc -c $<
multiply.o : multiply.c
		gcc -c $<
divide.o : divide.c
		gcc -c $<
makearc : add.o subtract.o multiply.o divide.o
		ar rcs libtest.a add.o multiply.o subtract.o divide.o
libout : libtest.a
	cd ..;gcc -I./lib -L./lib armain.c -ltest
