#ifndef ALIGNEDSTORAGE_LIBRARY_H
#define ALIGNEDSTORAGE_LIBRARY_H
#include "iostream"

// &obj % Align == 0, sizeof(obj) % Size == 0
template<std::size_t Align, std::size_t Size, typename T>
class AlignedStorage{
public:
    AlignedStorage(T value){
        T *newPtr = reinterpret_cast<T *>((reinterpret_cast<std::uintptr_t>(&storage) + Align - 1) & ~(Align - 1));
        *newPtr = T(std::forward<T>(value));
    }

    T* get() noexcept{
        return reinterpret_cast<T *>(&storage);
    }

    T operator*() const{
        return get();
    }

private:
    std::uint8_t storage[Size > sizeof(T) ? Size : sizeof(T)]{};
};

#endif //ALIGNEDSTORAGE_LIBRARY_H
