#include <unordered_set>
#include <set>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class SATSolver
{

public:
    // initialize the solver by reading input
    void initialize()
    {
        char c;
        string s;

        // Read the input cnf file
        while (true)
        {
            cin >> c;
            if (c == 'c')
            {                    // The character c is a comment in the cnf format
                getline(cin, s); // puts the rest of the line in s
            }
            else
            {
                cin >> s;
                break; // avoids infinite loop
            }
        }

        // Read number of literals and clauses (works because of cnf format)
        cin >> literals_count;
        cin >> clauses_count;
        
        // IMPORTANT: Resize vectors to avoid segmentation fault!
        clauses.clear();
        clauses.resize(clauses_count);
        literal_frequency.clear();
        literal_frequency.resize(literals_count, 0);
        literal_polarity.clear();
        literal_polarity.resize(literals_count, 0);
        
        int literal; // store the incoming literal value
        for (int i = 0; i < clauses_count; i++)
        {
            while (true)
            {
                cin >> literal;
                if (literal == 0)
                {
                    break; // end of clause
                }
                // Literal has positive polarity
                else if (literal > 0)
                {
                    clauses[i].push_back(literal);
                    literal_frequency[literal - 1]++; // increment frequency of this literal
                    literal_polarity[literal - 1]++;  // increment polarity of this literal
                }
                else if (literal < 0)
                {
                    clauses[i].push_back(literal);
                    literal_frequency[-1 - literal]++; // increment frequency of this literal
                    literal_polarity[-1 - literal]--;  // decrement polarity of this literal
                }
            }
            
        }
        
        


    }

    void solve()
    {
    }

private:
    int clauses_count;
    int literals_count;
    bool already_unsatisfied = false;
    vector<vector<int>> clauses;
    vector<int> literal_frequency;
    vector<int> literal_polarity;
    vector<int> assigned_literals;
};

int main()
{
    SATSolver solver;
    solver.initialize();
    solver.solve();
    return 0;
}
