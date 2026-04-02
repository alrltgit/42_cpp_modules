#include "whatever.h"
#include <string>
#include <iostream>

int main( void ) {
    std::cout << "======= INT =======" << std::endl;
    int a = 2;
    int b = 3;
    swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::cout << "======= STRING =======" << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    std::cout << "======= DOUBLE =======" << std::endl;
    double h = 42.42;
    double i = 24.24;
    swap( h, i );
    std::cout << "h = " << h << ", i = " << i << std::endl;
    std::cout << "min( h, i ) = " << ::min( h, i ) << std::endl;
    std::cout << "max( h, i ) = " << ::max( h, i ) << std::endl;

    std::cout << "======= CHAR =======" << std::endl;
    char f = '.';
    char g = ',';
    swap( f, g );
    std::cout << "f = " << f << " | g = " << g << std::endl;
    std::cout << "min( f, g ) = " << ::min( f, g ) << std::endl;
    std::cout << "max( f, g ) = " << ::max( f, g ) << std::endl;
    
    return 0;
}
