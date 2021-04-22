#include "hblk_crypto.h"
/**
 * ec_save - function save public key and privite key in file
 * @key: the EC_KEY contaning the public and privite key
 * @folder: the path where key's files are saved
 * Return: 1 or 0 upon success or failure
*/
int ec_save(EC_KEY *key, char const *folder)
{
	char my_file[BUFSIZ];
	FILE *file;

	if (!key || !folder)
		return (0);
	mkdir(folder, 0700);
	sprintf(my_file, "%s/%s", folder, PRIVATE_FILE);
	file = fopen(my_file, "w");
	if (!file)
		return (0);
	if (!PEM_write_ECPrivateKey(file, key, NULL, NULL, 0, NULL, NULL))
		return (0);
	fclose(file);
	sprintf(my_file, "%s/%s", folder, PUBLIC_FILE);
	file = fopen(my_file, "w");
	if (!file)
		return (0);
	if (!PEM_write_EC_PUBKEY(file, key))
		return (0);
	fclose(file);
	return (1);
}
