# BrainFuck Interpreter

Welcome to the **BrainFuck Interpreter**! This repository hosts a simple BrainFuck interpreter created by [0xKiwan](https://github.com/0xKiwan). The interpreter is currently in an early stage of development and has room for many improvements.

## Features

- **REPL (Read-Eval-Print Loop)**: Allows you to write and execute BrainFuck code interactively.
- **File Execution**: Execute BrainFuck code from files with the `.bf` extension.

## Usage

### Running in REPL Mode

To start the interpreter in REPL mode, simply run the executable without any arguments:

```bash
./BrainFuckInterpreter.exe
```

You can then start typing BrainFuck commands directly into the console. The interpreter will execute the commands and print the output.

### Running a BrainFuck File

To execute a BrainFuck file, provide the filename as an argument to the executable:

```bash
./BrainFuckInterpreter.exe "filename.bf"
```

Make sure that the file has a `.bf` extension and contains valid BrainFuck code.

## BrainFuck Language Overview

BrainFuck is an esoteric programming language with a minimalist design. It consists of eight commands:

- `>`: Increment the data pointer.
- `<`: Decrement the data pointer.
- `+`: Increment the byte at the data pointer.
- `-`: Decrement the byte at the data pointer.
- `.`: Output the byte at the data pointer.
- `,`: Accept one byte of input, storing its value in the byte at the data pointer.
- `[`: Jump forward to the command after the corresponding `]` if the byte at the data pointer is zero.
- `]`: Jump back to the command after the corresponding `[` if the byte at the data pointer is nonzero.

## Limitations

- **No Comments**: The interpreter does not support comments in BrainFuck code.
- **Unclosed Loops**: Ensure all loops are properly closed with matching `[` and `]`.
- **Valid Tokens Only**: Any characters outside of the accepted BrainFuck tokens will result in an error.

## Contributing

Contributions are welcome! Feel free to fork the repository and submit pull requests. Here are some areas that need improvement:

- Adding support for comments in BrainFuck code.
- Enhancing error handling and reporting.
- Optimizing the interpreter for better performance.
- Extending the REPL with additional features.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

Special thanks to the BrainFuck community for the inspiration and resources.

---

Happy coding with BrainFuck!

---

**Repository**: [0xKiwan/BrainFuck-Interpreter](https://github.com/0xKiwan/BrainFuck-Interpreter)
