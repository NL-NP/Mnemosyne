#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<numeric>
#include<random>
using namespace std;

int main()
{
    int gridsize, least_var;
    cout << "gridsize:";
    cin >> gridsize;
    cout << "least_var:";
    cin >> least_var;
    string C="|"; //"; // c|c|c|...
    string Row; //) "some stuff in like a& b& c&... "(\\\hline

    int i;
    for (i = 0; i < gridsize; i++)
    {
        C+="c|";
        
    }
    int N = (gridsize*gridsize);
    vector<string> a(N);
    for (int q = 0; q < N; ++q) {
        a[q] = to_string(least_var + q);
    }
    cout << endl;
    auto rng = default_random_engine {};
    shuffle(begin(a), end(a), rng);
    cout << "CHECKPOINT" << endl;

    for (int r=0; r<gridsize; r++)
    {
        for (int u=0; u<gridsize; u++)
        {
            Row += a[u+r];
            if (u<(gridsize-1)){Row += "&";}
        }
        Row += R"(\\\hline
        )";
    }

    cout << R"(
        \begin{table}[h]
        \centering
        \begin{tabular}{)"+C+ R"(}\hline
        )"+Row+    
        R"(
        \end{tabular}
        \end{table}
        )" 
        << endl;

}
