// 백준 1647번: 도시 분할 계획

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN = 100000+1;
const int maxM = 1000000;

struct Edge{
public:
    int start;
    int end;
    int cost;
    Edge() : start(0), end(0), cost(0){}
    Edge(int start, int end, int weight) : start(start), end(end), cost(weight){}
};
int parents[maxN];
Edge roads[maxM];

int parent(int x){
    if (parents[x] == x) return x;
    else return parents[x] = parent(parents[x]);
}

bool sameParent(int x, int y){
    if (parent(x) == parent(y)){
        return true;
    } else{
        return false;
    }
}

void Union(int x, int y){
    x = parent(x);
    y = parent(y);
    if (x != y){
        parents[y] = x;
    }
}

bool cmpbyCost(const Edge&a, const Edge&b){
    return a.cost < b.cost;
}

int solve(Edge roads[], int M){
    int sum = 0;
    vector<Edge> kruskal;
    for (int i = 0; i < M; i++){
        if (!sameParent(roads[i].start, roads[i].end)){
            Union(roads[i].start, roads[i].end);
            kruskal.push_back(roads[i]);
        } 
    }
    kruskal.pop_back();

    for (int i = 0; i < kruskal.size(); i++){
        //cout << kruskal[i].start << " " << kruskal[i].end << " " << kruskal[i].cost << "\n";
        sum += kruskal[i].cost;
    }
    return sum;
}

void printEdges(Edge edges[], long int N){
    for (int i = 0; i < N; i++){
        cout << edges[i].start << " " << edges[i].end << " " << edges[i].cost << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        int s, e, c;
        cin >> s >> e >> c;
        Edge add = Edge(s, e, c);
        roads[i] = add;
        parents[s] = s; parents[e] = e;
    }
    sort(roads, roads + M, cmpbyCost);


    cout << solve(roads, M) << "\n";
    return 0;
}