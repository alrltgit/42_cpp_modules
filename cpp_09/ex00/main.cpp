#include "BitcoinExchange.hpp"

int main(int ac, char **argv) {
    if (ac != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    try {
        BitcoinExchange btc = BitcoinExchange();
        btc.storeRatesInMap();
        btc.readInput(argv);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
