# 🖥️ Operating System Simulation


[![Build Status](https://img.shields.io/badge/build-passing-brightgreen)](https://github.com/Nidhi5896/osimulation)
![Language](https://img.shields.io/badge/language-C-blue.svg)

A comprehensive C-based simulation of operating system components including CPU scheduling algorithms and memory allocation strategies.

## 📚 Table of Contents
- [Features](#-features)
- [Prerequisites](#-prerequisites)
- [Installation](#-installation)
- [Usage](#-usage)
- [Project Structure](#-project-structure)
- [Cleaning](#-cleaning)
- [Contributing](#-contributing)
- [License](#-license)
- [Authors](#-authors)
- [Acknowledgments](#-acknowledgments)

## 🌟 Features

### CPU Scheduling Algorithms
- ⏰ First Come First Serve (FCFS)
- 📉 Shortest Job First (SJF)
- 🔄 Round Robin (RR)

### Memory Allocation Algorithms
- 🔍 First Fit
- ✅ Best Fit
- ❌ Worst Fit

## 📦 Prerequisites

- GCC compiler (MinGW for Windows)
- Make utility
- Git (for version control)

```bash
# Ubuntu/Debian
sudo apt-get install build-essential git
```

## 🛠️ Installation

1. Clone the repository:
```bash
git clone https://github.com/Nidhi5896/osimulation.git
cd osimulation
```

2. Compile the project:
```bash
make
```

## 🚀 Usage

Run the compiled program:
```bash
./osim
```

### CPU Scheduling Simulation
1. Choose option 1 for CPU Scheduling
2. Enter number of processes
3. For each process, provide:
   - Arrival time
   - Burst time
4. Select scheduling algorithm:
   - `1` FCFS
   - `2` SJF
   - `3` Round Robin
5. For Round Robin, enter time quantum

### Memory Allocation Simulation
1. Choose option 2 for Memory Allocation
2. Enter number of memory blocks
3. For each block, specify its size
4. Enter process ID and required memory size
5. Select allocation algorithm:
   - `1` First Fit
   - `2` Best Fit
   - `3` Worst Fit

## 📂 Project Structure

```
osimulation/
├── 📄 main.c          # Main program logic
├── 📄 scheduler.c     # CPU scheduling implementations
├── 📄 memory.c        # Memory allocation implementations
├── 📄 process.h       # Process structure definition
├── 📄 scheduler.h     # Scheduler headers
├── 📄 memory.h        # Memory allocation headers
├── 📄 Makefile        # Build configuration
└── 📄 README.md       # Project documentation
```

## 🧹 Cleaning

Remove compiled files:
```bash
make clean
```

## 👥 Authors

- **Nidhi KUmari** - [@Nidhi5896](https://github.com/Nidhi5896)
