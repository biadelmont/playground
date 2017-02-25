#include <algorithm>
#include <cstring>
#include <iostream>

#define INFINITY 1000001

int blocks[26];

int minimum_blocks(int m, int n) {
    int j;
    int result[m + 1], i;

    result[0] = 0;
    for (i = 1; i <= m; i++) {
        result[i] = INFINITY;
    }

    for (j = 0; j < n; j++) {
        for (i = blocks[j]; i <= m; i++) {
            result[i] = std::min(result[i], result[i - blocks[j]] + 1);
        }
    }

    return result[m];
}

int main() {
    int i, t, n;
    int m;

    std::cin >> t;

    while (t--) {
        std::cin >> n >> m;

        memset(blocks, 0, sizeof(blocks));

        for (i = 0; i < n; i++) std::cin >> blocks[i];

        std::sort(blocks, blocks + n);
        std::cout << minimum_blocks(m, n) << std::endl;
    }

    return 0;
}
