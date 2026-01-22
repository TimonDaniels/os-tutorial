int my_func(int* arg) {
    return *arg + 257;
}

void caller() {
    int input = 0xdede;
    my_func(&input);
}