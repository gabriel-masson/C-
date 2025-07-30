#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <string>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    std::for_each(v.begin(), v.end(), [](int x) {
        std::cout << x * x << " ";
    });
    std::cout << " " << std::endl;
    // Saída: 1 4 9 16 25

    std::vector<std::string> keys = {"Gabriel", "Dostoivski", "Kafka", "Camus"};
    std::vector<float> values = {5000.0, 7200.0, 1900.0,4400.0};
    float juros = 10;

    std::map<std::string, float> myMap;

    // Inserting elements into the map
    for (size_t i = 0; i < keys.size(); ++i) {
        myMap[keys[i]] = values[i];
    }

    // auto calculateInterest = [juros](float value) {
    //     return value * (juros / 100);
    // };
    // for (auto const& [key, value] : myMap) {
    //     myMap[key] += calculateInterest(value);
    //     std::cout << key << ": " << myMap[key] << std::endl;
    // }

    auto calculo_juros = [&](std::map<std::string, float>* p) -> void {
        for (auto& [key, value] : *p) {
            value += value * (juros / 100);
            (*p)[key] = value; 
            
            std::cout << key << ": " << (*p)[key]  << std::endl;
    }
    };
    calculo_juros(&myMap);
    // showing the final map
    std::cout << "Final map contents:" << std::endl;
    for (const auto& [key, value] : myMap) {
        std::cout << key << ": " << value << std::endl;
    }


}
