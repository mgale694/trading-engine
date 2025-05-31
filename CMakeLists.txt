cmake_minimum_required(VERSION 3.10) # Ensure a modern CMake version

project(TradingEngine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17) # Use C++17
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
add_executable(trading_engine 
    main.cpp
    src/orderBook.cpp
    src/order.cpp
    src/uuid.cpp
    src/trader.cpp
)

# Specify additional libraries or dependencies
target_link_libraries(trading_engine PRIVATE pthread)

# Add include directory for headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Install target (optional)
# install(TARGETS trading_engine DESTINATION bin)