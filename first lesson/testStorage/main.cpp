#include <iostream>
#include "../alignedStorage/library.h"
#include "fmt/core.h"

int main() {
    AlignedStorage<4, 8, double> ex(12.3);
    std::cout<<reinterpret_cast<uint64_t>(&ex) % 4<<std::endl;
    std::cout<<sizeof(ex)<<std::endl;
    std::cout<< *ex.get()<<std::endl;
}