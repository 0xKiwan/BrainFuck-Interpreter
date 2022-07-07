#ifndef _BF_TOKEN_HPP
#define _BF_TOKEN_HPP

#include <cstdint>

enum BFTokenType
{
    TOKEN_START,            // Start of the program.
    TOKEN_DECREMENT,        // -
    TOKEN_INCREMENT,        // +
    TOKEN_SHIFT_LEFT,       // <
    TOKEN_SHIFT_RIGHT,      // >
    TOKEN_OUTPUT,           // .
    TOKEN_INPUT,            // ,
    TOKEN_OPEN_LOOP,        // [
    TOKEN_CLOSE_LOOP,       // ]
    TOKEN_UNKNOWN,          // Used to skip unhandled tokens
    TOKEN_END,              // End of file 0x00 token
};

class BFToken
{
public: // Public members for this class

    int32_t     token_type;
    uint32_t    line_number;
    uint32_t    column_number;
    char        token_c;


public: // Public methods for this class.

    /**
     * Constructor for this class
     */
    BFToken(int32_t type, uint32_t line, uint32_t column, char token_c);

    /**
     * Used to convert the token type to a string
     */
    const char* ToString();
};


#endif // _BF_TOKEN_HPP