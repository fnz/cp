#pragma once

template <typename number_type>
class graph {
public:
    struct edge {
        number_type y;
        number_type weight;
    };
    std::vector<std::list<edge> > edges;
    std::vector<number_type> degree, parent;
    std::vector<bool> processed, discovered;
    std::vector<number_type> tag;
    number_type n_verts;
    number_type n_edges;
    bool dir;
    bool finished;
    
    graph(number_type n_verts_, bool dir_ = false) : n_verts(n_verts_), n_edges(0), dir(dir_) {
        for (number_type i = 0; i <= n_verts; i++) {
            degree.push_back(0);
            parent.push_back(0);
            processed.push_back(0);
            discovered.push_back(0);
            tag.push_back(0);
            edges.push_back(std::list<edge>());
            finished = false;
        }
    }
    
    virtual void insert_edge(number_type x, number_type y, bool directed = false, number_type weight = 0) {
        edge e;
        e.y = y;
        e.weight = weight;
        edges[x].push_front(e);
        degree[x]++;
        if (!directed) {
            insert_edge(y, x, true);
        } else {
            n_edges++;
        }
    }
    
    virtual void remove_edge(number_type x, number_type y, bool directed = false) {
        std::list<edge>& edges_ = edges[x];
        for (typename std::list<edge>::iterator it = edges_.begin(); it != edges_.end(); ++it) {
            if (it->y == y) {
                edges[x].erase(it);
                break;
            }
        }
        degree[x]--;
        if (!directed) {
            remove_edge(y, x, true);
        } else {
            n_edges--;
        }
    }
    
    virtual void clear_vertex(number_type v) {
        std::list<edge> edges_ = edges[v];
        for (typename std::list<edge>::iterator it = edges_.begin(); it != edges_.end(); ++it) {
            remove_edge(v, it->y, dir);
        }
    }
    
    virtual void init_search() {
    	for (number_type i = 1; i <= n_verts; i++) {
    		discovered[i] = false;
    		processed[i] = false;
    	}
    }
    
    number_type get_components_count() {
    	number_type c = 0;
    	init_search();
		for (number_type i = 1; i <= n_verts; i++) {
			if (!discovered[i]) {
				c++;
				bfs(i);
			}
		}
		return c;
	}
    
    void bfs() {
    	init_search();
		for (number_type i = 1; i <= n_verts; i++) {
			if (!discovered[i]) {
				bfs(i);
			}
		}
    }
    
    void bfs(number_type start) {
        std::queue<number_type> q;
        q.push(start);
        discovered[start] = true;
        while (!q.empty()) {
            number_type v = q.front();
            q.pop();
            process_vertex_early(v);
            processed[v] = true;
            std::list<edge>& edges_ = edges[v];
            for (typename std::list<edge>::const_iterator it = edges_.begin(); it != edges_.end(); ++it) {
                int y = it->y;
                if (!discovered[y]) {
                    parent[y] = v;
                }
                if (!processed[y] || dir) {
                    process_edge(v, *it);
                }
                if (!discovered[y]) {
                    q.push(y);
                    discovered[y] = true;
                }
            }
            process_vertex_late(v);
        }
    }
    
    void dfs(number_type v) {
        //if (finished) return;
        //time = time + 1;
        //entry_time[v] = time;
        discovered[v] = true;
        process_vertex_early(v);
        processed[v] = true;
        std::list<edge>& edges_ = edges[v];
        for (typename std::list<edge>::const_iterator it = edges_.begin(); it != edges_.end(); ++it) {
            number_type y = it->y;
            if (!discovered[y]) {
                parent[y] = v;
            }
            if (!processed[y] || dir) {
                process_edge(v, *it);
            }
            if (!discovered[y]) {
                dfs(y);
            }
            if (finished) return;
        }
        process_vertex_late(v);
        //time = time + 1;
        //exit_time[v] = time;
    }
    
    void dfs() {
    	init_search();
		for (number_type i = 1; i <= n_verts; i++) {
			if (!discovered[i] && tag[i] == 0) {
				dfs(i);
			}
		}
    }
    
    std::vector<number_type> find_path(number_type v1, number_type v2) {
        std::vector<number_type> path;
        init_search();
        if (find_path_dfs(v1, v2)) {
            number_type v = v2;
            while (v != v1) {
                path.push_back(v);
                v = parent[v];
            }
            path.push_back(v1);
        }
        return path;
    }
    
    bool find_path_dfs(number_type v1, number_type v2) {
        if (v1 == v2) {
            return true;
        }
        discovered[v1] = true;
        std::list<edge>& edges_ = edges[v1];
        for (typename std::list<edge>::const_iterator it = edges_.begin(); it != edges_.end(); ++it) {
            number_type y = it->y;
            if (!discovered[y]) {
                parent[y] = v1;
                if (find_path_dfs(y, v2)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    
    virtual void process_vertex_early(int v) {
        
    }
    
    virtual void process_vertex_late(int v) {
        
    }
    
    virtual void process_edge(int x, edge e) {
        
    }
    
    int get_spanning_forest_edges_count() {
    	number_type e = 0;
    	init_search();
    	for (int i = 1; i < n_verts; i++) {
    		if (discovered[i]) continue;
    		e += get_spanning_tree_edges_count(i);
    	}
    	return e;
    }
    
    int get_spanning_tree_edges_count(number_type v) {
        number_type e = 0;
        discovered[v] = true;
        std::list<edge>& edges_ = edges[v];
        for (typename std::list<edge>::const_iterator it = edges_.begin(); it != edges_.end(); ++it) {
            number_type y = it->y;
            if (!discovered[y]) {
                parent[y] = v;
            }
            if (!discovered[y] || dir) {
                e++;
            }
            if (!discovered[y]) {
                e += get_spanning_tree_edges_count(y);
            }
        }
        return e;
    }
    
    std::vector<std::vector<number_type> > find_cycles() {
        init_search();
        std::vector<std::vector<number_type> > cycles;
        std::vector<number_type> stack;
        for (number_type i = 1; i < n_verts; i++) {
            if (discovered[i]) continue;
            find_cycles_dfs(i, stack, cycles);
        }
        return cycles;
    }
    
    void find_cycles_dfs(number_type v, std::vector<number_type>& stack, std::vector<std::vector<number_type> >& cycles) {
        stack.push_back(v);
        discovered[v] = true;
        std::list<edge>& edges_ = edges[v];
        for (typename std::list<edge>::const_iterator it = edges_.begin(); it != edges_.end(); ++it) {
            number_type y = it->y;
            if (!discovered[y]) {
                parent[y] = v;
            }
            if (discovered[y] && parent[v] != y) {
                add_cycle(y, stack, cycles);
            }
            if (!discovered[y]) {
                find_cycles_dfs(y, stack, cycles);
            }
        }
        processed[v] = true;
        stack.pop_back();
    }
    
    void add_cycle(number_type v, std::vector<number_type>& stack, std::vector<std::vector<number_type> >& cycles) {
        std::vector<number_type> cycle;
        for (number_type i = (number_type)stack.size() - 1; i >= 0; i--) {
            cycle.push_back(stack[i]);
            if (stack[i] == v) {
                cycles.push_back(cycle);
                return;
            }
        }
    }
    
    virtual void print() {
        std::cout << "verts = " << n_verts << std::endl;
        std::cout << "edges = " << n_edges << std::endl;
        for (number_type i = 1; i <= n_verts; i++) {
            if (degree[i] == 0) {
                continue;
            }
            std::cout << "vert #" << i << " degree = " << degree[i] << std::endl;
            
            for (typename std::list<edge>::const_iterator it = edges[i].begin(); it != edges[i].end(); ++it) {
                std::cout << "   " << i << " -> " << it->y << " weight = " << it->weight << std::endl;
            }
        }
    }
};
