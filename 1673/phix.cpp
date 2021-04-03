#include <bits/stdc++.h>
using namespace std;

#define MaxK 4000000
#define MaxN 44725
#define Infinity (1LL << 61)
#define Test_Prime_Num 6
const int Test_Prime[Test_Prime_Num] = {2, 3, 5, 7, 11, 13};

long long K;
pair <long long, long long> Memo[MaxK];
int Prime[MaxN];
vector <pair <long long, long long> > X;

struct Compare
{
	bool operator () (pair <long long, long long> A, pair <long long, long long> B) {
		return A. first < B. first;
	}
};

long long GetMulMod(long long Base, long long Times, long long Divisor)
{
	if (!Times) return 0;
	else {
		long long Result = GetMulMod(Base, Times >> 1, Divisor);
		Result = (Result << 1) % Divisor;
		if (Times & 1) Result = (Result + Base) % Divisor;
		return Result;
	}
}

long long GetExpMod(long long Base, long long Exponent, long long Divisor)
{
	if (!Exponent) return 1;
	else {
		long long Result = GetExpMod(Base, Exponent >> 1, Divisor);
		Result = GetMulMod(Result, Result, Divisor);
		if (Exponent & 1) Result = GetMulMod(Result, Base, Divisor);
		return Result;
	}
}

bool Is_Prime(long long N)
{
	if ((N == 1) || ((N > 2) && !(N & 1))) return 0;
	if (N < MaxN) return Prime[N >> 4] & (1 << ((N >> 1) & 7));
	for (int i = 0; i < Test_Prime_Num; ++ i)
	{
		if (Test_Prime[i] >= N) continue;
		if (GetExpMod(Test_Prime[i], N - 1, N) == 1) continue;
		return 0;
	}
	return 1;
}

long long GCD(long long X, long long Y)
{
	for (; Y; )
	{
		long long R = X % Y;
		X = Y;
		Y = R;
	}
	return X;
}

void Update(pair <long long, long long> &A, long long B)
{
	if (B < A. first)
	{
		A. second = A. first;
		A. first = B;
	}
	else if (B > A. first) A. second = min(A. second, B);
}

pair <long long, long long> Search(long long K)
{
	pair <long long, long long> Result;
	if (K & 1)
	{
		Result. first = Result. second = 0;
		return Result;
	}
	Result. first = Result. second = Infinity;
	if (K / 2 < MaxK)
	{
		if (Memo[K / 2]. second == 0)
		{
			Result = Memo[K / 2];
			Result. second = Infinity;
			if (Result. first == 0) Result. first = Infinity;
		}
		else return Memo[K / 2];
	}
	else
		for (int L = 0, R = X. size() - 1; L <= R; )
		{
			int Mid = (L + R) / 2;
			if (X[Mid]. first == K)
			{
				Result. first = X[Mid]. second;
				break;
			}
			if (X[Mid]. first < K) L = Mid + 1;
			else R = Mid - 1;
		}
	if (Is_Prime(K + 1))
	{
		Result. second = Result. first;
		Result. first = K + 1;
	}
	for (long long x = 2; x * x <= K; x += 2)
		if (!(K % x))
		{
			pair <long long, long long> A = Search(x), B = Search(K / x);
			if (A. first > 0 && B. first > 0 && GCD(A. first, B. first) == 1) Update(Result, A. first * B. first);
			if (A. first > 0 && B. second > 0 && GCD(A. first, B. second) == 1) Update(Result, A. first * B. second);
			if (A. second > 0 && B. first > 0 && GCD(A. second, B. first) == 1) Update(Result, A. second * B. first);
			if (A. second > 0 && B. second > 0 && GCD(A. second, B. second) == 1) Update(Result, A. second * B. second);
		}
	if (Result. first == Infinity) Result. first = -1;
	if (Result. second == Infinity) Result. second = -1;
	if (K / 2 < MaxK) Memo[K / 2] = Result;
	if (Result. first == -1) Result. first = 0;
	return Result;
}

int main()
{
	cin >> K;
	if (K == 1) printf("1\n");
	else if (K & 1) printf("0\n");
	else {
		memset(Prime, -1, sizeof(Prime));
		Prime[0] = -2;
		for (int i = 1; i * i < MaxN; ++ i)
			if ((Prime[i >> 3] & (1 << (i & 7))) != 0)
				for (int j = (i * (i + 1)) << 1; j + j < MaxN; j += (i << 1) + 1)
					Prime[j >> 3] = Prime[j >> 3] & ~(1 << (j & 7));
		memset(Memo, 0, sizeof(Memo));
		X. clear();
		for (long long i = 3; i < MaxN; i += 2)
			if (Prime[i >> 4] & (1 << ((i >> 1) & 7)))
				for (long long Q = (i - 1) * i; Q <= K; Q *= i)
					if (Q / 2 < MaxK) Memo[Q / 2]. first = Q / (i - 1) * i;
					else {
						pair <long long, long long> T;
						T. first = Q;
						T. second = Q / (i - 1) * i;
						X. push_back(T);
					}
		sort(X. begin(), X. end(), Compare());
		cout << Search(K). first << endl;
	}
}