#include <cstdio>
//BOJ #1302
typedef long long ll;
const int PRIME = 10007;

struct data {
	char str[51];
	int cnt;
};
data map[PRIME];

int c_strcmp(char* a, char* b) {
	int i = 0;
	while (a[i] && b[i]) {
		if (a[i] > b[i]) {
			return 1;
		} else if (a[i] < b[i]) {
			return -1;
		}
		i++;
	}
	if (a[i] && !b[i]) {
		return 1;
	} else if (!a[i] && b[i]) {
		return -1;
	} else {
		return 0;
	}
}

void c_strcpy(char* dest, char* src) {
	int i = 0;
	while (src[i]) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

ll power(ll a, ll b) {
	if (b == 0) {
		return 1;
	}
	if (b & 1) {
		return (a%PRIME*power(a, b - 1) % PRIME) % PRIME;
	}
	return power((a%PRIME*a%PRIME)%PRIME, b >> 1)%PRIME;
}

ll make_hash(char* str) {
	ll hash = 0;
	ll i = 0;
	while (str[i]) {
		hash = (hash%PRIME + (power(26, i) % PRIME*str[i] % PRIME) % PRIME) % PRIME;
		i++;
	}
	return hash;
}

ll insert_hash(ll hash, char* str) {
	while (map[hash].str[0]) {
		hash++;
		hash %= PRIME;
	}
	c_strcpy(map[hash].str, str);
	map[hash].cnt=1;
	return hash;
}

ll find_hash(ll hash, char* str) {
	while (map[hash].str[0]) {
		if (c_strcmp(map[hash].str, str) == 0) {
			map[hash].cnt++;
			return hash;
		}
		hash++;
		hash %= PRIME;
	}
	return -1;
}

int main() {
	int n;
	scanf("%d", &n);
	char input[51];
	char maxstr[51]="";
	int maxcnt=0;
	for (int i = 0; i < n; i++) {
		scanf("%s", input);
		ll hashv = make_hash(input);
		ll find_ret = find_hash(hashv, input);
		if (find_ret == -1) {
			find_ret = insert_hash(hashv, input);
		}
		if (map[find_ret].cnt > maxcnt) {
			maxcnt = map[find_ret].cnt;
			c_strcpy(maxstr, map[find_ret].str);
		} else if (map[find_ret].cnt == maxcnt) {
			if (c_strcmp(maxstr, map[find_ret].str) == 1) {
				maxcnt = map[find_ret].cnt;
				c_strcpy(maxstr, map[find_ret].str);
			}
		}
	}
	printf("%s", maxstr);
}