#include "blockchain.h"

blockchain_t *blockchain_create(void)
{	
	int i;
	char * blk_buffer = "Holberton School";
	char * blk_hash = "\xc5\x2c\x26\xc8\xb5\x46\x16\x39\x63\x5d\x8e\xdf\x2a\x97\xd4\x8d\x0c\x8e\x00\x09\xc8\x17\xf2\xb1\xd3\xd7\xff\x2f\x04\x51\x58\x03";
	blockchain_t *blk_ch;
	
	block_t blk_genesis;

	block_info_t blk_info;

	block_data_t blk_data;

	blk_info.index = 0;
	blk_info.difficulty = 0;
	blk_info.timestamp = 1537578000;
	blk_info.nonce = 0;
	
	for(i = 0; i < SHA256_DIGEST_LENGTH; i++)
	{
		blk_info.prev_hash[i] = (uint8_t)0;
		blk_genesis.hash[i] = (uint8_t)blk_hash[i];
	}

	for(i = 0; i < 16; i++)
	{
		blk_data.buffer[i] = (int8_t)blk_buffer[i];
	}
	blk_data.len = 16;

	blk_genesis.info = blk_info;
	blk_genesis.data = blk_data;

	blk_ch = malloc(sizeof(*blk_ch));
	blk_ch->chain = llist_create(MT_SUPPORT_FALSE);

	llist_add_node(blk_ch->chain , (llist_node_t *)&blk_genesis, ADD_NODE_FRONT);

	return (blk_ch);
}
