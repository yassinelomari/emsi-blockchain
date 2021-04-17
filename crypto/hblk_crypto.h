#ifndef HEADER_SHA256
#define HEADER_SHA256
#include <stdint.h>
#include <openssl/sha.h>
#include <openssl/ec.h>
#include <openssl/objects.h>

/**
 * sha256 - function calculate the hash of a data
 * @s: the data which we want to calculate the hash value
 * @len: the lenght of the data
 * @digest: the hash value
 * Return: the hash value
*/
uint8_t *sha256(int8_t const *s, size_t len, uint8_t digest
[SHA256_DIGEST_LENGTH]);
/**
 * ec_create - function generate private and the public keys
 * Return: the EC_KEY structur containing both the public and private keys
*/
EC_KEY *ec_create(void);
#endif

