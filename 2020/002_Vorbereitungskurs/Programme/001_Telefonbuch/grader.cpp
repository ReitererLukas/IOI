#include "zahlensuche.h"
#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
    
    std::vector<int> numbers;
    numbers.reserve(n);

	for (int i=0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
		numbers.push_back(x);
    }
	init(numbers);
    
	int q;
	scanf("%d",&q);
    for (int i=0; i < q; i++)
    {
        int x;
        scanf("%d", &x);
		
        printf("%d: %s\n", x, query(x) ? "found" : "not found");
    }

	return 0;
}
