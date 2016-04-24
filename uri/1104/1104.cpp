#include <cstdio>
#include <set>
#include <algorithm>

int main() {
    int a, b, aux;

    while (scanf("%d %d", &a, &b) && a && b) {
        std::set<int> cards_a;
        std::set<int> cards_b;
        std::set<int> cards_b_not_in_a;
        std::set<int> cards_a_not_in_b;

        while (a--) {
            scanf("%d", &aux);
            cards_a.insert(aux);
        }

        std::set<int>::iterator it_a = cards_a.begin();

        while (b--) {
            scanf("%d", &aux);

            cards_b.insert(aux);

            while (*it_a < aux && it_a != cards_a.end()) ++it_a;

            if (it_a == cards_a.end() || *it_a != aux) {
                cards_b_not_in_a.insert(aux);
            }
        }

        std::set<int>::iterator it_b = cards_b.begin();

        for (it_a = cards_a.begin(); it_a != cards_a.end(); ++it_a) {
            while (*it_b < *it_a && it_b != cards_b.end()) ++it_b;

            if (it_b == cards_b.end() || *it_b != *it_a) {
                cards_a_not_in_b.insert(*it_a);
            }
        }

        if (cards_a_not_in_b.size() < cards_b_not_in_a.size()) {
            printf("%d\n", cards_a_not_in_b.size());
        } else {
            printf("%d\n", cards_b_not_in_a.size());
        }
    }

    return 0;
}
