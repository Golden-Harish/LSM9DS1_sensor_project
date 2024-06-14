cmake_minimum_required(VERSION 3.13.1)

# Define the target board
set(BOARD nucleo_l496zg)

# Include Zephyr's build system
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(lsm9ds1_sensor_project)

# Add your source files here
target_sources(app PRIVATE src/main.c)

