#include "hblk_crypto.h"
/**
 * ec_from_pub - function generate EC_KEY from public keys
 * @pub: the public key
 * Return: the EC_KEY created
*/
EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN])
{
	EC_KEY * my_key;
	EC_POINT *my_point;
	EC_GROUP *my_grp;

	if (pub == NULL)
		return (NULL);
	my_key = malloc(sizeof(my_key));
	my_key = EC_KEY_new_by_curve_name(NID_secp256k1);
	if (my_key == NULL)
		return (NULL);
	my_grp = malloc(sizeof(my_grp));
	my_grp = EC_GROUP_new_by_curve_name(NID_secp256k1);
	if (my_grp == NULL) 
		return (NULL);
	my_point = EC_POINT_new(my_grp);
	if (my_point == NULL)
		return (NULL);
	if (!EC_POINT_oct2point(my_grp, my_point, pub, EC_PUB_LEN, NULL))
		return (NULL);
	if (!EC_KEY_set_public_key(my_key, my_point))
		return (NULL);
	return my_key;
	
}
