# Game of Life (C, ncurses)

A terminal-based implementation of Conway's Game of Life in C, using the [ncurses](https://invisible-island.net/ncurses/) library. The game board dynamically resizes to fit your terminal window.

## Features

- **Dynamic Board Size:** The game board automatically adjusts to your terminal size.
- **Draw Mode:** Create your own initial configuration.
  - Use **arrow keys** or **WASD** to move the cursor.
  - Press **Space** to toggle cell state (alive/dead).
  - Press **Enter** to start the simulation.
- **Random Mode:** Start with a randomly generated board.
- **Exit:** Quit the application from the main menu.

## Build & Run

### Prerequisites

- GCC or Clang
- [ncurses](https://invisible-island.net/ncurses/) library

### Build

```sh
mkdir -p build
cd build
cmake ..
make
```

### Run

```sh
./game_of_life
```

## Controls

- **Main Menu:**  
  - Use **arrow keys** or **WASD** to navigate.
  - **Enter** to select.

- **Draw Mode:**  
  - **Arrow keys** or **WASD**: Move cursor  
  - **Space**: Toggle cell state  
  - **Enter**: Start simulation  
  - **q**: Quit draw mode

- **Simulation:**  
  - **q**: Quit simulation


---

Enjoy experimenting with Conway's Game of Life in your terminal!