#This is makefile Hi ha ha ha ha


all: treeApp

treeApp : nodeData/nodeData.h treeNode.o tree.o
	g++ -Itree/ -ItreeNode/ -InodeData/ treeNode.o tree.o main.cpp -o treeApp

treeNode.o : treeNode/treeNode.h
	g++ -c -ItreeNode/ -I nodeData/ treeNode/treeNode.cpp
tree.o : tree/tree.h
	g++ -c -Itree/ -ItreeNode/ -InodeData/ tree/tree.cpp

clean: 
	-rm *.o
	-rm treeApp
