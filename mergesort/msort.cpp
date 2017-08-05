//Maxwell Plotkin
#include <cstdio>
#include <deque>
using namespace std;

#define MAX_SIZE 999

deque<int> mSort(deque<int> in);
deque<int> merge(deque<int> l, deque<int> r);

int main(int argc, char** argv){
	FILE* in;
	int tmp, sz;
	deque<int> id;

	sz = 0;

	in = fopen("input.txt", "r");
	while(sz < MAX_SIZE && fscanf(in, "%d", &tmp) != EOF){
		id.push_back(tmp);
		++sz;
	}
	fclose(in);

	id = mSort(id);

	for(int i : id){
		printf("%d\n", i);
	}

	return 0;
}

deque<int> mSort(deque<int> in){
	if(in.size() < 2)
		return in;

	int split = in.size() / 2;
	deque<int> left;

	for(int i = 0; i < split; ++i){
		left.push_back(in.front());
		in.pop_front();
	}

	return merge(mSort(left), mSort(in));
}

deque<int> merge(deque<int> l, deque<int> r){
	deque<int> out;

	while(l.size() && r.size()){
		if(l.front() < r.front()){ 
			out.push_back(l.front());
			l.pop_front();
		}else{
			out.push_back(r.front());
			r.pop_front();
		}
	}

	while(l.size()){
		out.push_back(l.front());
		l.pop_front();
	}

	while(r.size()){
		out.push_back(r.front());
		r.pop_front();
	}

	return out;
}