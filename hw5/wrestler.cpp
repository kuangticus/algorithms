/*******************************************************************************
** Program: wrestler.cpp
** Date: 07/27/2018
** Description: This program uses BFS and the bipartite graphs to solve
** possible designation between wrestlers
** Input: External file dictated by the command line during execution.
** Output: Outputs team information, and possible designations if not possible
outputs "IMPOSSIBLE".
** https://www.geeksforgeeks.org/bipartite-graph/ used as reference
** https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/
** used for reference
*******************************************************************************/
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<fstream>
#include<climits>
#include<list>

using namespace std;
/*******************************************************************************
** Class: Graph
** Description: This will be the class that will represent the graph, and edges
** in this class there will be bipartite search functions, and
** Private: V and matrix
** Public: There print_matrix (), add_edge (int, int),
** is_bipartite_main (int**, int team_array[] ), and inBipartiteUtil( int**, int, int*)
** Threre will be
*******************************************************************************/
class Graph {
    int V; // vertex number
    int **matrix; // adjacency matrix
public:
    int **matrix_accessor (); // matrix accessor
    Graph(int V); // constructor
    ~Graph(); // descructor
    void add_edge(int v, int w); // add edge to graph function
    void print_matrix (); // prints matrix, used for testing purposes
    bool is_bipartite_main (int **Graph, int team_array[]); // bipartite main
    bool is_bipartite_helper(int **Graph, int source, int team_array[]);// bipartite helper
};
/*******************************************************************************
** Class Function: matrix_accessor
** Description: accessor of the private matrix in class Graph
** Parameters: none
** Pre-Conditions: Class object must be made, and matrix must exist
** Post-Conditions: returns the matrix
** Returns: matrix
*******************************************************************************/
int** Graph::matrix_accessor(){
    return matrix; // returns the matrix
}
/*******************************************************************************
** Class Function: Graph
** Description: constructor, that makes the matrix, and fills with 0
** Parameters: int V which is the number of wrestlers, nodes
** Pre-Conditions: Class object must be made, and int V exists
** Post-Conditions: Matrix will be made
** Return: none
*******************************************************************************/
Graph::Graph(int V){
    this->V = V; //sets the class object V to local V
    matrix = new int*[V]; // creates a 2d array
    for ( int i = 0; i < V; i++){ // the array colums are created
        matrix[i] = new int[V];
    }
    // fills the matrix with zeros a initialiation.
    for ( int i =0; i < V; i++ ){
        for ( int j  =0; j < V; j++){
            matrix[i][j] = 0; // intiallization of matrix indices
        }
    }
}
/*******************************************************************************
** Function: ~Graph()
** Description: Descructor of the class, frees dynamic memory
** Parameters: none
** Pre-Conditions: Graph class object must exist and made
** Post-Conditions: There will no memory left allocated, no memory leaks from
** class
** Return: none
*******************************************************************************/
Graph::~Graph(){
    for ( int i =0; i < V; i++){
        delete [] matrix[i]; // delete/frees the matrix
    }
    delete [] matrix; // deletes/frees the matrix points
}
/*******************************************************************************
** Class Function: add_edge
** Description: adding the edges in the graph so that they are connected
** Parameters: int v and int w
** Pre-Conditions: the matrix where the edges are added must exist.
** Post-Conditions: There will be edges added to adjacency matrix
** Return: none
*******************************************************************************/
void Graph::add_edge(int i, int j) {
    matrix[i][j] = 1; // sets the matrix edge to 1 if connect, 0 i not connected
}
/*******************************************************************************
** Class Function: print_matrix ()
** Description: prints the completed adjacency matrix, or at any time
** Parameters: none
** Pre-Conditions: the matrix to be printed must exist.
** Post-Conditions: The matrix will be printed.
** Return: none
*******************************************************************************/
void Graph::print_matrix (){
    // this nested loop is used for printing out the matrix, mainly
    // used for testing purposes.
    for ( int i = 0; i < V; i++ ){
        for ( int j =0; j < V; j++) {
            // couts the matrix to indices
            cout << matrix[i][j] << ' ';
        }
    cout << endl;
    }
}
/*******************************************************************************
** Class Function: is_bipartite_main
** Description: checks to see of the graph is bipartite
** Parameters: graph pointer, and color array
** Pre-Conditions: graph must exist, and color array must exist.
** Post-Conditions: the graph will be analysze and check whether it is bipartite
** Return: bool, true if the desigantion exists, false if designation doesn't
*******************************************************************************/
bool Graph::is_bipartite_main(int **Graph, int *team_array) {

    // fills the color array with -1, indicating not teamed up,
    // if 1 that means babyface,
    // if 0 that mean heels.
    for (int i = 0; i < V; ++i)
        team_array[i] = -1; // -1 initialization

    // This code is to handle disconnected graoh
    for (int i = 0; i < V; i++)
        if (team_array[i] == -1) // if not teamed, run
            if (is_bipartite_helper(Graph, i, team_array) == false) // bipartite run
                return false;

    return true;
}
/*******************************************************************************
** Class Function: is_bipartite_helper
** Description: checks to see of the graph is bipartite, helper function of
** is_bipartite_main
** Parameters: graph pointer, source, int *
** Pre-Conditions: graph must exist, and color array must exist, also source node
** is inputted.
** Post-Conditions: the graph will be analysze and check whether it is bipartite
** Return: bool, true if the desigantion exists, false if designation doesn't
*******************************************************************************/
bool Graph::is_bipartite_helper(int ** Graph, int source, int team_array[]) {
    team_array[source] = 1; // selects the first passed in node to be 1

    queue <int> q; // makes a queue to run bfs
    q.push(source);

    // while the queue is not empty run the bfs, alogithm
    while (!q.empty()) {
        int head = q.front();
        q.pop();

        // if the there are the same designation for two nodes
        // then it will comes back as false
        if (Graph[head][head] == 1)
           return false;

        // this will used to run thru the color array to check the
        // the teams, whether a node is 0 or 1, if they are both then
        // the return will be false.
        for (int v = 0; v < V; ++v) {

            // if the node is node assigned yet, then run.
            // An edge from head to v exists and destination v is not colored
            if (Graph[head][v] && team_array[v] == -1) {
                team_array[v] = 1 - team_array[head]; // assing alternate color
                q.push(v);
            }
            // if the nodes are the same color in that edge
            else if (Graph[head][v] && team_array[v] == team_array[head])
                return false; // return no desginatin availiable
        }
    }
    return true;
}
/*******************************************************************************
** Function: main
** Description: main driver of the program, where everything is called
** Parameters: none
** Pre-Conditions: must be ran, first when exexcuting progam
** Post-Conditions: return 0; when exiting
*******************************************************************************/
int main ( int argc, char *argv[] ) {

    // these conditional statements are used to look for the input file
    if (argc != 2){
        // if the inputfile is not include at runtime then false return.
        cout << "Error, invalid arguments." << endl;
    }
    else {
        int wrestlers = 0;
        int rivalries = 0, n = 0, v = 0;
        string name1, name2;
        vector<string> babyface; // babyface container
        vector<string> heel; // heel container

        //opens the inputfile stream that is included with the
        //command line arguments
        ifstream input;
        input.open(argv[1]);

        if( input.good() ) {
            input >> wrestlers; // read the amound of nodes there will be
            int team_array[wrestlers]; // makes a team array for wrestlers
            string array[wrestlers]; // makes a name array for wrestlers
            for ( int i =0; i < wrestlers; i++){
                input >> array[i]; // reads in the names from input file
            }
            // Makes an object called graph to use for to sort, and hold the
            // inputted information.
            Graph graph(wrestlers);
            // inputs the rivalries number into the variable to use in loop
            input >> rivalries;

            // the for loop will run for rivalries amound of times
            for ( int i =0; i < rivalries; i++){
                input >> name1; // name1
                input >> name2; // name2
                //this loop will run the amount of the wrestlers
                // to check each and every single name in the names array
                for ( int j=0; j < wrestlers; j++){
                    if ( name1 == array[j] ) // if name1 equals the array[j]
                        n = j;              // assign the vertex to the adj matrix
                    // if name2 equals the array[j]
                    // assign the vertex to the adj matrix
                    else if (name2  == array[j])
                        v = j;
                }
                graph.add_edge(n, v); // add the edge to the graph
                graph.add_edge(v, n); // add the opposite to the graph,
                // example: adding 2,1 = 1, you must add 1,2 = 1 as well
            }
            //graph.print_matrix(); // tesgin purposes.

            // if the graph is bipartite do the following things.
            if ( graph.is_bipartite_main(graph.matrix_accessor(), team_array) ){
                // run the the loop so that it check the team array
                // and see what team the people are on.
                for ( int i =0; i < wrestlers; i++){
                    // the index at i is equal to 1 in the team array
                    // set that index of the name array to the babyface container
                    if ( team_array[i] == 1 ){
                        babyface.push_back( array[i] );
                    }
                    // the index at i is equal to 0 in the team array
                    // set that index of the name array to the heel container
                    else if ( team_array[i] == 0 ) {
                        heel.push_back(array[i]);
                    }
                }
                // the following lines from 261 - 269, are used to direct and
                // formate the output of the program.
                cout << "Yes possible" << endl;
                cout << "Babyfaces: " ;
                // for loop prints out all of the babyface names
                for ( int i = 0; i < babyface.size(); i++ )
                    cout << babyface[i] << ' ';
                cout << endl;
                cout << "Heels: " ;
                // for loop prints of all of the heel names
                for ( int i = 0; i < heel.size(); i++ )
                    cout << heel[i] << ' ';
                cout << endl;
            }
            else
                // prints out the impossible if the names
                // can not be designated.
                cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
