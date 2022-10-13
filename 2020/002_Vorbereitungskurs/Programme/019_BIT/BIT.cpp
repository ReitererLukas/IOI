//#include "BIT.h" //Wird bei Einreichung benötigt
#include <cmath>
#include <stdio.h>

const int MAX_N = 100005;
long long tree[4 * MAX_N];
int n;

void init(int N)
{
	n = pow(2, ceil(log2(N)));
}

void update(int i,	//Index des knotens im baum
						int l,	//Sein linkestes Element aus dem ursprünglichen Array, zudem ein Weg führt
						int r,	//Sein rechtestes Element aus dem ursprünglichen Array, zudem ein Weg führt
						int si, //Index, zu welchem Element im ursprünglichen Array wir wollen
						int v /*Wert, denn wir addieren*/)
{
	if (l > si || r < si)
		return;
	if (l == r)
	{
		tree[i] += v;
		return;
	}
	update(2 * i, l, (l + r) / 2, si, v);
	update(2 * i + 1, (l + r) / 2 + 1, r, si, v);
	tree[i] = tree[2 * i] + tree[2 * i + 1];
}

void update(int i, int v)
{
	update(1, 1, n, i, v);
}

long long sum(int i, //Index des knotens im baum
							int l, //Sein linkestes Element aus dem ursprünglichen Array, zudem ein Weg führt
							int r, //Sein rechtestes Element aus dem ursprünglichen Array, zudem ein Weg führt
							int a, //Linke Intervallgrenze, bezieht sich auf ursprüngliches Array
							int b /*Rechte Intervallgrenze, bezieht sich auf ursprüngliches Array*/)
{
	if (l > b || r < a)
		return 0;
	if (l >= a && r <= b)
		return tree[i];
	return sum(2 * i, l, (l + r) / 2, a, b) + sum(2 * i + 1, (l + r) / 2+1, r, a, b);
}

long long query(int a, int b)
{
	return sum(1, 1, n, a, b);
}

//Bei Einreichung auskommentieren
int main() {
	int i, N, Q, qu, p, q, v, query_type;
	scanf("%d %d", &N, &Q);
	
	init(N);
	for(qu = 0; qu < Q; qu++) {
		scanf("%d", &query_type);
		if (query_type == 0) {
			scanf("%d %d", &i, &v);
			update(i, v);
		} else if (query_type == 1) {
			scanf("%d %d", &p, &q);
			printf("%lld\n", query(p, q));
		}
	}
	
	return 0;
}