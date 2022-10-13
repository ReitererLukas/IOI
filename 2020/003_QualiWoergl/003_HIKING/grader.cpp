#include "hiking.h"
#include <cstdio>
#include <cstdlib>

const int MAX_N = 1000003;
const int MAX_QUERIES = 150;

int N;
int height;
int heights[MAX_N];
int queryCount = 0;

int getHeight(int coordinate) {
	if (coordinate < 1 || coordinate > N) {
		printf("Coordinate %d was not between 1 and %d\n", coordinate, N);
		exit(0);
	}
	queryCount++;
	if (queryCount > MAX_QUERIES) {
		printf("Too many queries\n");
		exit(0);
	}
	return heights[coordinate-1];
}

int main() {
	scanf("%d %d", &N, &height);
	for (int i = 0; i < N; i++)
		scanf("%d", &heights[i]);
	
	int result = findCoordinate(N, height);
	if (result < 1 || result > N) {
		printf("Result %d was not between 1 and %d\n", result, N);
		return 0;
	}
	
	if (height == heights[result-1]) {
		printf("Correct\n");
	} else {
		printf("Incorrect\n");
	}	
	return 0;
}
