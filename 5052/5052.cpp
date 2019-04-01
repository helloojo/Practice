#include <cstdio>
#include <cstring>
#include <algorithm>
//BOJ #5052

#define PRIME 100019

struct Data {
	Data* child;
	Data* sibling;
	bool fin;
	char str[11];
};

struct Hash {
	Data table[PRIME];
} tb,sm;

typedef unsigned long long ull;

void insert(Data* parent, Data* child) {
	if (parent->child == NULL) {
		parent->child = child;
		return;
	}
	Data* temp = parent->child;
	while (temp->sibling) {
		temp = temp->sibling;
	}
	temp->sibling = child;
}

Data* find(ull h, char *str)
{
	int cnt = PRIME;

	while (tb.table[h].str[0] && cnt--)
	{
		if (strcmp(tb.table[h].str, str) == 0)
		{
			return &tb.table[h];
		}
		h = (h + 1) % PRIME;
	}
	return NULL;
}

Data* add(ull h, char *str)
{
	while (tb.table[h].str[0])
	{
		h = (h + 1) % PRIME;
	}
	strcpy(tb.table[h].str, str);
	return &tb.table[h];
}

bool find_insert(char* str) {
	ull hash = 5381;
	int c;
	int i = 0;
	Data* temp;
	Data* prev = NULL;
	char s[11] = "";
	bool ret = false;
	while (c = *str++) {
		s[i++] = c;
		hash = (((hash << 5) + hash) + c) % PRIME;
		if (!(temp = find(hash, s))) {
			temp = add(hash, s);
			if (prev) {
				insert(prev, temp);
			}
		} else {
			if (temp->fin || ((*str)=='\0')) {
				ret = true;
			}
		}
		prev = temp;
	}
	temp->fin = true;
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		tb = sm;
		int n;
		char str[11];
		bool flag = true;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", str);
			if (find_insert(str)) {
				flag = false;
			}
		}
		printf("%s\n", (flag ? "YES" : "NO"));
	}
	return 0;
}