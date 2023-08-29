
#include <iostream>
using namespace std;


void Merge(int A[], int start, int end, int q);

void Sort(int A[], int start, int end)
{
    int q;
    if (start < end)
    {
        q = (start + end) / 2; 
        Sort(A, start, q); 
        Sort(A, q + 1, end);
        Merge(A, start, end, q); 
    }
}

void Merge(int A[], int start, int end, int q)
{
    int mergeA[8];
    int i, j, k;
    i = start;
    k = start;
    j = q + 1;

    while (i <= q && j <= end) 
    {
        if (A[i] < A[j])
        {
            mergeA[k] = A[i];
            ++k;
            ++i;
        }
        else
        {
            mergeA[k] = A[j];
            ++k;
            ++j;
        }

    }
    while (i <= q)
    {
        mergeA[k] = A[i];
        ++k;
        ++i;
    }

    while (j <= end)
    {
        mergeA[k] = A[j];
		++k;
		++j;
    }

    for (i = start; i < k; ++i)
    {
        A[i] = mergeA[i];
    }
}

int main()
{

   int A[8]{5, 2, 4, 6, 1, 3, 2, 6};
   Sort(A,0, 7);
 
    return 0;
}
