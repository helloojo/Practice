#include <cstdio>
//BOJ 3425

int stack[1001];
int pos = -1;


int c_abs(int num) {
	return (num < 0 ? -num : num);
}
long long c_abs(long long num) {
	return (num < 0 ? -num : num);
}

bool c_strcmp(char* a, const char* b) {
	int i = 0;
	while (a[i] && b[i]) {
		if (a[i] != b[i]) {
			return false;
		}
		i++;
	}
	return !(a[i] || b[i]);
}
void c_strcpy(char* dest, char* src) {
	int i = 0;
	while (src[i]) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

bool NUM(int x) {
	stack[++pos] = x;
	return true;
}
bool POP() {
	if (pos == -1) {
		return false;
	}
	pos--;
	return true;
}
bool INV() {
	if (pos == -1) {
		return false;
	}
	stack[pos] = -stack[pos];
	return true;
}
bool DUP() {
	if (pos == -1) {
		return false;
	}
	stack[pos + 1] = stack[pos];
	pos++;
	return true;
}
bool SWP() {
	if (pos - 1 == -1) {
		return false;
	}
	int temp = stack[pos];
	stack[pos] = stack[pos - 1];
	stack[pos - 1] = temp;
	return true;
}
bool ADD() {
	if (pos == -1) {
		return false;
	}
	int first = stack[pos--];
	if (pos == -1) {
		return false;
	}
	int second = stack[pos--];
	int ret = first + second;
	if (c_abs(ret) > 1000000000) {
		return false;
	}
	stack[++pos] = ret;
	return true;
}
bool SUB() {
	if (pos == -1) {
		return false;
	}
	int first = stack[pos--];
	if (pos == -1) {
		return false;
	}
	int second = stack[pos--];
	int ret = second - first;
	if (c_abs(ret) > 1000000000) {
		return false;
	}
	stack[++pos] = ret;
	return true;
}
bool MUL() {
	if (pos == -1) {
		return false;
	}
	long long first = stack[pos--];
	if (pos == -1) {
		return false;
	}
	long long second = stack[pos--];
	long long ret = first * second;
	if (c_abs(ret) > 1000000000) {
		return false;
	}
	stack[++pos] = ret;
	return true;
}
bool DIV() {
	if (pos == -1) {
		return false;
	}
	int first = stack[pos--];
	if (pos == -1) {
		return false;
	}
	int second = stack[pos--];
	if (first == 0) {
		return false;
	}
	bool minus = false;
	if (first > 0 && second < 0) {
		minus = true;
		second = c_abs(second);
	} else if (first < 0 && second>0) {
		minus = true;
		first = c_abs(first);
	} else if (first < 0 && second < 0) {
		first = c_abs(first);
		second = c_abs(second);
	}
	int ret = second / first;
	if (c_abs(ret) > 1000000000) {
		return false;
	}
	stack[++pos] = (minus ? -ret:ret);
	return true;
}
bool MOD() {
	if (pos == -1) {
		return false;
	}
	int first = stack[pos--];
	if (pos == -1) {
		return false;
	}
	int second = stack[pos--];
	if (first == 0) {
		return false;
	}
	bool minus = false;
	if (first < 0) {
		first = c_abs(first);
	}
	if (second < 0) {
		minus = true;
		second = c_abs(second);
	}
	int ret = second % first;
	if (c_abs(ret) > 1000000000) {
		return false;
	}
	stack[++pos] = (minus ? -ret : ret);
	return true;
}

/*
NUM X: X�� ������ ���� ���� �����Ѵ�. (0 �� X �� 10^9)
POP: ���� ���� ���� ���ڸ� �����Ѵ�.
INV: ù ��° ���� ��ȣ�� �ٲ۴�. (42 -> -42)
DUP: ù ��° ���ڸ� �ϳ� �� ������ ���� ���� �����Ѵ�.
SWP: ù ��° ���ڿ� �� ��° ������ ��ġ�� ���� �ٲ۴�.
ADD: ù ��° ���ڿ� �� ��° ���ڸ� ���Ѵ�.
SUB: ù ��° ���ڿ� �� ��° ���ڸ� ����. (�� ��° - ù ��°)
MUL: ù ��° ���ڿ� �� ��° ���ڸ� ���Ѵ�.
DIV: ù ��° ���ڷ� �� ��° ���ڸ� ���� ���� �����Ѵ�. �� ��° ���ڰ� ������, ù ��° ���ڰ� �����̴�.
MOD: ù ��° ���ڷ� �� ��° ���ڸ� ���� �������� �����Ѵ�. �� ��° ���ڰ� ������, ù ��° ���ڰ� �����̴�.

���� �������� ��쿡 ù ��° ���ڰ� �����ʿ� �ִ� ���̰�, �� ��° ���ڰ� ���ʿ� �ִ� ���̴�.
��, ������ �����ϱ� ���� �� ���ڸ� ��� ���ÿ��� ������ ��, ����� �ٽ� ���ÿ� �����ϴ� ���̴�.
���ڰ� �����ؼ� ������ ������ �� ���� ��, 0���� ������ �� (DIV, MOD),
���� ����� ������ 109�� �Ѿ ���� ��� ���α׷� �����̴�.

���� �������� ���� ��ȣ���� ���ϱ� ���� ������ ���� ����Ѵ�.
�������� �ǿ����ڿ� ������ ���� ����, �� ���� ������ ���� �� ����Ѵ�.
�׸��� ���� ��� �������� ��ȣ�� ������ ���� �����Ѵ�. �ǿ������� ������ �� ���϶��� ���� ��ȣ�� �����̴�.
�� ��츦 �����ϸ� ���� ��ȣ�� �׻� ����̴�.
�������� ��ȣ�� �������� ��ȣ�� ����. ����, 13 div -4 = -3, -13 mod 4 = -1, -13 mod -4 = -1�̴�.

���α׷� ������ �߻����� ��쿡��, ���� ���α׷��� ������ ���߰�, �� ���� � ��ɵ� �������� �ʴ´�.
*/

struct data {
	char input[5];
	int num;
};

data input[100001];

int main() {
	while (true) {
		int idx = 0;
		scanf("%s", input[idx].input);
		if (c_strcmp(input[idx].input, "QUIT")) {
			break;
		}
		while (!c_strcmp(input[idx].input, "END")) {
			if (c_strcmp(input[idx].input, "NUM")) {
				scanf("%d", &input[idx].num);
			}
			scanf("%s", input[++idx].input);
		}
		int n;
		scanf("%d", &n);
		for (int t = 0; t < n; t++) {
			bool normal = true;
			pos = -1;
			scanf("%d", &stack[++pos]);
			for (int i = 0; i < idx; i++) {
				if (c_strcmp(input[i].input, "NUM")) {
					NUM(input[i].num);
				} else if (c_strcmp(input[i].input, "POP")) {
					if (!POP()) {
						normal = false;
						break;
					}
				} else if (c_strcmp(input[i].input, "INV")) {
					if (!INV()) {
						normal = false;
						break;
					}
				} else if (c_strcmp(input[i].input, "DUP")) {
					if (!DUP()) {
						normal = false;
						break;
					}
				} else if (c_strcmp(input[i].input, "SWP")) {
					if (!SWP()) {
						normal = false;
						break;
					}
				} else if (c_strcmp(input[i].input, "ADD")) {
					if (!ADD()) {
						normal = false;
						break;
					}
				} else if (c_strcmp(input[i].input, "SUB")) {
					if (!SUB()) {
						normal = false;
						break;
					}
				} else if (c_strcmp(input[i].input, "MUL")) {
					if (!MUL()) {
						normal = false;
						break;
					}
				} else if (c_strcmp(input[i].input, "DIV")) {
					if (!DIV()) {
						normal = false;
						break;
					}
				} else if (c_strcmp(input[i].input, "MOD")) {
					if (!MOD()) {
						normal = false;
						break;
					}
				}
			}
			if (pos != 0) {
				normal = false;
			}
			if (normal) {
				printf("%d\n", stack[pos]);
			} else {
				printf("ERROR\n");
			}
		}
		printf("\n");
	}
	return 0;
}