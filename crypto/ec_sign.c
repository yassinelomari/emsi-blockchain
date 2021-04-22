#include "hblk_crypto.h"

/**
 * ec_sign - function signs a given set of bytes
 * @key: the EC_KEY contaning the public and privite key
 * @msg: characters to be signed
 * @msglen: length of @msg
 * @sig: the structure of signature
 * Return: A pointor to the signature
*/
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg, size_t msglen,
	sig_t *sig)
{
	unsigned char hash[SHA256_DIGEST_LENGTH];

	if (!key || !msg || !sig)
		return (NULL);
	if (!EC_KEY_check_key(key))
		return (NULL);
	if (!SHA256(msg, msglen, hash))
		return (NULL);
	sig->len = ECDSA_size(key);
	if (!sig->len)
		return (NULL);
	if (ECDSA_sign(EC_CURVE, hash, SHA256_DIGEST_LENGTH, sig->sig,
				(unsigned int *)&(sig->len), (EC_KEY *)key) != 1)
		return (NULL);
	return (sig->sig);
}

