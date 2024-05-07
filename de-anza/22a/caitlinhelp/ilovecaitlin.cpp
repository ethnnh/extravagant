#include <iostream>
using namespace std;
int ilovecaitlin(int &);

int main() {
	int a = 10;
	ilovecaitlin(a);
	cout << a;
}

int ilovecaitlin(int &n) {
	n = 5;
	n++;
	return n;
}