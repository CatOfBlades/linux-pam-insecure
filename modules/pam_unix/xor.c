// TODO: impliment an xor encryption algorithm as the seccond worst idea to hash paswords since plaintext

char *xor_create(const char *password);

int xor_verify(const char *password, const char *stored)
{
  // if ( xor_create(password) == stored ) // this should use strcmp or something when actually implimented
  // {
  //   return 1; // 1 or whatever success is
  // }
  // else
  // {
  //   return 0; // our failure case
  // }
}
