#include "../inc/linter.hpp"
#include <string>

// Implementation for BFLinter::BFLinter()
BFLinter::BFLinter(std::vector<BFToken> tokens)
{
	this->tokens = tokens;
}

// Implementation for BFLinter::Run()
BFLinterError BFLinter::Run()
{
	// Loop through tokens
	for (int32_t idx = 0; idx < this->tokens.size(); idx++)
	{
		// Get the current token
		BFToken *token = &this->tokens[idx];

		// Will store the open bracket count
		int32_t brackets = 0;

		// Handle opening braces
		if (token->token_type == TOKEN_OPEN_LOOP)
		{
			// Store the index we started at
			int32_t bracket_idx = idx+1;

			// Loop through the rest of the tokens
			for (brackets = 1; brackets; bracket_idx++)
			{
				// Get the current token
				BFToken *check_token = &this->tokens[bracket_idx];

				// Check if the token is an opening bracket
				if (check_token->token_type == TOKEN_OPEN_LOOP) brackets++;

				// Check if the token is a closing bracket
				else if (check_token->token_type == TOKEN_CLOSE_LOOP) brackets--;

				// Check for EOF
				else if (check_token->token_type == TOKEN_END)
				{
					// We need to throw an error
					printf("[BFLint] [Error]: Unclosed loop at line %d, col %d", token->line_number, token->column_number);

					// Exit
					exit(0);
				}
			}
		}

		// Handle closing braces
		else if (token->token_type == TOKEN_CLOSE_LOOP)
		{
			// Store the index we started at
			int32_t bracket_idx = idx-1;

			// Loop through the rest of the tokens
			for (brackets = 1; brackets; bracket_idx--)
			{
				// Get the current token
				BFToken* check_token = &this->tokens[bracket_idx];

				// Check if the token is an opening bracket
				if (check_token->token_type == TOKEN_OPEN_LOOP) brackets--;

				// Check if the token is a closing bracket
				else if (check_token->token_type == TOKEN_CLOSE_LOOP) brackets++;

				// Check for EOF
				else if (check_token->token_type == TOKEN_START)
				{
					// We need to throw an error
					printf("[BFLint] [Error]: Loop closed without open at line %d, col %d", token->line_number, token->column_number);

					// Exit
					exit(0);
				}
			}
		}

		// Handle unknown tokens
		else if (token->token_type == TOKEN_UNKNOWN)
		{
			// Store the index the unknown token started at
			int32_t token_idx = idx + 1;

			// Will store the full token
			std::string token_str;

			// Append current token to the str
			token_str += token->token_c;

			// Loop through the rest of the tokens and grab any unknowns
			for (;;)
			{
				// Get next token
				BFToken* cur_token = &this->tokens[token_idx];

				// Check if this token is unknown too
				if (cur_token->token_type == TOKEN_UNKNOWN)
				{
					// Append current token to the str
					token_str += cur_token->token_c;

					// Increment token idx
					token_idx++;

					// Skip this iteration
					continue;
				}

				// Break from the loop
				break;
			}

			// Log the error
			printf("[BFLint] [Error]: Unidentified token '%s' at line %d, col %d\n", token_str.c_str(), token->line_number, token->column_number);

			// Exit
			exit(1);
		}

	}

	return BFLinterError{};
}