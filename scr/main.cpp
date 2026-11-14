#include <unordered_set>
#include <set>
#include <iostream>
#include <vector>

using namespace std;

enum RetValues
{
    SAT,
    UNSAT,
    NO_SOLUTION
};

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

        assigned_literal_count = 0;
        kappa = -1;
        pick_counter = 0;
        already_unsatisfied = false;

        // IMPORTANT: Resize vectors to avoid segmentation fault!
        literals.clear();
        literals.resize(literals_count, -1);
        literals_per_clause.clear();
        literals_per_clause.resize(clauses_count);
        literal_frequency.clear();
        literal_frequency.resize(literals_count, 0);
        literal_polarity.clear();
        literal_polarity.resize(literals_count, 0);
        literals_per_clause.clear();
        literals_per_clause.resize(clauses_count);
        literal_antecedent.clear();
        literal_antecedent.resize(literals_count, -1);
        literal_decision_level.clear();
        literal_decision_level.resize(literals_count, -1);

            int literal; // store the incoming literal value
        int literals_count_in_clause = 0;
        for (int i = 0; i < clauses_count; i++)
        {
            literals_count_in_clause = 0;
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
                    literals_per_clause[i].push_back(literal);
                    literal_frequency[literal - 1]++; // increment frequency of this literal
                    literal_polarity[literal - 1]++;  // increment polarity of this literal
                }
                else if (literal < 0)
                {
                    literals_per_clause[i].push_back(literal);
                    literal_frequency[-1 - literal]++; // increment frequency of this literal
                    literal_polarity[-1 - literal]--;  // decrement polarity of this literal
                }
                else
                {
                    if (literals_count_in_clause == 0)
                    {
                        already_unsatisfied = true;
                    }
                    break; // end of clause
                }
            }
            literals_count_in_clause++;
        }

        original_literal_frequency = literal_frequency; // jump back after branching
    }

    int CDCL(){}

    void show_result(int result){}

    void solve()
    {
        int result = CDCL();
        show_result(result);
    }

private:
    int clauses_count;
    int literals_count;
    int kappa;
    int assigned_literal_count;
    int pick_counter;
    bool already_unsatisfied = false;
    vector<int> literals;
    vector<vector<int>> literals_per_clause;
    vector<int> literal_frequency;
    vector<int> literal_polarity;
    vector<int> assigned_literals;
    vector<int> original_literal_frequency;
    vector<int> literal_decision_level;
    vector<int> literal_antecedent;
};

int main()
{
    SATSolver solver;
    solver.initialize();
    solver.solve();
    return 0;
}
