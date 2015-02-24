#pragma once

#include <vector>

template <typename number_type>
class set_union {
public:
    number_type n;
    std::vector<number_type> p;
    std::vector<number_type> size;
    
    set_union(const number_type n) : n(n), size(n + 1, 1) {
        for (number_type i = 0; i<=n; i++) {
            p.push_back(i);
        }
    }
    
    number_type find(const number_type x) const {
        if (p[x] == x) {
            return x;
        } else {
            return find(p[x]);
        }
    }
    
    void union_sets(const number_type s1, const number_type s2) {
        number_type r1, r2;
        r1 = find(s1);
        r2 = find(s2);
        if (r1 == r2) return;
        if (size[r1] >= size[r2]) {
            size[r1] = size[r1] + size[r2];
            p[r2] = r1;
        }
        else {
            size[r2] = size[r1] + size[r2];
            p[r1] = r2;
        }
    }
    
    bool same_component(const number_type s1, const number_type s2) {
        return find(s1) == find(s2);
    }
};
