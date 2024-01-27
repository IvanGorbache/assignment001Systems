CFLAGS = -Wall -g
CC = gcc

#ALL
all: libclassloops.a libclassrec.a libclassrec.so libclassloops.so mains maindloop maindrec

#BASIC
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(CFLAGS) -c $^
	
#LOOP
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(CFLAGS) -c $^
	
#RECURSIVE
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(CFLAGS) -c $^
	
#STATIC LOOP LIBRARY
libclassloops.a: advancedClassificationLoop.o basicClassification.o
	ar rcu $@ $^	
loops: libclassloops.a
	
#STATIC REC LIBRARY
libclassrec.a: advancedClassificationRecursion.o basicClassification.o
	ar rcu $@ $^
recursives: libclassrec.a

#DYNAMIC REC LIBRARY
libclassrec.so: advancedClassificationRecursion.o basicClassification.o
	$(CC) -fPIC -shared -o $(FLAGS) $@ $^	
recursived: libclassrec.so

#DYNAMIC LOOP LIBRARY
libclassloops.so: advancedClassificationLoop.o basicClassification.o
	$(CC) -fPIC -shared -o $(FLAGS) $@ $^
loopd: libclassloops.so
		
#MAIN	
main.o: main.c NumClass.h
	$(CC) $(CFLAGS) -c $^

#EXE
mains: main.o libclassrec.a
	$(CC) $(CFLAGS) -o $@ $< libclassrec.a
	
maindloop: main.o libclassloops.so
	$(CC) $(CFLAGS) -o $@ $< ./libclassloops.so

maindrec: main.o libclassrec.so
	$(CC) $(CFLAGS) -o $@ $< ./libclassrec.so

.PHONY: clean all	

clean:
	rm -f *.o *.so *.a mains maindrec maindloop
	

