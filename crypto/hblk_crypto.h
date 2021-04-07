/*
 *this file is the header of tasks of Blockchain - crypto
 */
#ifndef HEADER_FILE
#define HEADER_FILE
/**
 *This function calculate the hash of *@s: witch has @len like length and
 *store it in @digest
*/
uint8_t *sha256(int8_t const *s, size_t len, uint8_t digest
[SHA256_DIGEST_LENGTH]);
#endif
