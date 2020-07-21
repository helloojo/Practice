#include <stdio.h>
#include <string.h>
//BOJ #10546

const int PRIME = 200009;

struct Data {
	char name[21];
	int cnt;	
};

Data Hash[PRIME];
typedef unsigned long long ull;

ull make_hash(char* str) {
	ull h = 5381;
	int c;
	while (c = *str++) {
		h = ((h << 5) + h + c) % PRIME;
	}
	return h%PRIME;
}

void add(char* str) {
	ull h = make_hash(str);
	while (Hash[h].name[0]) {
		if (strcmp(Hash[h].name, str) == 0) {
			Hash[h].cnt++;
			return;	
		}
		h = (h + 1) % PRIME;
	}
	Hash[h].cnt++;
	strcpy(Hash[h].name, str);
	return;
}

void find(char* str) {
	ull h = make_hash(str);
	while (Hash[h].name[0]) {
		if (strcmp(Hash[h].name, str) == 0) {
			Hash[h].cnt--;
			return;
		}
		h = (h + 1) % PRIME;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	char str[21];
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		add(str);
	}
	for (int i = 0; i < n - 1; i++) {
		scanf("%s", str);
		find(str);
	}
	for (int i = 0; i < PRIME; i++) {
		if (Hash[i].cnt) {
			printf("%s", Hash[i].name);
			break;
		}
	}
	return 0;
}