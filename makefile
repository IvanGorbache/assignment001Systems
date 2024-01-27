#FLAGS FOR COMPILER
CFLAGS = -Wall -g
#COMPLIER
CC = gcc

#ALL - A call to make all of the static libraries, dynamic libraries, and executables
all: libclassloops.a libclassrec.a libclassrec.so libclassloops.so mains maindloop maindrec

#BASIC - A call to make the basicClassification object
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(CFLAGS) -c $^
	
#LOOP - A call to make the advancedClassificationLoop object
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(CFLAGS) -c $^
	
#RECURSIVE - A call to make the advancedClassificationRecursion object
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(CFLAGS) -c $^
	
#STATIC LOOP LIBRARY
libclassloops.a: advancedClassificationLoop.o basicClassification.o
	ar rcu $@ $^	
#LOOPS
loops: libclassloops.a
	
#STATIC REC LIBRARY
libclassrec.a: advancedClassificationRecursion.o basicClassification.o
	ar rcu $@ $^
#recursives
recursives: libclassrec.a

#DYNAMIC REC LIBRARY
libclassrec.so: advancedClassificationRecursion.o basicClassification.o
	$(CC) -fPIC -shared -o $(FLAGS) $@ $^	
#recursived
recursived: libclassrec.so

#DYNAMIC LOOP LIBRARY
libclassloops.so: advancedClassificationLoop.o basicClassification.o
	$(CC) -fPIC -shared -o $(FLAGS) $@ $^
loopd: libclassloops.so
		
#MAIN - A call to make the main object
main.o: main.c NumClass.h
	$(CC) $(CFLAGS) -c $^

#EXE
#Using the static recursive library
mains: main.o libclassrec.a
	$(CC) $(CFLAGS) -o $@ $< libclassrec.a
#Using the dynamic loop library
maindloop: main.o libclassloops.so
	$(CC) $(CFLAGS) -o $@ $< ./libclassloops.so
#Using the dynamic recursive library
maindrec: main.o libclassrec.so
	$(CC) $(CFLAGS) -o $@ $< ./libclassrec.so

#A call to both clean all and remake all files
.PHONY: clean all	

#Removing all the files besides the c,h,and make files
clean:
	rm -f *.o *.so *.a *.gch mains maindrec maindloop
	

