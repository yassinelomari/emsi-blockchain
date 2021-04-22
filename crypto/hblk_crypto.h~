#ifndef HEADER_SHA256
#define HEADER_SHA256
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/stat.h>
#include <openssl/opensslconf.h>
#include <openssl/ec.h>
#include <openssl/ecdsa.h>
#include <openssl/obj_mac.h>
#include <openssl/pem.h>
#include <openssl/sha.h>

#define EC_CURVE	NID_secp256k1
#define EC_PUB_LEN 65

#define PRIVATE_FILE "key.pem"
#define PUBLIC_FILE "key_pub.pem"

/**
 * sha256 - function calculate the hash of a data
 * @s: the data which we want to calculate the hash value
 * @len: the lenght of the data
 * @digest: the hash value
 * Return: the hash value
*/
uint8_t *sha256(int8_t const *s, size_t len, uint8_t digest
[SHA256_DIGEST_LENGTH]);
/**
 * ec_create - function generate private and the public keys
 * Return: the EC_KEY structur containing both the public and private keys
*/
EC_KEY *ec_create(void);
/**
 * ec_to_pub - function generate private and the public keys
 * @key: the EC_KEY contaning the public key
 * @pub: public key
 * Return: the uint8_t pointor to public key
*/
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN]);
/**
 * ec_from_pub - function generate EC_KEY from public keys
 * @pub: the public key
 * Return: the EC_KEY created
*/
EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN]);
/**
 * ec_save - function save public key and privite key in file
 * @key: the EC_KEY contaning the public and privite key
 * @folder: the path where key's files are saved
 * Return: 1 or 0 upon success or failure
*/
int ec_save(EC_KEY *key, char const *folder);
/**
 * ec_load - function load public key and privite key from file
 * @folder: the path where files are saved
 * Return: the EC_KEY contaning the public key and privite key
*/
EC_KEY *ec_load(char const *folder);
#endif

