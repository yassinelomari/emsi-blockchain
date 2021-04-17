#include "hblk_crypto.h"

EC_KEY *ec_create(void)
{
	const char * curve_name = "secp521r1";
	int  nid;
	EC_KEY * mykey;

	nid = OBJ_txt2nid(curve_name);
	
	mykey = malloc(sizeof(EC_KEY *));
	mykey = EC_KEY_new_by_curve_name(nid);
	
	return mykey;
}
