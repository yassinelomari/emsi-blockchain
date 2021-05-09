#include "blockchain.h"

/**
 * block_destroy - function destroy a block
 *
 * @block: pointer to the block to be destroied
 */
void block_destroy(block_t *block)
{
	if (!block)
		return;
	llist_destroy(block->transactions, 1, (node_dtor_t)transaction_destroy);
	free(block);
}
