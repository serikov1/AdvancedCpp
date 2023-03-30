### This is the repo with "Implementation of a memory device"

I added some [methods](https://github.com/serikov1/AdvancedCpp/blob/main/secondLesson/src/buffer.h) in `class Iterator` to
complete Random Access Iterator  
It was:  
`friend difference_type operator-(const Iterator& lhs, const Iterator& rhs);` - return offset(`size_t`) between lhs and rhs   
`reference operator[](difference_type n) const;` - equivalent to *(it + n)  
`Iterator &operator++();`- prefix operator  
`Iterator operator++ (int);` - postfix operator  
`Iterator &operator+=(difference_type n);`  
`Iterator operator+(difference_type n);`  
Also, the same operators with '-' instead of '+'
Moreover, it needed all bool operators which I too added.

So, I wrote simple [tests](https://github.com/serikov1/AdvancedCpp/blob/main/secondLesson/tests/devmem.cpp) which
checked correctness these operators.
But I don't know do I need write other test for checking that Iterator perfect for using?
