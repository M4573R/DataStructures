#include <iostream>
#include "Trie.h"

using namespace std;

int main() {
	Trie *t = new Trie();
	cout << "Inserting hello..." << endl;
	t -> insert("hello");
	cout << "Inserting hallo..." << endl;
	t -> insert("hallo");

	cout << "Finding hallo " << t -> find("hallo") << endl;
	cout << "Finding hello " << t -> find("hello") << endl;
	cout << "Finding hullo " << t -> find("hullo") << endl;

	cout << "Inserting hullo..." << endl;
	t -> insert("hullo");

	cout << "Inserting ollo..." << endl;
	t -> insert("ollo");

	cout << "Inserting allo..." << endl;
	t -> insert("allo");
	cout << "Finding hullo " << t -> find("hullo") << endl;
	cout << "Finding ollo " << t -> find("ollo") << endl;
	cout << "Finding allo " << t -> find("allo") << endl;
	cout << "Finding all " << t -> find("all") << endl;

	return 0;
}