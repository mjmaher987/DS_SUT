#include <iostream>
#include <cmath>

int calculate_answer(int starting_index, int ending_index, char string[], int total_score);

int main() {
    int n = 0;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; ++i) {
        std::string string_input;
        std::cin >> string_input;
        char array1[string_input.size()];
        for (int j = 0; j < string_input.size(); ++j) {
            array1[j] = string_input[j];
        }
        array[i] = calculate_answer(0, string_input.size()-1, array1, 0);
    }
    for (const auto &item : array) {
        std::cout << item << "\n";
    }
    return 0;
}

int calculate_answer(int starting_index, int ending_index, char string[], int total_score) {
    long long int hashed_one = 0;
    long long int hashed_two = 0;
    int counter = 0;
    long long int p_power = 1;
    while (true) {
        if (starting_index + counter > ending_index - counter && counter == 0) {
            return total_score;
        }
        if (starting_index + counter > ending_index - counter && counter != 0) {
            return total_score + 1;
        }
        if (starting_index + counter == ending_index - counter) {
            return total_score + 1;
        }
        long long int temp1 = string[starting_index + counter] - 'a' + 1;
        long long int temp2 = string[ending_index - counter] - 'a' + 1;
        hashed_one = (hashed_one * 26 + temp1) % 1000000007;
        hashed_two = (hashed_two % 1000000007) + ((temp2 * p_power) % 1000000007);



        if ((hashed_one - hashed_two) % 1000000007 == 0) {
            return calculate_answer(starting_index + counter + 1, ending_index - counter - 1, string, total_score + 2);
        }
        counter++;
        p_power *= 26;
        p_power %= 1000000007;
    }
}
