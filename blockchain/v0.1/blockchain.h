#ifndef HEADER_BLOCKCHAIN
#define HEADER_BLOCKCHAIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <llist.h>
#include <stdint.h>
#include <openssl/sha.h>
#include <time.h>

#define GNS_DATA "Holberton School"
#define GNS_DATA_LEN 16
#define GNS_HASH "\xc5\x2c\x26\xc8\xb5\x46\x16\x39\x63\x5d\x8e\xdf\x2a\x97\xd4\x8d\x0c\x8e\x00\x09\xc8\x17\xf2\xb1\xd3\xd7\xff\x2f\x04\x51\x58\x03"
#define GNS_TIMESTAMP 1537578000

/**
 * struct blockchain_s - Blockchain structure
 *
 * @chain: Linked list of pointers to block_t
 */
typedef struct blockchain_s
{
	llist_t     *chain;
} blockchain_t;

/**
 * struct block_info_s - Block info structure
 *
 * @index:      Index of the Block in the Blockchain
 * @difficulty: Difficulty of proof of work (hash leading zero bits)
 * @timestamp:  Time the Block was created at (UNIX timestamp)
 * @nonce:      Salt value used to alter the Block hash
 * @prev_hash:  Hash of the previous Block in the Blockchain
 */
typedef struct block_info_s
{
	uint32_t    index;
	uint32_t    difficulty;
	uint64_t    timestamp;
	uint64_t    nonce;
	uint8_t     prev_hash[SHA256_DIGEST_LENGTH];
} block_info_t;

#define BLOCKCHAIN_DATA_MAX 1024

/**
 * struct block_data_s - Block data
 *
 * @buffer: Data buffer
 * @len:    Data size (in bytes)
 */
typedef struct block_data_s
{
	int8_t      buffer[BLOCKCHAIN_DATA_MAX];
	uint32_t    len;
} block_data_t;

/**
 * struct block_s - Block structure
 *
 * @info: Block info
 * @data: Block data
 * @hash: 256-bit digest of the Block, to ensure authenticity
 */
typedef struct block_s
{
	block_info_t    info; /* This must stay first */
	block_data_t    data; /* This must stay second */
	uint8_t     hash[SHA256_DIGEST_LENGTH];
} block_t;

/**
 * blockchain_create - function create a new blockchain
 *
 * Return: this function return the created blockchain
 *
*/
blockchain_t *blockchain_create(void);
/**
 * block_create - function create a new block and initializes it
 *
 * @prev: pointet to the previous block in the chain
 * @data: the data to be stored in the block
 * @data_len: the length of data
 * Return: the created block
 */
block_t *block_create(block_t const *prev, int8_t const *data, uint32_t data_len);
/**
 * block_destroy - function destroy a block 
 *
 * @block: pointer to the block to be destroied
 */
void block_destroy(block_t *block);
#endif
