#include <iostream>
#include <queue>
#include <array>
#include <algorithm>
using namespace std;
// abstract data type of graph
class Graph
{
    public:
        virtual ~Graph(){}
        bool IsEmpty() const { return n == 0; }
        int NumOfVertices() const {return n; }
        int NumOfEdges() const {return e; }
        virtual int Degree(int u) const = 0; // return edge on vertex u
        virtual bool ExistsEdge(int u, int v) const = 0;  // return true if edge (u,v) exist
        virtual void InstertVertex(int v) = 0; 
        virtual void InsertEdge(int u, int v) = 0;
        virtual void DeleteVertex(int v) = 0; 
        virtual void DeleteEdge(int u, int v) = 0;
    private:
        int n; // # of vertices
        int e; // # of edge
};

/*
    representation of graphs
    1. adjacency matrix
    2. adjacency list
    3. sequential list
    4. adjacency multilists
*/

// the Chain ADT is in previous chapter
/*
class linkedgraph: public Graph{
    public:
        linkedgraph(const int vertices = 0): n(vertices), e(0){
            adjlist = new Chain<int>[n];
        }
    private:
        Chain<int> *adjlist;
};
*/
