#include <unordered_set>
#include <set>
#include <iostream>
#include <string>

using namespace std;
class SATSolver{

    
    public:

    //initialize the solver by reading input
    void initialize(){
        char c;
        string s;
        while(true){
            cin >> c;
            if(c == 'c'){ // The character c is a comment in the cnf format
                getline(cin, s); // puts the rest of the line in s
            }
            else{
                cin >> s;
                break; // avoids infinite loop
            }
        }

        // Read the clauses
        cin >> clauses_count;

        for(int i = 0; i < clauses_count; i++){

        }

    }
    void solve(){

    }
    private: 
    int clauses_count;
    std::unordered_set<int> formula;
    set<string> clauses;


};




int main(){
    SATSolver solver;
    solver.initialize();
    solver.solve();
    return 0;
}
