CXX = clang++ -m32
CXXFLAGS = -Wall -g
OFILES = Node.o Trie.o TrieTest.o

.SUFFIXES: .o .cpp

main: $(OFILES)
	  $(CXX) $(CXXFLAGS) $(OFILES)

clean:
	  /bin/rm -f *.o *~ a.out

