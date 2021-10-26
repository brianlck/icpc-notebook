#pragma once
#include "general.hpp"
template <class T> class MaxFlow {
    public:
    struct Edge {
        int v, nextEdge;
        T capacity;
        Edge (int v, T capacity, int nextEdge) : v(v), capacity(capacity), nextEdge(nextEdge) {}
    };

    MaxFlow(int n) : n(n) {
        source = 0, sink = n + 1;
        head = vector<int>(n+5, -1);
        BFSQueue.reserve(n+5);
    }

    void addEdge (int u, int v, T capacity) {
        edges.emplace_back(v, capacity, head[u]);
        head[u] = edges.size() - 1;
        edges.emplace_back(u, 0, head[v]);
        head[v] = edges.size() - 1;
    }

    T get_result() {
        T res = 0;
        while (countLayer(source, sink))
            res += augment(source, sink, INF);
        return res; 
    }
    
    bool countLayer(int source, int sink) {
        cur = head;
        layer.assign(n+5, 0);
        BFSQueue[QueHead = 0] = source;
        QueTail = 1;
        layer[source] = 1;
        while (QueHead < QueTail) {
            int u = BFSQueue[QueHead++];
            for (int p = head[u]; p != -1; p = edges[p].nextEdge) {
                int v = edges[p].v;
                if (!layer[v] && edges[p].capacity) {
                    layer[v] = layer[u] + 1;
                    BFSQueue[QueTail++] = v;
                if (v == sink) return true;
                }
            }
        }
        return false;
    }

    T augment (int u, int sink, T flow) {
        T curFlow = flow;
        if (u == sink) return flow;
        for (int p = cur[u]; p != -1; p = edges[p].nextEdge) {
            int v = edges[p].v, &cap = edges[p].capacity;
            cur[u] = p;
            if (cap && layer[v] == layer[u] + 1 && curFlow) {
                T augmentedFlow = augment(v, sink, min(curFlow, cap));
                curFlow -= augmentedFlow;
                cap -= augmentedFlow;
                edges[p ^ 1].capacity += augmentedFlow;
                if (curFlow == 0) return flow;
            }
        }
        return flow - curFlow;
    }

    const T INF = is_same<T, long long>::value ? 1e17 : 1e8;
    int source, sink;
    int n;
    
    vector<int> head;
    vector<int> layer;
    vector<int> cur;
    vector<Edge> edges;
    vector<int> BFSQueue;
    int QueHead;
    int QueTail;
};