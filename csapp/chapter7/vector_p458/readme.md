#P459
gcc -c # just complie and assemble, don't link
ar rcs # arch 

gduozhang@etl-test:~/c-workspace/csapp/chapter7/vector_p458$ cc -c main.c 
duozhang@etl-test:~/c-workspace/csapp/chapter7/vector_p458$ ls
addvec.c  addvec.o  libverctor.a  main.c  main.o  multvec.c  multvec.o  readme.md  vector.h
duozhang@etl-test:~/c-workspace/csapp/chapter7/vector_p458$ ls *.o
addvec.o  main.o  multvec.o
duozhang@etl-test:~/c-workspace/csapp/chapter7/vector_p458$ gcc -static main.o libverctor.a
