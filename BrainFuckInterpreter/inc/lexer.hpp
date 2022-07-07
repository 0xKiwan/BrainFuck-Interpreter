#ifndef _BF_LEXER_HPP
#define _BF_LEXER_HPP

#include <cstdint>
#include <map>
#include "../inc/token.hpp"


class BFLexer
{
public: // Public members for this class

	char*					src;
	char*					start;
	uint32_t				line_number;
	uint32_t				column_number;
	std::map<char, int32_t> token_map;


public: // Public methods for this class.

	/**
	 * Constructor for the lexer class.
	 */
	BFLexer(char* source);

	/**
	 * Allows peeking at the current lexer character without consuming.
	 * Returns the character at the current src pointer.
	 */
	char Peek();

	/**
	 * Allows peeking at any given offset of the src file without consuming.
	 * Returns the character at src pointer + offset
	 */
	char PeekOffset(int32_t offset);

	/**
	 * Gets the current lexer character, and consumes it, moving on to the next.
	 * Returns the current character at src pointer.
	 */
	char Consume();

	/**
	 * Checks if the lexer has reached EOF
	 * Returns true if yes, false if no.
	 */
	bool IsEOF();

	/**
	 * Skips any whitespace in the file and moves to the next token
	 */
	void HandleWhitespace();

	/**
	 * Scans for the next token and returns it.
	 */
	BFToken ScanToken();

};

#endif // _BF_LEXER_HPP