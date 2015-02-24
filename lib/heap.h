#pragma once

#include <vector>

template <typename T, typename sizeT = int>
class heap {
    sizeT n;
    std::vector<T> container;
    
public:
    heap() {
        n = 0;
        container.push_back(0);
    }
    
    void print() {
        for (sizeT i = 1; i <= n; i++) std::cout << container[i] << " ";
        std::cout << "n = " << n;
        std::cout << std::endl;
    }
    
    void insert(T a) {
        n++;
        container.push_back(a);
        
        sizeT k = n;
        while(k > 1) {
            sizeT p = k >> 1;
            if (container[k] < container[p]) {
                std::swap(container[k], container[p]);
                k = p;
            } else break;
        }
    }
    
    T get_top() {
        return container[1];
    }
    
    T pop_top() {
        T ret = container[1];
        
        container[1] = container[n];
        n--;
        
        sizeT k = 1;
        while(k <= n >> 1) {
            sizeT c = k << 1;
            sizeT kmn;
            T mn = container[k];
            for (int j = 0; j < 2; j++) {
                sizeT cj = c + j;
                if (cj <= n && mn > container[cj]) {
                    mn = container[cj];
                    kmn = cj;
                }
            }
            if (mn != container[k]) {
                std::swap(container[k], container[kmn]);
                k = kmn;
            } else break;
        }
        
        return ret;
    }
};