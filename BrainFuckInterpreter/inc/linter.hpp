#ifndef _BF_LINTER_HPP
#define _BF_LINTER_HPP

#include <vector>

#include "../inc/token.hpp"

struct BFLinterError
{
	; // Store details about the error here.
};

class BFLinter
{
public: // Public members for this class.

	std::vector<BFToken> tokens;

public: // Public methods for this class.

	/**
	 * Constructor for this class. Stores the list of tokens.
	 */
	BFLinter(std::vector<BFToken> tokens);

	/**
	 * Runs various checks on the array of tokens
	 * and returns any errors it finds.
	 */
	BFLinterError Run();
};

#endif // _BF_LINTER_HPP