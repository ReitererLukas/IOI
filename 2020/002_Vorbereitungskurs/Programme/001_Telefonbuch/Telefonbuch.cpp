//#include "grader.cpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

void init(vector<int> numbers)
{
    for (int num : numbers)
    {
        v.push_back(num);
    }
    sort(v.begin(), v.end());
}

bool query(int number)
{
    return binary_search(v.begin(),v.end(),number);
}
