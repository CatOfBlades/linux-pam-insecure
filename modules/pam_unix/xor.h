#ifndef XOR_H
#define XOR_H

char *xor_create(const char *password);

int xor_verify(const char *password, const char *stored);

#endif //XOR_H
