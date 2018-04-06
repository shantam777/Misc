#include <stdio.h>
#include <fstream>

using namespace std;

int main()
{
	fstream input, output;
    input.open("input.in",std::ios::in);
    output.open("output.out",std::ios::out);
    int t;
    input >> t;
    for(int z=0;z<t;++z)
    {
        long long n,k,c,x;
        input >> n;
        input >> k;
        input >> c;
        input >> x;
        long long *A = new long long[n];
        long long *B = new long long[n];
        for(long long i=0;i<n;++i)
            input >> A[i];
        for(long long i=0;i<n;++i)
            input >> B[i];
        long long** M = new long long*[n];
        for(long long i = 0; i < n; ++i)
            M[i] = new long long[n];
        for(long long i=0; i<n; ++i)
        {
            for(long long j=0; j<n; ++j)
            {
                //Big mod algorithm
                M[i][j] = ((A[i]*(i+1))%x + (B[j]*(j+1))%x + c) % x;
            }
        }
        long long sum = 0, max = 0;
        for(long long i=0; i<n; ++i)
        {
            for(long long j=0; j<n; ++j)
            {
                max = 0;
                for(long long l=0; l<k&&(i+k-1)<n; ++l)
                {
                    for(long long m=0; m<k&&(j+k-1)<n; ++m)
                    {
                        if(M[i+l][j+m] > max)
                            max = M[i+l][j+m];
                    }
                }
                sum += max;
            }
        }
        delete [] A;
        delete [] B;
        for (int i = 0; i < n; ++i)
            delete [] M[i];
        delete [] M;
        output << "Case #" << z+1 << ": " << sum << endl;
    }
    input.close();
    output.close();
    return 0;
}
