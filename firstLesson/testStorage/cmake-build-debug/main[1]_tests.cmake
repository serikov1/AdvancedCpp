add_test([=[AlignedStorageTest.Easy]=]  [==[/home/vasilli/CLionProjects/AdvancedC++/firstLesson/testStorage/cmake-build-debug/main]==] [==[--gtest_filter=AlignedStorageTest.Easy]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[AlignedStorageTest.Easy]=]  PROPERTIES WORKING_DIRECTORY [==[/home/vasilli/CLionProjects/AdvancedC++/firstLesson/testStorage/cmake-build-debug]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[AlignedStorageTest.Medium]=]  [==[/home/vasilli/CLionProjects/AdvancedC++/firstLesson/testStorage/cmake-build-debug/main]==] [==[--gtest_filter=AlignedStorageTest.Medium]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[AlignedStorageTest.Medium]=]  PROPERTIES WORKING_DIRECTORY [==[/home/vasilli/CLionProjects/AdvancedC++/firstLesson/testStorage/cmake-build-debug]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[AlignedStorageTest.Hard]=]  [==[/home/vasilli/CLionProjects/AdvancedC++/firstLesson/testStorage/cmake-build-debug/main]==] [==[--gtest_filter=AlignedStorageTest.Hard]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[AlignedStorageTest.Hard]=]  PROPERTIES WORKING_DIRECTORY [==[/home/vasilli/CLionProjects/AdvancedC++/firstLesson/testStorage/cmake-build-debug]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  main_TESTS AlignedStorageTest.Easy AlignedStorageTest.Medium AlignedStorageTest.Hard)