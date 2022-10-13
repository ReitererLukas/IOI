#include "hiking.h"
#include "grader.cpp"

int f(int unter, int ober, int height)
	{
		int mid = unter + (ober - unter) / 2;
		printf("%d: ",mid);
		int h = getHeight(mid);
		printf("%d\n",h);
		if (h == height)
		{
			return mid;
		}
		else if (h < height)
		{
			return f(mid+1,ober,height);
		}
		else if(h > height)
		{
			return f(unter,mid-1,height);
		}
	}

int findCoordinate(int N, int height)
{
	// TODO
	/*if (getHeight(N) == 4)
		return 42;
	return N;*/
	return f(1,N,height);
}
