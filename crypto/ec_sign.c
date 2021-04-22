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
	uint32_t length = 0;

	if (!key || !msg || !msglen)
		return (NULL);
	memset(sig->sig, 0, sizeof(sig->sig));
	if (!ECDSA_sign(0, msg, (int)msglen, sig->sig, &length, (EC_KEY *)key))
		return (NULL);
	sig->len = (uint8_t)length;
	return (sig->sig);
}

