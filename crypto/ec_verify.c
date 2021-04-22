#include "hblk_crypto.h"

/**
 * ec_sign - function signs a given set of bytes
 * @key: the EC_KEY contaning the public and privite key
 * @msg: characters to be verified
 * @msglen: length of @msg
 * @sig: the structure of signature to be checked
 * Return: 1 if the signature is valid, and 0 otherwise
*/
int ec_verify(EC_KEY const *key, uint8_t const *msg, size_t msglen,
	sig_t const *sig)
{
	uint8_t buffer[SHA256_DIGEST_LENGTH];

	if (!key || !msg || !sig)
		return (0);

	if (!EC_KEY_check_key(key))
		return (0);

	if (!SHA256(msg, msglen, buffer))
		return (0);

	if (ECDSA_verify(0, buffer, SHA256_DIGEST_LENGTH, sig->sig,
		sig->len, (EC_KEY *)key) != 1)
		return (0);

	return (1);
}
