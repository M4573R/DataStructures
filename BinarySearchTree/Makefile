CXX = clang++ -m32
CXXFLAGS = -Wall -g
OFILES = TreeNode.o BinarySearchTree.o BinarySearchTreeTest.o

.SUFFIXES: .o .cpp

main: $(OFILES)
	  $(CXX) $(CXXFLAGS) -o test $(OFILES)

clean:
	  /bin/rm -f *.o *~

