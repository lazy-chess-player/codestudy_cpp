#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream outfile("output.txt");
    for (int i = 1; i <= 1000; i++)
    {
        outfile << i << endl;
    }
    outfile.close();
    return 0;
}
