cmake_minimum_required(VERSION 3.12)

project(TradingEngine)

# Add source files
add_executable(trading_engine src/main.cpp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Specify additional libraries or dependencies
target_link_libraries(trading_engine PRIVATE pthread)

# Install target (optional)
# install(TARGETS trading_engine DESTINATION bin)