#include <bits/stdc++.h>


int main() {
    std::set<long long int, std::less<>> setOfEntered;
    std::map<long long int, long long int> mapOfEntered;
    std::map<long long int, char> map2char;

    setOfEntered.insert(0);
    mapOfEntered[0] = 0;
    map2char[0] = 'U';

    long long int n = 0, m = 0;
    std::cin >> n >> m;


    setOfEntered.insert(n+1);
    mapOfEntered[n + 1] = 0;
    map2char[0] = 'L';


    for (int i = 0; i < m; ++i) {
        long long int x = 0, y = 0;
        char character;
        std::cin >> x >> y >> character;
        auto before = setOfEntered.lower_bound(x);
        if (*before == x) {
            std::cout << "0\n";
        }
        else {
            setOfEntered.insert(x);
            map2char[x] = character;

            if (character == 'U') {
                auto x_of_upper = setOfEntered.upper_bound(x);
                if (map2char[*x_of_upper] == 'U') {
                    long long int height = mapOfEntered[*x_of_upper];
                    mapOfEntered[x] = *x_of_upper - x + height;
                    std::cout << mapOfEntered[x] << "\n";
                } else {
                    mapOfEntered[x] = *x_of_upper - x;
                    std::cout << mapOfEntered[x] << "\n";
                }
            }

            else {
                auto x_of_lower = setOfEntered.lower_bound(x);
                if (*x_of_lower != 0) {
                    x_of_lower--;
                }
                if (map2char[*x_of_lower] == 'L') {
                    long long int height = mapOfEntered[*x_of_lower];
                    mapOfEntered[x] = x - *x_of_lower + height;
                    std::cout << mapOfEntered[x] << "\n";
                } else {
                    mapOfEntered[x] = x - *x_of_lower;
                    std::cout << mapOfEntered[x] << "\n";
                }
            }
        }


    }

    return 0;
}
