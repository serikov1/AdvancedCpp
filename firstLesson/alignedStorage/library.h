#ifndef ALIGNEDSTORAGE_LIBRARY_H
#define ALIGNEDSTORAGE_LIBRARY_H

#include <memory>
#include "iostream"

// &obj % Align == 0, sizeof(obj) % Size == 0
template<std::size_t Align, std::size_t Size, typename T>
class AlignedStorage{
public:
    template<typename... Args>
    constexpr AlignedStorage(Args ...args) {
        newPtr = reinterpret_cast<T *> ((reinterpret_cast<std::uintptr_t>(&storage) + Align - 1) & (~(Align - 1)));
        *newPtr = T(std::forward<Args>(args)...);
    }

    constexpr const T &operator*() const {
        return *newPtr;
    }
    constexpr T &operator*() {
        return *newPtr;
    }

private:
    std::uint8_t storage[Size + Align > sizeof (T) ? Size + Align : sizeof(T)]{};
    T *newPtr = nullptr;
};

#endif //ALIGNEDSTORAGE_LIBRARY_H
