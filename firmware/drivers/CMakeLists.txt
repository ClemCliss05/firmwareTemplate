# ------------------------------------------------------------------------------
# Hardware drivers
# Direct register access (no HAL)
# ------------------------------------------------------------------------------

add_library(drivers STATIC)

target_sources(drivers PRIVATE

    gpio/gpio.cpp

    uart/uart.cpp
    uart/uart_logger_backend.cpp
)

target_include_directories(drivers PUBLIC

    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(drivers PUBLIC

    core
    platform_mcu_name
)
