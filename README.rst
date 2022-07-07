"BrainFuck" Interpreter.
=======
A very simple brainfuck interpreter. 
Comes with a lexer, for tokenizing the source,
a linter which only handles unidentified tokens, and mismatched loop brackets.
Still needs a LOT of work.

Install
-------
Download the project, and build it as x64.

Usage
-------
You can either use the built-in interpreter, or feed it a file.

To use the interpreter, just run BrainFuckInterpreter.exe, and begin typing your BrainFuck code into the console.

To feed in a file, the syntax for the terminal is like this:

.. code-block:: fish

    ./BrainFuckInterpreter.exe "filename.bf"

Ensure your filename ends with the .bf extension or it will not be accepted by the interpreter.
Code must be valid brainfuck, or the interpreter will error and exit. No comments, unclosed loops, or random characters outside of the accepted brainfuck tokens are accepted.
