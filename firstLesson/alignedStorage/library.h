#ifndef ALIGNEDSTORAGE_LIBRARY_H
#define ALIGNEDSTORAGE_LIBRARY_H

#include <memory>
#include "iostream"

//&obj % Align == 0, sizeof(obj) % Size == 0
template<std::uint64_t Align, std::uint64_t Size, typename T>
class AlignedStorage{
public:
    template<typename... Args>
    constexpr AlignedStorage(Args ...args) {
        newPtr = reinterpret_cast<T *> ((reinterpret_cast<std::uintptr_t>(&storage) + Align - 1) & (~(Align - 1)));
        new (newPtr) T(std::forward<Args>(args)...);
    }

    constexpr const T &operator*() const {
        return *newPtr;
    }
    constexpr T &operator*() {
        return *newPtr;
    }
    ~AlignedStorage() {
        static_cast<T *>(newPtr)->~T();
    }

private:
    std::uint8_t storage[Size + Align]{};
    T *newPtr = nullptr;
};

// This storage was proposed me by ChatGPT

//template<std::size_t Align, std::size_t Size, typename T>
//class AlignedStorage
//{
//private:
//    alignas(Align) std::uint8_t data[Size];
//
//public:
//    template<typename... Args>
//   AlignedStorage(Args... args)
//    {
//        new (data) T(std::forward<Args>(args)...);
//    }
//
//    ~AlignedStorage()
//    {
//        reinterpret_cast<T*>(data)->~T();
//    }
//
//    T& operator*()
//    {
//        return *reinterpret_cast<T*>(data);
//    }
//
//    const T& operator*() const
//    {
//        return *reinterpret_cast<const T*>(data);
//    }
//};

// This Storage was in class

//template<typename T, uint64_t Align, uint64_t Size>
//constexpr auto storage_size() {
//    auto estimated_size = sizeof(T) + Align;
//    return (estimated_size + Size - 1) & (~(Size - 1));
//}
//
//template<uint64_t Align, uint64_t Size, typename T>
//class AlignedStorage {
//public:
//    template<typename... Args>
//    constexpr explicit AlignedStorage(Args &&...args) {
//        uint64_t space = sizeof(storage_);
//        base_ = storage_;
//        std::align(Align, sizeof(T), base_, space);
//
//        new (base_) T(std::forward<Args>(args)...);
//    }
//
//    constexpr T &operator*() { return *static_cast<T *>(base_); }
//    constexpr const T &operator*() const {
//        return *static_cast<const T *>(base_);
//    }
//
//    ~AlignedStorage() { static_cast<T *>(base_)->~T(); }
//
//private:
//    uint8_t storage_[storage_size<T, Align, Size>()] = {};
//    void *base_ = nullptr;
//};

#endif //ALIGNEDSTORAGE_LIBRARY_H
