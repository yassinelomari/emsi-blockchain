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
	uint8_t buffer[SHA256_DIGEST_LENGTH];
	unsigned int len;

	if (key == NULL || msg == NULL || sig == NULL)
		return (NULL);
	if (!EC_KEY_check_key(key))
		return (NULL)
	sig->len = (uint8_t)ECDSA_size(key);
	if (!SHA256(msg, msglen, buffer))
		return (NULL);
	memset(sig->sig, 0, sizeof(sig->sig));
	if (!ECDSA_sign(EC_CURVE, buffer, SHA256_DIGEST_LENGTH, sig->sig,
		 &len, (EC_KEY *)key))
		return (NULL);
	sig->len = len;
	return (sig->sig);
}
