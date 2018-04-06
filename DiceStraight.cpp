#include <iostream>
#include <fstream>
#include <algorithm>
#include <bitset>
#include <conio.h>

#define BSIZE 101
//#define BSIZE 300001 //Use this for large input

using namespace std;

struct face {
    long long int val;
    long long int dnum;
};

//long long int* sol = NULL;

long long int n;

bool facecompare(face lhs, face rhs)
{
    return lhs.val < rhs.val;
}

long long int calcLen(long long int i, struct face dices[], bitset<BSIZE> selected, long long int len)
{
    //Memo code appears to be faulty, removing...
	//if (len + (n * 6 - i) <= sol[i])
    //    return sol[i];
    /*if (i >= (n * 6 - 1)) {
        sol[i] = len;
        return sol[i];
    }*/
    long long int currLen = len, maxLen = len, start;
    start = i++;
    bool next = false;
    while (dices[i].val == dices[start].val) {
    	if (i == (n * 6 - 1)) //investigate these further
            break;
        bitset<BSIZE> selectedb;
        selectedb.set(dices[i].dnum);
        currLen = calcLen(i, dices, selectedb, 1);
        if (currLen > maxLen) 
            maxLen = currLen;
        next = true; //?? added later. you sure about this?
        i++;
    }
    while (dices[i].val == (dices[start].val + 1)) {
    	if (i == (n * 6 - 1)) //investigate these further
            break;
        next = true; //?? added later. you sure about this?
        if (selected[dices[i].dnum]) {
            bitset<BSIZE> selectedb;
            selectedb.set(dices[i].dnum);
            currLen = calcLen(i, dices, selectedb, 1);
            if (currLen > maxLen) 
                maxLen = currLen;
            //next = true; //?? adding below as well //Original
            i++;
            continue;
        }
        bitset<BSIZE> selectedb;
        selectedb.set(dices[i].dnum);
        currLen = calcLen(i, dices, selectedb, 1);
        if (currLen > maxLen)
            maxLen = currLen;
        selected.set(dices[i].dnum);
        currLen = calcLen(i, dices, selected, len + 1);
        selected.set(dices[i].dnum, false);
        if (currLen > maxLen)
            maxLen = currLen;
        i++;
    }
    if (!next) {
        if (i != (n * 6 - 1)) { // refactor?
            selected.reset();
            selected.set(dices[i].dnum);
            currLen = calcLen(i, dices, selected, 1);
            if (currLen > maxLen)
                maxLen = currLen;
        }
    }
    //for (long long int x = start; x < i; ++x)	//Something probably wrong with this section anyway
    //    sol[x] = maxLen;
    //return sol[i - 1];
    return maxLen;
}

int main()
{
    int t;
    ifstream in("in.txt");
    streambuf* cinbuf = std::cin.rdbuf();
    cin.rdbuf(in.rdbuf());
    cin >> t;
    for (int a = 0; a < t; ++a) {
        long long int k = 0, len, max = 0;
        cin >> n;
        struct face dices[n * 6];
        bitset<BSIZE> selected;
        for (long long int b = 0; b < n; ++b) {
            for (int c = 0; c < 6; ++c) {
                cin >> dices[k].val;
                dices[k++].dnum = b;
            }
        }
        sort(dices, dices + k, facecompare);
        /*sol = new long long int[k];
        for (long long int b = 0; b < k; ++b)
            sol[b] = -1;*/
        selected.set(dices[0].dnum);
        max = calcLen(0, dices, selected, 1);
        cout << "Case #" << a + 1 << ": " << max << endl;
        //delete[] sol;
        //sol = NULL;
    }
    return 0;
}
