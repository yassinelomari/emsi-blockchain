#include <stdint.h>
#include <openssl/sha.h>


uint8_t *sha256(int8_t const *s, size_t len, uint8_t digest
[SHA256_DIGEST_LENGTH])
{
if (digest)
{
	/**
	 *The SHA256 function compute the hash value of @s and put it in
	 *@digest
	 */
	SHA256((const unsigned char *)s, len, (unsigned char *)digest);
	return (digest);
}
/*
 *return NULL if digest is NULL
 */
return (NULL);
}

