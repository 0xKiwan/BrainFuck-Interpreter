#ifndef _INTERPRETER_HPP
#define _INTERPRETER_HPP

#include <vector>
#include "token.hpp"

/**
 * Built from https://github.com/brain-lang/brainfuck/blob/master/brainfuck.md
 */

class BFInterpreter
{
public: // Public members for this class.

	std::vector<BFToken>	tokens;					// Stores tokens for the interpreter to execute.
	char					*tape;					// Memory for the BrainFuck interpreter.
	int32_t					head_idx;				// ptr to the current cell we have selected.
	int						pc;						// Program Counter.
	BFToken					*cur_token;				// The current token being executed.

public: // Public methods for this class.

	/**
	 * Constructor for this class. Takes a vector of tokens.
	 */
	BFInterpreter(std::vector<BFToken> tokens);

	/**
	 * Will interpret and run the tokens
	 */
	void Run();
};

#endif // _INTERPRETER_HPP