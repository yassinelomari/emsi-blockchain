#include "hblk_crypto.h"

EC_KEY *ec_create(void)
{
	EC_KEY *mykey;

	mykey = malloc(sizeof(mykey));
	mykey = EC_KEY_new_by_curve_name(NID_secp256k1);
	if (mykey == NULL)
		return (NULL);
	if (!EC_KEY_generate_key(mykey))
	{
		EC_KEY_free(mykey);
		return (NULL);
	}
	return (mykey);
}

