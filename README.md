# OS

A lightweight collection of tools for systems programming and OS-level development. This repository includes:

- 🔧 **os-gdb**: Pre-configured GDB scripts for debugging kernel-level code.
- ⚡ **os-turbo**: A C-based benchmarking suite to test CPU, I/O, and disk performance.

---

## 🚀 Getting Started

### Prerequisites

Ensure you have the following installed:

- GCC (or any C compiler)
- GNU Make
- GDB (for `os-gdb`)

### Installation

```bash
git clone https://github.com/noturCR/os.git
cd os
```

To build either tool:

```bash
cd os-gdb     # or cd os-turbo
make
```

---

## 🛠 Usage

### Debugging with os-gdb

Start GDB with predefined scripts:

```bash
gdb -x init.gdb <your_kernel_binary>
```

This will load breakpoints and symbol mappings automatically.

### Benchmarking with os-turbo

Run any of the compiled tools directly:

```bash
./cpu      # Test CPU performance
./disk     # Benchmark disk I/O
./io       # Measure general I/O load
```

---

## 🤝 Contributing

Contributions are welcome!  
Please fork the repository and submit a pull request. For significant changes, open an issue first to discuss your proposal.

---

For any queries or suggestions, feel free to open an issue on the [GitHub Repo](https://github.com/noturCR/os).
