#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<ctime>
#define MAX 99999

int main()
{
	clock_t begin = clock();
    int t;
    std::fstream input, output;
    //Setting up I/O file streams
    input.open("input.in", std::ios::in);
    output.open("output.out", std::ios::out);
    //Number of test cases
    input >> t;
    for(int i=0; i<t; i++)
    {
        //Number of citizens
        unsigned long long n;
		input >> n;
        std::string names[MAX];
        std::string greatest;
        for(unsigned long long j=0; j<n; j++)
        {
            //Inputting names of citizens for i-th case
            std::getline(input, names[j]);
            //Delete if a blank line is encountered
            if(names[j].empty())
            {
                --j;
                continue;
            }
        }
        //Set the first citizen as the candidate leader
        greatest = names[0];
        for(unsigned long long j=1; j<n; j++)
        {
            //Creating vectors of unique characters from strings.
            std::vector<char> diff1(greatest.begin(), greatest.end());
            std::vector<char> diff2(names[j].begin(), names[j].end());
            //Removing space character (included <algorithm> for std::remove)
            diff1.erase(std::remove(diff1.begin(),diff1.end(),' '), diff1.end());
            diff2.erase(std::remove(diff2.begin(),diff2.end(),' '), diff2.end());
            sort( diff1.begin(), diff1.end() );
            diff1.erase( unique( diff1.begin(), diff1.end() ), diff1.end() );
            sort( diff2.begin(), diff2.end() );
            diff2.erase( unique( diff2.begin(), diff2.end() ), diff2.end() );
            //Comparing number of characters in the candidate leader string and the j-th citizen string
            if(diff1.size() > diff2.size())
            {
                continue;
            }
            //If equal, check which one comes first alphabetically
            else if(diff1.size() == diff2.size())
            {
                if(greatest.at(0) > names[j].at(0))
                {
                    continue;
                }
                else if(greatest.at(0) == names[j].at(0))
                {
                    int ret = greatest.compare(names[j]);
                    if(ret > 0)
                    {
                        //If j-th citizen string comes first alphabetically, set it as the new candidate leader
                        greatest = names[j];
                        continue;
                    }
                    
                }
                else
                {
                    //If j-th citizen string comes first alphabetically, set it as the new candidate leader
                    greatest = names[j];
                    continue;
                }
            }
            //If the number of characters is greater in the j-th citizen string, set it as the new candidate leader
            else
            {
                greatest = names[j];
                continue;
            }
        }
        //Outputting results
        output << "Case #" << i+1 << ": " << greatest << std::endl;
    }
    //Closing file I/O streams
    input.close();
    output.close();
    //Calculating and displaying execution time
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    std::cout << elapsed_secs << std::endl;
    return 0;
}
