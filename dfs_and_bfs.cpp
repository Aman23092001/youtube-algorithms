#include <bits/stdc++.h>

class Graph
{
    int _N;
    std::list<int> *_g;
    bool *_visited;
    std::queue<int> _queue;
    void _dfsUtil(int _i);
    public:
    Graph(int _N);
    void _addEdge(int u, int v);
    void _dfs(int _s);
    void _bfs(int _s);
};

Graph::Graph(int _N)
{
    this->_N = _N;
    _g = new std::list<int>[_N];
    _visited = new bool[_N];
    for(int _i = 0; _i < _N; _i++)
        _visited[_i] = false;
}

void Graph::_addEdge(int u, int v)
{
    _g[u].push_back(v);
    _g[v].push_back(u);
}

void Graph::_dfsUtil(int _i)
{
    if(_visited[_i])
        return;
    _visited[_i] = true;
    std::cout<<_i<<std::endl;
    for(auto _x: _g[_i])
    {
        _dfsUtil(_x);
    }
}

void Graph::_dfs(int _s)
{
        _dfsUtil(_s); 
}

void Graph::_bfs(int _s)
{
    _queue.push(_s);
    _visited[_s] = true;

    while(!_queue.empty())
    {
        for(auto x: _g[_queue.front()])
        {
            if(!_visited[x])
            {
                _queue.push(x);
                _visited[x] = true;
            }
        }
        std::cout<<_queue.front()<<std::endl;
        _queue.pop();

    }
}
int main()
{
    Graph _graph(5);
    _graph._addEdge(0, 1);
    _graph._addEdge(0, 3);
    _graph._addEdge(0, 4);
    _graph._addEdge(1, 2);
    _graph._addEdge(1, 3);
    _graph._addEdge(2, 3);
    _graph._addEdge(3, 4);

    _graph._bfs(0);
    return 0;
}