//Maxwell Plotkin
#include <cstdio>
#include <vector>
using namespace std;

#define MAX_SIZE 999

void hSort(vector<int>* h);
void heapify(vector<int>* h);

int main(int argc, char** argv){
	FILE* in;
	int tmp, sz;
	vector<int> iv;

	sz = 0;

	in = fopen("input.txt", "r");
	while(sz < MAX_SIZE && fscanf(in, "%d", &tmp) != EOF){
		iv.push_back(tmp);
		++sz;
	}
	fclose(in);

	iv = heapify(iv);
	iv = hSort(iv);
	for(int i : iv){
		printf("%d\n", i);
	}

	return 0;
}

void hSort(vector<int>* h){
}
