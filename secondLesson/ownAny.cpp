#include <gtest/gtest.h>

#include <any>
#include <fmt/core.h>

namespace detail {
    // Here is a possible implementation of std::any
    class my_any {
    public:
        template<typename T>
        explicit my_any(T value) : obj_{std::make_unique<T>(std::move(value))} {}

        decltype(auto) get() { return obj_->get(); }

        // HW: Add move/copy-assignment operators
        // HW: Add copy/move-ctor

        // copy-constructor
        my_any(const my_any &other) : obj_( std::unique_ptr<base>{other.obj_->clone()} ) {}
        // move-constructor
        my_any(my_any&& other)  noexcept : obj_( std::move(other.obj_) ){}

        // copy-assignment
        my_any& operator=(const my_any& other) {
            if (this != &other) {
                obj_.reset(); // nullptr
                if (other.obj_) {
                    obj_ = std::unique_ptr<base>{other.obj_->clone()};
                }
            }
            return *this;
        }
        // move-assignment
        my_any& operator=(my_any&& other) noexcept {
            if (typeid((*obj_).get()) == typeid((*other.obj_).get())) {
                obj_ = std::move(other.obj_);
            }
            return *this;
        }

        template<typename T>
        T& get() {
            if (!obj_) {
                throw std::bad_cast{};
            }
            if (typeid(T) != obj_->type()) {
                throw std::bad_cast{};
            }
            auto ptr = static_cast<handler<T>*>(obj_.get())->get();
            return *static_cast<T*>(ptr);
        }

    private:
        struct base {
            virtual void *get() = 0;
            virtual const std::type_info& type() const = 0;
            virtual base *clone() = 0;
            virtual ~base() = 0;
            };

        template<typename T>
        struct handler : base {
            explicit handler(T value) : var{std::move(value)} {}

            const std::type_info& type() const override { return typeid(T); }
            void *get() override { return &var; }

            handler(const handler &other) : var(other.var){}

            handler* clone() const override { return new handler(*this); }
            T var;
        };

        std::unique_ptr<base> obj_;
    };

    template<typename T>
    T &any_cast(my_any &v) {
        // HW: Implement cast function to get the value of type T from my_any
    }

    // HW: Write tests for my_any class

}// namespace detail

TEST(Any, ConstructionAndAccess) {
    std::any a = 10;

    ASSERT_NO_THROW(std::any_cast<int>(a));
    ASSERT_THROW(std::any_cast<std::string>(a), std::bad_any_cast);

    ASSERT_EQ(std::any_cast<int>(a), 10);

    auto golden = std::string{"Here is a string in std::any"};
    a = golden;

    ASSERT_THROW(std::any_cast<int>(a), std::bad_any_cast);
    ASSERT_NO_THROW(std::any_cast<std::string>(a));

    ASSERT_EQ(std::any_cast<std::string>(a), golden);
}

namespace {
    auto process_any(const std::any &v) {
        auto dump_any_content = [](const auto &v) {
            fmt::print("std::any handle type {} with value {}\n",
                       typeid(decltype(v)).name(), v);
        };
        if (std::any_cast<int>(&v) != nullptr) {
            dump_any_content(std::any_cast<int>(v));
        } else if (std::any_cast<double>(&v) != nullptr) {
            dump_any_content(std::any_cast<double>(v));
        } else if (std::any_cast<std::string>(&v) != nullptr) {
            dump_any_content(std::any_cast<std::string>(v));
        } else {
            fmt::print("Unknown any.\n");
        }
    }
}// namespace

// HW: Suggest the output from this test.
TEST(Any, InvokeFunction) {
    std::any v = 10;
    ::process_any(v);

    v = 3.14;
    ::process_any(v);

    v = "Some string value (or not)";
    ::process_any(v);

    v = std::string{"Some string value (or not)"};
    ::process_any(v);
}
