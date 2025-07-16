# Collision-Detection
Detects when two objects collide using SFML.
## How to Run

### Prerequisites

- **SFML** (tested with 3.0.0)
- **g++ compiler** (MSYS2, MinGW, or similar)
- **Visual Studio Code** with the **C/C++ extension**

### VS Code Setup

1. Clone or download this repository.
2. Place all necessary `.dll` files for SFML in the same directory as your `.exe`.
3. Open the folder in VS Code.
4. Press `Ctrl + Shift + B` to build using the configured `tasks.json`.
5. Run the generated `.exe` to play the simulation.

---

## Controls

| Player 1 (Green Circle) | Player 2 (Blue Circle) |
|-------------------------|------------------------|
| W - Move Up             | ↑ - Move Up            |
| A - Move Left           | ← - Move Left          |
| S - Move Down           | ↓ - Move Down          |
| D - Move Right          | → - Move Right         |

- When the circles collide, they both turn **red**.

---

## Tools Used

- **C++17**
- **SFML** (`Graphics`, `Window`, `System`)
- **cmath**, **iostream**, **optional**
- **VS Code**, **MSYS2 g++**
- **tasks.json** and **c_cpp_properties.json** for VS Code integration

---

## Notes

- Make sure all SFML `.dll` files (like `sfml-graphics-2.dll`, `sfml-window-2.dll`, `sfml-system-2.dll`) are present in the same directory as the executable or added to your system path.
- The include and lib paths in `tasks.json` and `c_cpp_properties.json` must match your SFML installation directory.

