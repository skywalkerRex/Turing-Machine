# Turing-Machine
This project is to replicate the Turing machine mentioned in book "The Emperor's New Mind"

## Build Instructions

### Prerequisites
- Ubuntu 24.04 (or compatible Linux distribution)
- CMake 3.22 or higher
- C++17 compatible compiler (g++ 13.3.0 or compatible)

### Building the Project

```bash
# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
make

# Run the executable
./bin/turing_machine
```

### Project Structure
```
.
├── CMakeLists.txt      # CMake configuration file
├── src/
│   └── main.cpp        # Main application source
└── build/              # Build directory (generated)
    └── bin/            # Executable output
```
