


#include "../inc/lexer.hpp"

// Implementation for BFLexer::BFLexer()
BFLexer::BFLexer(char* source)
{
	this->line_number	= 0;
	this->column_number = 0;
	this->src			= source;
	this->start			= NULL;

    // Initialize the token map
    // I dont like this. find a better solution.
    this->token_map = {
        {'+',   TOKEN_INCREMENT},
        {'-',   TOKEN_DECREMENT},
        {'<',   TOKEN_SHIFT_LEFT},
        {'>',   TOKEN_SHIFT_RIGHT},
        {'.',   TOKEN_OUTPUT},
        {',',   TOKEN_INPUT},
        {'[',   TOKEN_OPEN_LOOP},
        {']',   TOKEN_CLOSE_LOOP}
    };
}

// Implementation for BFLexer::Peek()
char BFLexer::Peek()
{
	// Return the character at the current src ptr.
	return *this->src;
}

// Implementation for BFLexer::PeekOffset()
char BFLexer::PeekOffset(int32_t offset)
{
	// Return the character at the given offset from the src ptr.
	return this->src[offset];
}

// Implementation for BFLexer::Consume()
char BFLexer::Consume()
{
	// Get the current character
	char ch = this->Peek();

	// Increment source ptr
	this->src++;

	// Move to the next character.
	this->column_number++;

	// Return the char we consumed.
	return ch;
}

// Implementation for BFLexer::IsEOF()
bool BFLexer::IsEOF()
{
	// Peek at the current char and check if it's EOF char.
	return this->Peek() == '\x00';
}

// Implementation for BFLexer::HandleWhitespace()
void BFLexer::HandleWhitespace()
{
    // Loop until we reach EOF.
    while (!this->IsEOF())
    {
        // Peek at the next character in the source.
        char ch = this->Peek();

        // Handle different characters
        switch (ch)
        {
        case '\r':      // Return carriage.
        case '\t':      // Tab
        case ' ':       // Space
            this->column_number++;
            break;
        case '\n':      // Newline
            this->line_number++;
            this->column_number = 0;
            break;
        default:
            return;
        }

        // Increment src ptr
        this->src++;
    }
}

// Implementation for BFLexer::ScanToken()
BFToken BFLexer::ScanToken()
{
    // Handle any whitespace first.
    this->HandleWhitespace();

    // Construct the BFToken object
    BFToken token(TOKEN_UNKNOWN, this->line_number, this->column_number, this->Peek());

    // Check if we are at EOF
    if (this->IsEOF())
    {
        // Change token type to EOF
        token.token_type = TOKEN_END;

        // Consume the current token
        this->Consume();

        // Return EOF token
        return token;
    }

    // Get the current char
    char ch = this->Peek();

    // Check the token is contained within our map
    if (this->token_map.count(ch))
    {

        // Set the token type from the map we created earlier.
        token.token_type = this->token_map[ch];
    }

    // Consume the current token
    this->Consume();

    // Return an unknown token
    return token;
}