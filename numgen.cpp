#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
typedef vector<unsigned> vu;

vu getnum(istream &is)
{
	vu vi(3);
	char com;
	for (int i = 0; i != 2; ++ i){
		is >> vi[i];
		is >> com;
	}
	is >> vi[2];
	sort(vi.begin(),vi.end());
	return std::move(vi);
}
void gen(const vu & v, vu & tmp);
void check(vu& vi, vu& tmp){
	for (auto i=0; i != vi.size(); ++ i){
		if(vi[i] == 2){
			vi[i] = 5;
			gen(vi, tmp);
		}
		else if(vi[i] == 5){
			vi[i] = 2;
			gen(vi, tmp);
		}
		else if(vi[i] == 6){
			vi[i] = 9;
			gen(vi, tmp);
		}
		else if(vi[i] == 9){
			vi[i] = 6;
			gen(vi, tmp);
		}
	}
}

void gen(const vu& v, vu& tmp){
	copy(v.begin(), v.end(),inserter(tmp, tmp.end()));
	for(int i = 0; i != v.size(); ++ i)
		for (int j = 0; j != v.size(); ++ j)
			if(i != j)
				tmp.push_back(10*v[i] + v[j]);
	for(int i = 0; i != v.size(); ++ i)
		for (int j = 0; j != v.size(); ++ j)
			for (int k = 0; k != v.size(); ++ k)
				if (i != j && i != k)
					tmp.push_back(100*v[i] + 10*v[j] + v[k]);
}

int main(){
	ifstream file("Text.txt");
	auto vi = getnum(file);
	copy(vi.begin(), vi.end(), ostream_iterator<int>(cout ,", "));
	auto index = vi.back();
	vu tmp;
	gen(vi, tmp);
	check(vi, tmp);
	
	sort(tmp.begin(),tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	//copy(tmp.begin(), tmp.end(), ostream_iterator<int>(cout ,", "));
	//cout << endl;
	return tmp[index-1];
	return 0;
}

