template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
    std::cout << "Default constructor is called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) {
    std::cout << "Copy constructor is called" << std::endl;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other) {
    std::cout << "Copy assignment operator is called" << std::endl;

    if (this != &other) {
        std::stack<T>::operator=(other);
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {
    std::cout << "Destructor is called" << std::endl;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}
