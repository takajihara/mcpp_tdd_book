# mcpp_tdd_book
Exercise for the book [Modern C++ Programming with Test-Driven Development](https://pragprog.com/titles/lotdd/modern-c-programming-with-test-driven-development/).

## Setup for Linux
### Install g++ and cmake
```
sudo apt-get install build-essential
sudo apt-get install cmake
```

### Download original example code
```
wget https://media.pragprog.com/titles/lotdd/code/lotdd-code.zip
unzip lotdd-code.zip
```

# Install libcurl
```
wget https://curl.se/download/curl-7.76.1.zip
unzip curl-7.76.1.zip 
cd curl-7.76.1/
mkdir mybuild
cd mybuild/
cmake ..
make
export CURL_HOME=$HOME/curl-7.76.1
```

# Install gtest
```
git clone https://github.com/google/googletest.git
cd googletest/
mkdir build
cd build/
cmake ..
make
export GMOCK_HOME=$HOME/mcpp_tdd_book/googletest/
```

# Update CMakeLists.txt for latest version of gtest
```
[old]
include_directories($ENV{GMOCK_HOME}/googlemock/include $ENV{GMOCK_HOME}/googletest/include)
link_directories($ENV{GMOCK_HOME}/mybuild $ENV{GMOCK_HOME}/gtest/mybuild)
...
target_link_libraries(test pthread)
target_link_libraries(test gmock)
target_link_libraries(test gtest)
```

```
[new]
include_directories($ENV{GMOCK_HOME}/include $ENV{GMOCK_HOME}/gtest/include)
link_directories($ENV{GMOCK_HOME}/mybuild/lib)
...
target_link_libraries(test gmock)
target_link_libraries(test gtest)
target_link_libraries(test pthread)
```
[] write a script to update as below.