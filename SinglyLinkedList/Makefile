CXX = clang++ -m32
CXXFLAGS = -Wall -g
OFILES = ListNode.o ListIterator.o SinglyLinkedList.o \
		 SinglyLinkedListTest.o

.SUFFIXES: .o .cpp

main: $(OFILES)
	  $(CXX) $(CXXFLAGS) -o test $(OFILES)

clean:
	  /bin/rm -f *.o *~

