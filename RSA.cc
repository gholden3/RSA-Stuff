// ECE4122/6122 RSA Encryption/Decryption assignment
// Fall Semester 2015

#include <iostream>
#include "RSA_Algorithm.h"

using namespace std;

gmp_randclass r1 (gmp_randinit_default);
//void createKeyPair(mpz_class, mpz_class, mpz_class, mpz_class * d, mpz_class *e);
void createPandQ(mpz_class * , mpz_class);

int main()
{
  // Instantiate the one and only RSA_Algorithm object
  RSA_Algorithm RSA;
  
  // Loop from sz = 32 to 1024 inclusive
  for(mpz_class sz =32;sz<1024;sz*=2){
    mpz_class p, q, n, d, e;
    createPandQ(&p,sz);
    createPandQ(&q,sz);
   // createKeyPair(p,q,n,&d,&e);
  // for each size choose 10 different key pairs
  // For each key pair choose 10 differnt plaintext 
  // messages making sure it is smaller than n.
  // If not smaller then n then choose another
  // For eacm message encrypt it using the public key (n,e).
  // After encryption, decrypt the ciphertext using the private
  // key (n,d) and verify it matches the original message.

  // your code here
  }
}

void createPandQ(mpz_class *  p,mpz_class size){
mpz_class tempP;
while(1){
    tempP  = r1.get_z_bits(size);
    //mpz probab_prime takes mpz_t
    if(mpz_probab_prime_p(tempP.get_mpz_t(),100) == 1){
      *p = tempP;
      return;
    }
  }
}
 
//void createKeyPair(mpz_class p, mpz_class q, mpz_class n, mpz_class * d, mpz_class * e){
  
//}
