cc_library (
    name = 'test',
    hdrs = ['classA.h', 'classB.h'],
    srcs = ['classA.cpp', 'classB.cpp'],
    extra_cppflags = [
        '-std=c++17'
    ],
)

cc_binary (
    name = 'main',
    srcs = ['main.cpp'],
    extra_cppflags = [
        '-std=c++17'
    ],
    deps = [':test'],
)
