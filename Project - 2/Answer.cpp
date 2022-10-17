#include "bits/stdc++.h"


int number_of_nights(int stack, int pInt[], const int pInt1[], int n);

int main() {
    int n;
    std::cin >> n;
    int array_of_numbers[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> array_of_numbers[i];
    }
    int array_of_nights_to_death[n];
    for (int i = 0; i < n; ++i) {
        array_of_nights_to_death[i] = 0;
    }

//    array_of_nights_to_death[0] = -1;

//    std::stack<int> stack_for_find_the_biggest_number;
    std::stack<int> indexes;
    for (int i = 0; i < n; i++) {
        int item = array_of_numbers[i];
        bool continue_stack = true;
        int largest_night = 0;

        while (continue_stack) {
            int top_in_stack = -1;
            if (!indexes.empty()) {
                top_in_stack = array_of_numbers[indexes.top()];
            }
            if (!indexes.empty() && top_in_stack < item) {
                int index = indexes.top();
                int night = array_of_nights_to_death[index];
                if (night > largest_night) {
                    largest_night = night;
                }
                indexes.pop();
            } else {
                continue_stack = false;
            }
        }
        if (indexes.empty()) {
            array_of_nights_to_death[i] = 0;
        }
        else {
            array_of_nights_to_death[i] = largest_night + 1;
        }
        indexes.push(i);

    }

    int maximum_nights = 0;
    for (const auto &item : array_of_nights_to_death) {
        if (item > maximum_nights) {
            maximum_nights = item;
        }
    }
    std::cout << maximum_nights;



    return 0;
}




