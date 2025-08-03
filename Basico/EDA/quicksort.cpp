#include <iostream>
#include <vector>
using namespace std;

class QuickSort {
    public:
        static std::vector<int> mergeArray(std::vector<int> left, std::vector<int> right, int pivot) {
            std::vector<int> merged;

            merged.reserve(left.size() + 1 + right.size()); // eserva espaço na memória para o vetor merged de forma a comportar todos os elementos de left e right juntos. Isso evita realocações múltiplas conforme elementos são inseridos, o que melhora a performance.
            merged.insert(merged.end(), left.begin(), left.end()); // Insere todos os elementos do vetor left no final de merged
            merged.push_back(pivot);                           
            merged.insert(merged.end(), right.begin(), right.end()); // Insere todos os elementos do vetor left no final de merged

            return merged;

        };
        static std::vector<int> sort(std::vector<int> arr) {
            std::cout << "Starting QuickSort..." << std::endl;

            std::vector<int> left;
            std::vector<int> right;
            // Base case: if the array is empty or has one element, it's already sorted
           if (arr.size() <= 1) {
                std::cout << "Array is already sorted or has one element." << std::endl;
                return arr; // Base case: array is already sorted
            }else{
                //selecting the pivot as the last element
                int pivot = arr[0];

                for(int i = 1; i < arr.size(); ++i) {
                    if (arr[i] < pivot) {
                        left.push_back(arr[i]);
                    } else {
                        right.push_back(arr[i]);
                    }
                }
                return mergeArray(QuickSort::sort(left), QuickSort::sort(right), pivot);
            }

          
           return arr;
        };

};

int main(){
    std::cout << "hello world" << std::endl;
    std::vector<int> vec = {3,7,12,1, 5, 9, 2, 8, 4, 6};

    QuickSort::sort(vec);
    std::vector<int> sorted = QuickSort::sort(vec);
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Sorted array: ";
    for (const auto& elem : sorted) {
        std::cout << elem << " ";
    }

    return 0;
}


