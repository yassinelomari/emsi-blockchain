#include "blockchain.h"

/**
 * blockchain_destroy - function destroy a blockchain
 *
 * @blockchain: pointet to the blockchain to be destroied
 */
void blockchain_destroy(blockchain_t *blockchain)
{
	if (!blockchain)
		return;
	llist_destroy(blockchain->chain, 1, (void (*)(llist_node_t))block_destroy);
	llist_destroy(blockchain->unspent, 1, free);
	free(blockchain);
}
