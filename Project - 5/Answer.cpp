#include <bits/stdc++.h>

struct vertex_class {
    int value_of_vertex;
    int index_of_vertex_in_the_ordered_array;
};

void scan_all_numbers(int n, vertex_class pClass[], vertex_class *pClass1[]);


int main() {


    std::pair<std::pair<int, int>, std::pair<int, int>> newSetBFS;
    int dfs_sum_of;
    int n;
    std::cin >> n;


    vertex_class all_vertexes_array[2 * n];
    vertex_class *pointer_to_all_created_vertex_classes_as_an_array[2 * n];
    std::list<int> all_neighbors[2 * n];
    bool visited[2 * n];

    scan_all_numbers(n, all_vertexes_array, pointer_to_all_created_vertex_classes_as_an_array);


    //this part of code is taken from https://stackoverflow.com/questions/26479846/how-do-i-sort-array-of-pointers-to-structs-without-changing-original-array
    //sort pointers based of the real value of the pointed value
    std::sort(pointer_to_all_created_vertex_classes_as_an_array,
              pointer_to_all_created_vertex_classes_as_an_array + 2 * n, [](const vertex_class* a, const vertex_class* b)
    { return a->value_of_vertex < b->value_of_vertex; });


    // determine the index of each vertex and also assign the same index for the same values
    int counter = -1;
    pointer_to_all_created_vertex_classes_as_an_array[0]->index_of_vertex_in_the_ordered_array = 0;
    for (const auto &vertex : pointer_to_all_created_vertex_classes_as_an_array) {
        counter++;
        if (counter == 2 * n - 1) break;

        int first = vertex->value_of_vertex;
        int second = (*(&vertex + 1))->value_of_vertex;
        if (first == second) {
            (*(&vertex + 1))->index_of_vertex_in_the_ordered_array = vertex->index_of_vertex_in_the_ordered_array;
        }
        else {
            (*(&vertex + 1))->index_of_vertex_in_the_ordered_array = counter + 1;
        }
    }

    int count = -1;
    for (int x = 0; x < n; x++) {
        count++;
        visited[2 * count] = false;
        visited[2 * count + 1] = false;
        all_neighbors[all_vertexes_array[2 * count].index_of_vertex_in_the_ordered_array].push_back(all_vertexes_array[2 * count + 1].index_of_vertex_in_the_ordered_array);
        all_neighbors[all_vertexes_array[2 * count + 1].index_of_vertex_in_the_ordered_array].push_back(all_vertexes_array[2 * count].index_of_vertex_in_the_ordered_array);
    }





    std::list<std::pair<std::pair<int, int>, std::pair<int, int>>> moalefeyeh_hambany;
    //BFS
    for (int y = 0; y < 2 * n; y++) {
        int this_vertex = y;
        if (!visited[this_vertex] && !all_neighbors[this_vertex].empty()) {
            std::list<int> queue;

            newSetBFS.second.first = this_vertex;
            newSetBFS.first.first = 1;
            dfs_sum_of = 0;
            visited[this_vertex] = true;
            queue.push_back(this_vertex);
            while(!queue.empty())
            {
                this_vertex = queue.front();
                queue.pop_front();

                for (const auto &neighbor : all_neighbors[this_vertex]) {
                    dfs_sum_of++;
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        queue.push_back(neighbor);
                        newSetBFS.first.first++;
                        if (neighbor > newSetBFS.second.first) {
                            newSetBFS.second.second = newSetBFS.second.first;
                            newSetBFS.second.first = neighbor;
                        }
                        else if (neighbor > newSetBFS.second.second && neighbor != newSetBFS.second.first) {
                            newSetBFS.second.second = neighbor;
                        }
                    }
                }
            }
            newSetBFS.first.second = dfs_sum_of;
            std::pair<std::pair<int, int>, std::pair<int, int>> pait_to_add(newSetBFS);
            moalefeyeh_hambany.push_back(pait_to_add);
        }

    }


    bool possible = true;
    int max = 0;

    for (const auto &newSet: moalefeyeh_hambany) {
        std::pair<std::pair<int, int>, std::pair<int, int>> newSetCopy = newSet;
        int vertex_number = newSet.first.first;
        int edge_number = newSet.first.second/2;



        if (vertex_number == 1) {
            int maximum = newSet.second.first;
            maximum = (*pointer_to_all_created_vertex_classes_as_an_array[maximum]).value_of_vertex;
            if (maximum > max) max = maximum;
        }
        else {
            //find two biggest numbers

            int first_max = newSet.second.first;
            first_max = (*pointer_to_all_created_vertex_classes_as_an_array[first_max]).value_of_vertex;

            int second_max = newSet.second.second;
            second_max = (*pointer_to_all_created_vertex_classes_as_an_array[second_max]).value_of_vertex;

            if (edge_number > vertex_number) {
                possible = false;
                break;
            }
            else if (edge_number == vertex_number) {
                max= std::max(first_max, max);
            }
            else if (edge_number + 1 == vertex_number) {
                max= std::max(second_max, max);
            }
            else {
                possible = false;
                break;
            }
        }

    }
    if (possible) {
        std::cout << max;
    }
    else {
        std::cout << "-1";
    }
    return 0;

}

void scan_all_numbers(int n,  vertex_class all_vertexes_array[], vertex_class *pointer_to_all_created_vertex_classes_as_an_array[]) {
    for (int i = 0; i < n; ++i) {

        int first_number, second_number;
        std::cin >> first_number;
        std::cin >> second_number;


        //add first number to vertexes
        vertex_class first_number_struct {
                first_number
        };
        all_vertexes_array[2 * i] = first_number_struct;
        pointer_to_all_created_vertex_classes_as_an_array[2 * i] = &all_vertexes_array[2 * i];


        //add second number to vertexes
        vertex_class second_number_struct {
                second_number
        };
        all_vertexes_array[2 * i + 1] = second_number_struct;
        pointer_to_all_created_vertex_classes_as_an_array[2 * i + 1] = &all_vertexes_array[2 * i + 1];

    }

}






