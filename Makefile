shlib :
		cd lib;
		make;
		cd ..;
		gcc -shared -Wl,-soname,libtest.so.1 -o libtest.so.1.0.1 add.o subtract.o multiply.o divide.o

