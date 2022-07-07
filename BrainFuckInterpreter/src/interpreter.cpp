#include "../inc/interpreter.hpp"

// Implementation for BFInterpreter::BFInterpreter()
BFInterpreter::BFInterpreter(std::vector<BFToken> tokens)
{
	// Store the vector of tokens
	this->tokens	= tokens;

	// Initialize the tape
	this->tape		= new char[30000];

	// Set all values in the tape to 0
	std::memset(this->tape, 0, sizeof(char) * 30000);

	// Start the process at the middle of the tape.
	this->head_idx  = (30000 / 2);

	// Set PC to 0 to begin with
	this->pc		= 0;

	// Stores the current token, should be TOKEN_START
	this->cur_token = &this->tokens[0];
}

// Implementation for BFInterpreter::Run()
void BFInterpreter::Run()
{
	// Loop until cur_token is TOKEN_END
	while (static_cast<BFTokenType>((*this->cur_token).token_type) != TOKEN_END)
	{
		// Used to track bracket opening/closing
		int32_t brackets = 0;

		// Handle the current token type
		switch (static_cast<BFTokenType>((*this->cur_token).token_type))
		{
		case TOKEN_INCREMENT:

			// Increment current value at the head
			this->tape[this->head_idx]++;
			break;
		case TOKEN_DECREMENT:

			// Decrement current value at the head
			this->tape[this->head_idx]--;
			break;
		case TOKEN_SHIFT_LEFT:

			// Check if head index is 0 and wrap to the end
			if (this->head_idx == 0) this->head_idx = 0;

			// Otherwise decrement the head index
			else this->head_idx--;

			break;
		case TOKEN_SHIFT_RIGHT:

			// Check if we are at the end of the tape and wrap to the start
			if (this->head_idx == 29999) head_idx = 0;

			// Otherwise increment the head index.
			else this->head_idx++;

			break;
		case TOKEN_INPUT:

			// Capture user input and store it at the head.
			this->tape[this->head_idx] = getchar();
			break;
		case TOKEN_OUTPUT:

			// Output the current char at the head.
			putchar(this->tape[this->head_idx]);
			break;
		case TOKEN_OPEN_LOOP:
			
			// Skip the loop if data at head is zero.
			if (!this->tape[this->head_idx])
			{
				// Loop forwards through tokens until we find an opening loop
				for (brackets = 1; brackets; pc++)
				{
					// Check for another loop open and increment open loop count
					if ((BFTokenType)this->tokens[pc].token_type == TOKEN_OPEN_LOOP) brackets++;

					// Check for a close loop and decrement open loop count
					else if ((BFTokenType)this->tokens[pc].token_type == TOKEN_CLOSE_LOOP) brackets--;
				}
			}
			break;

		case TOKEN_CLOSE_LOOP:
			
			// Enter the loop if data at head is non-zero.
			if (this->tape[this->head_idx])
			{
				// Go to just before the ]
				pc -= 2;

				// Loop backwards through tokens until we find an opening loop.
				for (brackets = 1; brackets; pc--)
				{
					// Check for another loop open, and increment open loop count
					if (this->tokens[pc].token_type == TOKEN_CLOSE_LOOP) brackets++;

					// Check for a close loop and decrement open loop count
					else if (this->tokens[pc].token_type == TOKEN_OPEN_LOOP) brackets--;
				}

				// Advance pointer after loop to matching with opening [
				pc++;
			}

			break;

		}

		// Increment instruction counter
		pc++;

		// Update current token
		this->cur_token = &this->tokens[pc];
	}
}