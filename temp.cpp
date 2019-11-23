#include <cstring>
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

bool containSameCharacters(const string& a, const string& b)
{
	if(a.size() != b.size()) return false;
	
	int count[256], i, len = a.size();
	memset(count, 0, sizeof(count));
	for(i = 0; i < len; ++i) ++count[a[i]];
	for(i = 0; i < len; ++i){
		if(--count[b[i]] < 0) return false;
	}
	return true;
}
int getMinimumSwaps(const string& from, const string& to)
{
	if(!containSameCharacters(from, to)) return -1;
	if(from == to) return 0;

	unordered_map<string, int> fromMap, toMap;//record state already visited and 
											  //how many swaps need to transfrom into this state
	queue<string> fromQueue, toQueue;//states queue
	int level = 1;					 //how many swaps has been done

	string tmp;
	int i, j, k, n, len = from.size();
	unordered_map<string, int>::iterator iter;
	//initialize
	fromQueue.push(from);
	fromMap[from] = 0;
	toQueue.push(to);
	toMap[to] = 0;
	//binary BFS
	for(; !fromQueue.empty() && !toQueue.empty(); ++level){
		//extend state in fromQueue
		for(i = 0, n = fromQueue.size(); i < n; ++i){
			tmp = fromQueue.front();
			fromQueue.pop();
			for(j = 0; j < len; ++j){
				for(k = j+1; k < len; ++k){
					swap(tmp[j], tmp[k]);//try to swap tmp[j] with tmp[k]
					iter = toMap.find(tmp);//check if this state has been visited by 'to'
					if(iter != toMap.end()){
						cout << "fromMap["<< tmp << "]= " << level << endl;
						cout << "toMap[" << tmp << "]= " << iter->second << endl;
						return level + iter->second;
					}
					else if(fromMap.find(tmp) == fromMap.end()){//check if this state has been visited by 'from'
						fromQueue.push(tmp);
						fromMap[tmp] = level;
					}
					swap(tmp[j], tmp[k]);
				}
			}
		}
		//extend state in toQueue
		for(i = 0, n = toQueue.size(); i < n; ++i){
			tmp = toQueue.front();
			toQueue.pop();
			for(j = 0; j < len; ++j){
				for(k = j+1; k < len; ++k){
					swap(tmp[j], tmp[k]);//try to swap tmp[j] with tmp[k]
					iter = fromMap.find(tmp);//check if this state has been visited by 'from'
					if(iter != fromMap.end()){
						cout << "toMap[" << tmp << "]= " << level << endl;
						cout << "fromMap["<< tmp << "]= " << iter->second << endl;
						return level + iter->second;
					}
					else if(toMap.find(tmp) == toMap.end()){//check if this state has been visited by 'to'
						toQueue.push(tmp);
						toMap[tmp] = level;
					}
					swap(tmp[j], tmp[k]);
				}
			}
		}
	}

	return -1;//actually it never reaches here
}

int main()
{
	cout << getMinimumSwaps("kamal", "amalk");
	return 0;
}