# Firmware Architecture

This repository provides a modular and scalable template for embedded firmware development.  
It is designed to be portable across different microcontrollers and toolchains, while remaining simple and easy to understand.

---

## Overview

The project is organized into independent layers with clear responsibilities:

- **core**: platform-independent logic
- **drivers**: low-level hardware interfaces
- **services**: higher-level features built on top of drivers
- **platform**: hardware-specific implementation (startup, linker, system)
- **app**: firmware entry point
- **tests**: host-based unit tests

This separation ensures good maintainability, testability, and portability.

---

## Directory Structure

```

├── cmake/                 # Toolchain and CMake utilities
├── firmware/
│   ├── app/               # Application entry point (main)
│   ├── core/              # Platform-independent logic
│   ├── drivers/           # Hardware drivers (GPIO, UART, etc.)
│   ├── services/          # High-level modules (business logic)
│   └── platform/          # MCU-specific implementation
├── tests/                 # Unit tests (host execution)
├── scripts/               # Build and flashing scripts
└── CMakeLists.txt         # Root build configuration

```

---

## Layer Description

### Core

The `core` module contains reusable, platform-independent components.

Examples:
- data structures (ring buffer)
- logging interfaces
- utilities

Constraints:
- must not depend on hardware
- must be fully testable on host

---

### Drivers

The `drivers` layer provides low-level access to hardware peripherals.

Examples:
- GPIO
- UART
- SPI, I2C (future extensions)

Responsibilities:
- abstract hardware registers
- expose simple and reusable APIs

---

### Services

The `services` layer implements higher-level features using drivers.

Examples:
- sensor management
- communication protocols
- application logic components

Dependencies:
- can depend on `core` and `drivers`
- must remain independent from `platform`

---

### Platform

The `platform` layer contains all hardware-specific code required to run the firmware.

Typical content:
- startup code
- linker scripts
- interrupt handling
- system initialization

This layer is the only one tightly coupled to a specific microcontroller.

---

### Application

The `app` module contains the firmware entry point.

Responsibilities:
- initialize the system
- configure services and drivers
- run the main loop

---

### Tests

The `tests` directory contains unit tests executed on the host machine.

Key points:
- only `core` and optionally `services` are tested
- no hardware or platform code is included
- uses standard C++ toolchain (no cross-compilation)

This enables fast and reliable testing without hardware.

---

## Build System

The project uses CMake with two main configurations:

### Firmware Build

Builds the embedded firmware using a cross-compilation toolchain.

```

cmake -B build -DCMAKE_TOOLCHAIN_FILE=cmake/arm-gcc-toolchain.cmake
cmake --build build

```

Output:
- `.elf`
- `.bin`
- `.hex`

---

### Host Tests Build

Builds and runs unit tests on the host.

```

cmake -B build_tests -DBUILD_TESTS=ON
cmake --build build_tests
ctest --test-dir build_tests

```

Only the following modules are compiled:
- core
- tests

---

## Design Principles

- Clear separation of concerns
- Minimal coupling between modules
- Platform-independent core logic
- Testability on host
- Scalable architecture for future features

---

## Notes

- The `platform` layer should be adapted for each target MCU
- The rest of the architecture remains unchanged across projects
- New features should be added to `services`, not directly in `app`

---