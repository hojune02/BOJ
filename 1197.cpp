//백준 1197번: 최소 스패닝 트리
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const long int maxNode = 10000 + 1;
const long int maxEdge = 100000;

struct Edge{
public:
    long int start;
    long int end;
    long int weight;
    Edge() : start(0), end(0), weight(0){}
    Edge(int start, int end, int weight) : start(start), end(end), weight(weight){}

};
long int parent[maxNode];
Edge edges[maxEdge];


int findParent(long int x){
    if (parent[x] == x) return x;
    else return parent[x] = findParent(parent[x]);
}

bool sameParent(long int x, long int y){
    x = findParent(x);
    y = findParent(y);
    if (x==y) return true;
    else return false;
}

void Union(long int x, long int y){
    x = findParent(x);
    y = findParent(y);
    if (x != y){
        parent[y] = x;
    }
}

long int solve(Edge edges[], long int E){
    vector<Edge> kruskal;
    long int sum = 0;
    for (int i = 0; i < E; i++){
        if(!sameParent(edges[i].start, edges[i].end)){
                Union(edges[i].start, edges[i].end);
                kruskal.push_back(edges[i]);
        } else{
            continue;
        }
    }
   //cout << "\n";
    for (int i = 0; i < kruskal.size(); i++){
        //cout << kruskal[i].start << " " << kruskal[i].end << " " <<  kruskal[i].weight << "\n";
        sum += kruskal[i].weight;
    }
    return sum;
}

bool compareByWeight(const Edge&a, const Edge&b){
    return a.weight < b.weight;
}

void printEdges(Edge edges[], long int N){
    for (int i = 0; i < N; i++){
        cout << edges[i].start << " " << edges[i].end << " " << edges[i].weight << "\n";
    }
}

int main(){
    long int V, E;
    cin >> V >> E;

    for (int i = 0; i < E; i++){
        int s, e, w;
        cin >> s >> e >> w;
        Edge add = Edge(s, e, w);
        edges[i] = add;
        parent[s] = s; parent[e] = e;
    }
    sort(edges, edges + E, compareByWeight);
    //printEdges(edges, E);

    cout << solve(edges, E) << "\n";


    return 0;
}