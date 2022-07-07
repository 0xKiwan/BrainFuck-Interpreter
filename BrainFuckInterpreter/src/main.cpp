// BrainFuckInterpreter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "../inc/lexer.hpp"
#include "../inc/interpreter.hpp"
#include "../inc/linter.hpp"

/**
 * Lexes, lints and interprets code.
 */
void HandleBFCode(std::string data)
{
    // Create a lexer struct.
    BFLexer lexer((char*)data.c_str());

    // Will store the tokens the lexer pulled.
    std::vector<BFToken> tokens;

    // Construct TOKEN_START and append to the tokens
    tokens.push_back(BFToken(TOKEN_START, 0, 0, 0));

    // Loop until we reach TOKEN_EOF.
    for (;;)
    {
        // Scan the next token
        BFToken token = lexer.ScanToken();

        // Append the token to the vector
        tokens.push_back(token);

        // Check if we have reached EOF
        if (token.token_type == TOKEN_END) break;
    }

    // Initialize the linter and run it.
    BFLinter(tokens).Run();

    // Initialize our interpreter object and run it.
    BFInterpreter(tokens).Run();
}

int main(int argc, char *argv[])
{
    // Self promo yk ;)
    printf("0xKiwan's BrainFuck Interpreter\n");

    // Will store the data we want to parse
    std::string data;

    // Check if we are interpreting a brainfuck file
    if (argc > 1)
    {
        // Get the file name we want to interpret
        std::string in_file = std::string(argv[1]);

        // Check the file is a valid '.bf' file.
        if (!(in_file.substr(in_file.size() - 3) == ".bf"))
        {
            // Log the error
            printf("[BFI] [Error]: Please input a valid .bf brainfuck file\n");

            // Exit
            exit(1);
        }

        // Open a stream to the file
        std::ifstream fs(in_file);

        // Read file data into a string
        std::string data(
            (std::istreambuf_iterator<char>(fs)),
            std::istreambuf_iterator<char>()
        );

        // Call HandleBFCode();
        HandleBFCode(data);
    }
    else
    {
        // Will store the current line buffer
        char line_buffer[1024];

        // Loop forever
        for (;;)
        {
            // Accept BrainFuck input. Change this to handle a .bf source file later on.
            printf("> ");

            // Capture the user's input
            if (fgets(line_buffer, sizeof(line_buffer), stdin) == NULL) continue;

            // Handle the input
            HandleBFCode(std::string(line_buffer));
        }
    }
}