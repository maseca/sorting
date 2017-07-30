//Maxwell Plotkin
#include <cstdio>
#include <fstream>
#include <vector>
using namespace std;

void qSort(int ary[], int l, int r);
void qSort(int in[], int out[]);

int main(int argc, char* argv[]){
	const int bs = 64;

	ifstream in;
	int as = 0;
	int ia[bs];
	int* oa;

	in.open("input.txt");

	while(!in.fail() && as < bs){
		in >> ia[as];	
		++as;
	}

	in.close();

	as -= 1;
	oa = (int*)malloc(as);
	qSort(ia, oa);
	//qSort(ia, 0, as-1);

	for(int i = 0; i < as; ++i){
		printf("%d\n", oa[i]);
	}
	free(oa);
}

void qSort(int in[], int out[]){
	vector<int> l, r;	
}

void qSort(int ary[], int l, int r){
	int i = l, j = r;
	int tmp;
	int pvt = ary[(l+r)/2];

	while(i<=j){
		while(ary[i] < pvt)
			++i;
		while(ary[j] > pvt)
			--j;
		if(i<=j){
			tmp = ary[i];
			ary[i] = ary[j];
			ary[j] = tmp;
			++i;
			--j;
		}
	}

	if(l<j)
		qSort(ary, l, j);
	if(i<r)
		qSort(ary, i, r);
}