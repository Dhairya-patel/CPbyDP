#include <bits/stdc++.h>
using namespace std;

struct Trienode {
	int next[26];
	int mx = -1;
	bool last = false;

	Trienode() {
		for(int i=0;i<26;i++)
			next[i] = -1;
	}
};

vector<Trienode>trie(1);

void insertstr(string &str, int w)
{
	int cv = 0;
	for(int i=0;i<str.size();i++)
	{
		int ind = str[i] - 'a';
		if(trie[cv].next[ind] == -1)
		{
			trie[cv].next[ind] = trie.size();
			Trienode tn;
			trie.push_back(tn);
		}
		cv = trie[cv].next[ind];
		trie[cv].mx = max(trie[cv].mx, w);
	}
	trie[cv].last = true;
}

int search(string &str)
{
	int cv = 0, ans = -1;
	for(int i=0;i<str.size();i++)
	{
		int ind = str[i] - 'a';
		if(trie[cv].next[ind] == -1)
		{
			ans = -1;
			break;
		}
		cv = trie[cv].next[ind];
		ans = trie[cv].mx;
	}
	return ans;
}

int main() {
	int n, q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		string str;
		int w;
		cin>>str>>w;
		insertstr(str, w);
	}
	for(int i=0;i<q;i++)
	{
		string str;
		cin>>str;
		int ans = search(str);
		cout<<ans<<endl;
	}
}