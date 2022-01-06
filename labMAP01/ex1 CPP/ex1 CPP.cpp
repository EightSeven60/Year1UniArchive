#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream file1;
	ofstream file2;
	unsigned int i;
	char* sir = (char*)malloc(512 * sizeof(char));
	file1 >> sir;
	for (i = 0; i < 512; ++i) {
		printf("%c", sir[i]);
	}
	file1.close();
	file2.close();
	getchar();
	return 0;
}