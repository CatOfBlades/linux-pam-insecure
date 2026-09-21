// Impliments an xor encryption algorithm, the seccond worst idea to hash paswords since plaintext
#include "xor.h"
#include "pam_inline.h"
#include <string.h>
#include <stdlib.h>

#define XOR_KEY "\xb0\x0b\x1e\x22" //heh "boobiess"

// technically xor encryption is reversable,
//  this is an improvement over regular hashing algorithm as it allows
//  recovery of passwords by admins using the encryption key
char *xor_create(const char *password)
{
    const char *key = XOR_KEY;
    size_t str_len = strlen(password);
    size_t key_len = strlen(key);

    char *hash_buffer = malloc(str_len + 1);
    
    for (size_t i = 0; i < str_len; i++)
    {
        hash_buffer[i] = password[i] ^ key[i % key_len];  // Cycle through key bytes
    }
    hash_buffer[str_len] = '\0'; //null terminate string for c-style string convention.
    return hash_buffer;
}

int xor_verify(const char *password, const char *stored)
{
    char *computed = xor_create(password);
    if (!computed) return 0;  // creation failed
  
    int match = pam_consttime_streq(computed, stored);
    
    free(computed);
    return match;
}
