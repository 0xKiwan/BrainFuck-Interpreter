
#include "../inc/token.hpp"

// Macro to convert a token to string.
#define TOKEN_TO_STRING(token) case TOKEN_##token: return #token;


// Implementation for BFToken::BFToken()
BFToken::BFToken(int32_t type, uint32_t line, uint32_t column, char token_c)
{
    this->token_type    = type;
    this->line_number   = line;
    this->column_number = column;
    this->token_c       = token_c;
}

// Implementation for BFToken::ToString()
const char* BFToken::ToString()
{
    switch ((BFTokenType)this->token_type)
    {
        TOKEN_TO_STRING(START)
        TOKEN_TO_STRING(DECREMENT)
        TOKEN_TO_STRING(INCREMENT)
        TOKEN_TO_STRING(SHIFT_LEFT)
        TOKEN_TO_STRING(SHIFT_RIGHT)
        TOKEN_TO_STRING(OUTPUT)
        TOKEN_TO_STRING(INPUT)
        TOKEN_TO_STRING(OPEN_LOOP)
        TOKEN_TO_STRING(CLOSE_LOOP)
        TOKEN_TO_STRING(UNKNOWN)
        TOKEN_TO_STRING(END)
    }

    return "UNKNOWN";
}