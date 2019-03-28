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
NUM X: X를 스택의 가장 위에 저장한다. (0 ≤ X ≤ 10^9)
POP: 스택 가장 위의 숫자를 제거한다.
INV: 첫 번째 수의 부호를 바꾼다. (42 -> -42)
DUP: 첫 번째 숫자를 하나 더 스택의 가장 위에 저장한다.
SWP: 첫 번째 숫자와 두 번째 숫자의 위치를 서로 바꾼다.
ADD: 첫 번째 숫자와 두 번째 숫자를 더한다.
SUB: 첫 번째 숫자와 두 번째 숫자를 뺀다. (두 번째 - 첫 번째)
MUL: 첫 번째 숫자와 두 번째 숫자를 곱한다.
DIV: 첫 번째 숫자로 두 번째 숫자를 나눈 몫을 저장한다. 두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.
MOD: 첫 번째 숫자로 두 번째 숫자를 나눈 나머지를 저장한다. 두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.

이항 연산자의 경우에 첫 번째 숫자가 오른쪽에 있는 수이고, 두 번째 숫자가 왼쪽에 있는 수이다.
또, 연산을 수행하기 전에 두 숫자를 모두 스택에서 제거한 뒤, 결과를 다시 스택에 저장하는 것이다.
숫자가 부족해서 연산을 수행할 수 없을 때, 0으로 나눴을 때 (DIV, MOD),
연산 결과의 절댓값이 109를 넘어갈 때는 모두 프로그램 에러이다.

음수 나눗셈에 대한 모호함을 피하기 위해 다음과 같이 계산한다.
나눗셈의 피연산자에 음수가 있을 때는, 그 수를 절댓값을 씌운 뒤 계산한다.
그리고 나서 몫과 나머지의 부호는 다음과 같이 결정한다. 피연산자중 음수가 한 개일때는 몫의 부호가 음수이다.
이 경우를 제외하면 몫의 부호는 항상 양수이다.
나머지의 부호는 피제수의 부호와 같다. 따라서, 13 div -4 = -3, -13 mod 4 = -1, -13 mod -4 = -1이다.

프로그램 에러가 발생했을 경우에는, 현재 프로그램의 수행을 멈추고, 그 다음 어떤 명령도 수행하지 않는다.
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