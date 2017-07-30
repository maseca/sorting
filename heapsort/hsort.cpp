//Maxwell Plotkin
#include <cstdio>
#include <vector>
using namespace std;

#define MAX_SIZE 999

vector<int> qSort(vector<int>& v);

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

	iv = qSort(iv);
	for(int i : iv){
		printf("%d\n", i);
	}

	return 0;
}

vector<int> qSort(vector<int>& v){
	if(v.size() <= 1) return v;

	vector<int> l, r;
	int pvt = v.back();
	v.pop_back();

	for(int i : v){
		if(i > pvt){
			r.push_back(i);
		}else{
			l.push_back(i);
		}
	}

	l = qSort(l);
	l.push_back(pvt);
	r = qSort(r);
	l.insert(l.end(), r.begin(), r.end());
	return l;
}
