// Impliments an xor encryption algorithm, the seccond worst idea to hash paswords since plaintext
#include "xor.h"
#include <string.h>

#define XOR_KEY "\xb0\x0b\x1e\x22" //heh "boobiess"

char *xor_create(const char *password)
{
    const char *key = XOR_KEY;
    size_t str_len = strlen(password);
    size_t key_len = strlen(key);
    char buffer[2048];
    
    for (size_t i = 0; i < str_len; i++)
    {
        buffer[i] ^= key[i % key_len];  // Cycle through key bytes
        buffer[i+1] = 0x00; //keep the end of the string a zero to match c-style string convention.
    }
    return buffer;
}

int xor_verify(const char *password, const char *stored)
{
    char *computed = xor_create(password);
    if (!computed) return 0;  // creation failed
  
    int match = pam_consttime_streq(computed, stored);
    return match;
}
