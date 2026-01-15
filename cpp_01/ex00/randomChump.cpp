#include "Zombie.hpp"

// As shown above, the stack segment is near the top of memory 
// with high address. Every time a function is called, 
//the machine allocates some stack memory for it. 
//When a new local variables is declared, more stack memory is allocated 
//for that function to store the variable.
// After the function returns, the stack memory of this function is deallocated,
// which means all local variables become invalid. 
// The allocation and deallocation for stack memory is automatically done. 
// The variables allocated on the stack are called stack variables, 
// or automatic variables.

void randomChump(std::string name) {
    Zombie FooStack = Zombie(name);
    FooStack.announce();
}
