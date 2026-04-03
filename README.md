# Embedded Firmware Template

A clean, modular, and scalable template for embedded firmware development.

This project is designed to provide a solid foundation for building reliable, testable, and maintainable embedded systems across different microcontrollers.

---

## Features

- Modular architecture (core / drivers / services / platform)
- Cross-compilation support (ARM GCC toolchain)
- Host-based unit testing
- Lightweight and hardware-agnostic design
- Easy to extend and reuse across projects

---

## Project Structure

```

firmware/
core/        # Platform-independent logic
drivers/     # Hardware drivers
services/    # High-level modules
platform/    # MCU-specific code
app/         # Entry point

tests/         # Unit tests (host)
cmake/         # Toolchain configuration
scripts/       # Build and flash scripts

````

---

## Build Firmware

```bash
cmake -B build
cmake --build build
````

Outputs:

* `firmware.elf`
* `firmware.bin`
* `firmware.hex`

---

## Run Tests

```bash
cmake -B build_tests -DBUILD_TESTS=ON
cmake --build build_tests
ctest --test-dir build_tests
```

---

## Goals

* Keep core logic independent from hardware
* Enable fast testing without target hardware
* Provide a reusable template for embedded projects

---

## License

MIT
