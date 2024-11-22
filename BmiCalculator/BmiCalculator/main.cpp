#include <iostream>
#include <string_view>
#include <iomanip>

namespace constants {
    constexpr int imperialConversionFactor { 703 };
}

int promptInput(std::string_view type) {
    std::cout << "Enter your " << type << ": ";
    int x{};
    std::cin >> x;
    return x;
}

double constexpr calculateBmi(int height, int weight) {
    const int convertedWeight = weight * constants::imperialConversionFactor;
    return static_cast<double>(convertedWeight / height) / height;
}

void printOutput(double output) {
    std::cout << "Your bmi is " << std::setprecision(4) << output << "\n";
}

int main() {
    const int height { promptInput("height (inches)") };
    const int weight { promptInput("weight (lbs)") };
    
    printOutput(calculateBmi(height, weight));
    
    return 0;
}
