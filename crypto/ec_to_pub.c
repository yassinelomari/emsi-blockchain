#include "hblk_crypto.h"
/**
 * ec_to_pub - function generate private and the public keys
 * @key: the EC_KEY contaning the public key
 * @pub: public key
 * Return: the uint8_t pointor to public key
*/
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN])
{
	const EC_POINT *my_point;
	const EC_GROUP *my_grp;

	if (key == NULL || pub == NULL)
		return (NULL);
	my_point = EC_KEY_get0_public_key(key);
	if (my_point == NULL)
		return (NULL);
	my_grp = EC_KEY_get0_group(key);
	if (my_grp == NULL)
		return (NULL);
	if (!EC_POINT_point2oct(my_grp, my_point,
		POINT_CONVERSION_UNCOMPRESSED, pub, EC_PUB_LEN, NULL))
		return (NULL);
	return (pub);
}
