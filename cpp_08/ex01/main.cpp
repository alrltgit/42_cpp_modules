#include "Span.h"

int main() {
    try {
        Span sp = Span(5);
        std::vector<int> src;

        src.push_back(6);
        src.push_back(3);
        src.push_back(17);
        src.push_back(9);
        src.push_back(11);
        // src.push_back(0);

        sp.addNumbers(src);
        // sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
