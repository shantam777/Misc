#include<iostream>
#include<fstream>
#include<ctime>
#include<vector>
#include<bitset>
#include<cstring>
#include<algorithm>
#define MAX 99999
long long N, counthalf, count, m;

struct Card
{
    long long index;
    long long power;
    long long cost;
};

struct Deck
{
    long long totalPower;
    long long totalCost;
};

bool my_cmp(const Deck& a, const Deck& b)
{
    return a.totalPower > b.totalPower;
}

std::bitset<MAX> selected;
std::vector<struct Deck> powerSum;
long long indexz = 0;
long long counters[10];
struct Card deck[MAX];

void computeOperation(long long level)
{
	long long totalCost = 0, totalPower = 0;
    for (long long i=0; i<level; i++)
    {
        totalCost += deck[counters[i]].cost;
        totalPower += deck[counters[i]].power;
    }
    if(totalCost > m)
        return;
    powerSum.push_back(Deck());
    powerSum[indexz].totalPower = totalPower;
    powerSum[indexz++].totalCost = totalCost;
}

void nestedToRecursion(long long level)
{
	if((level == N/2 && N%2==0) || level > N/2)
        computeOperation(level);
    else
    {
        for (counters[level]=0; counters[level]<counthalf; counters[level]++)
        {
            if(selected[deck[counters[level]].index])    
				continue;
            selected[deck[counters[level]].index] = true;
            nestedToRecursion(level+1);
            selected[deck[counters[level]].index] = false;
        }
    }
}

void nestedToRecursion2(long long level)
{
	if(level == (N/2))
        computeOperation(level);
    else
    {
        for (counters[level]=counthalf; counters[level]<count; counters[level]++)
        {
            if(selected[deck[counters[level]].index])        
				continue;
            selected[deck[counters[level]].index] = true;
			nestedToRecursion2(level+1);
            selected[deck[counters[level]].index] = false;
        }
    }
}

int main()
{
    std::fstream input, output;
    input.open("input.in", std::ios::in);
    output.open("output.out", std::ios::out);
    clock_t begin = clock();
    long long t;
    input >> t;
    for(long long z=0; z<t; ++z)
    {
		long long count = 0, k[MAX], l[MAX], m, n, counthalf = 0;
        bool flag1 = true;
        memset(deck, 0, sizeof(deck));
        input >> m;
        ::m = m;
        input >> n;
        N = n;
        for(long long i=0; i<n; ++i)
        {
            input >> k[i];
            input >> l[i];
            long long beginMark = count;
            long long temp;
            for(long long j=0; j<(l[i]-1); ++j)
                input >> temp;
            for(long long j=l[i]-1; j<k[i]; ++j)
            {
                if(flag1)
                {
                    if((i==n/2 && n%2==0)||(i==((n/2)+1) && n%2!=0))
                    {
                        counthalf = count;
                        flag1 = false;
                    }
                }
                deck[count].index = i;
                input >> deck[count++].power;
            }
            for(long long j=0; j<(l[i]-1); ++j)
                input >> temp;
            deck[beginMark].cost = 0;
            long long tempCost = 0;
            for(long long j=beginMark+1; j<count; ++j)
            {
                input >> temp;
                tempCost += temp;
                deck[j].cost = tempCost;
            }
        }
        n=8;
        N=n;
        ::count = count;
        ::counthalf = counthalf;
        std::vector<struct Deck> powerSum1, powerSum2;
        selected.reset();
        if(!::powerSum.empty())
            ::powerSum.clear();
        ::indexz = 0;
        nestedToRecursion(0);
        powerSum1 = ::powerSum;
        selected.reset();
		::powerSum.clear();
        long long index0 = ::indexz;
        ::indexz = 0;
        nestedToRecursion2(0);
        powerSum2 = ::powerSum;
        long long index1 = ::indexz;
        std::sort(powerSum2.begin(), powerSum2.end(), my_cmp);
        long long maxSum = 0;
        for(long long e=0; e<index0; ++e)
        {
            for(long long f=0; f<index1; ++f)
            {
                if((powerSum1[e].totalCost+powerSum2[f].totalCost) > m)
                    continue;
                long long temp = powerSum1[e].totalPower+powerSum2[f].totalPower;
                if(temp > maxSum)
                	maxSum = temp;
                break;
            }
        }
        std::cout << "Case #" << z+1 << ": " << maxSum << "\n";
    }
    input.close();
    output.close();
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    std::cout << elapsed_secs << std::endl;
    return 0;
}
