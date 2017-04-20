# containers
Build status:
* master: [![Build Status](https://travis-ci.org/brandl-muc/containers.svg?branch=master)](https://travis-ci.org/brandl-muc/containers)
* develop: [![Build Status](https://travis-ci.org/brandl-muc/containers.svg?branch=develop)](https://travis-ci.org/brandl-muc/containers)
Code coverage:
* master: [![codecov](https://codecov.io/gh/brandl-muc/containers/branch/master/graph/badge.svg)](https://codecov.io/gh/brandl-muc/containers)
* develop: [![codecov](https://codecov.io/gh/brandl-muc/containers/branch/develop/graph/badge.svg)](https://codecov.io/gh/brandl-muc/containers)

## Synopsis

This is intended as a collection of container classes written in C++14.

Existing containers:
* unstable_vector

Planned containers:
* stack_vector

## Code Example

Show what the library does as concisely as possible, developers should be able to figure out **how** your project solves their problem by looking at the code example. Make sure the API you are showing off is obvious, and that your code is short and concise.

## Motivation

Reason for their creation is mainly for my entertainment, testing stuff and practicing.

## Installation

src/ contains the containers which are header only. Simply copy desired container headers into your project or to a designated folder and include them.

## API Reference

TODO
Depending on the size of the project, if it is small and simple enough the reference docs can be added to the README. For medium size to larger projects it is important to at least provide a link to where the API reference docs live.

## Tests

A GTest unit test exists in the directory test/, to build and run it issue the following commands in that directory:

    cmake CMakeLists.txt
    make
    ./utest

## Contributors

No contributors or users yet, so no issue tracker.

## License

GNU GPL v3
