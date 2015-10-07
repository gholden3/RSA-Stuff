// ECE4122/6122 RSA Encryption/Decryption assignment
// Fall Semester 2015

#include <iostream>
#include "RSA_Algorithm.h"

using namespace std;

gmp_randclass r1 (gmp_randinit_default);
//void createKeyPair(mpz_class, mpz_class, mpz_class, mpz_class * d, mpz_class *e);
void getRand(mpz_class *, mpz_class);
void getD(mpz_class *, mpz_class, mpz_class);

int main()
{
  // Instantiate the one and only RSA_Algorithm object
  RSA_Algorithm RSA;
  
  // Loop from sz = 32 to 1024 inclusive
  for(mpz_class sz =32;sz<1024;sz*=2){
    mpz_class p, q, n, d, e, phiN;
    //choose 10 different key pairs 
    for(int i = 0;i<9;i++){
      getRand(&p,sz);
      getRand(&q,sz);
      n = p * q; 
      phiN = (p-1) * (q-1);
      getD(&d, sz*2, phiN);
      mpz_invert(e.get_mpz_t(), d.get_mpz_t(), phiN.get_mpz_t());
      RSA.n = n;
      RSA.d = d;
      RSA.e = e;
      RSA.PrintNDE();
      //generate 10 random messages for each key pair
    }

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
 
void getD(mpz_class * d, mpz_class size, mpz_class phi){
  mpz_class tempD;
  mpz_class gcd;
  while(1){
    tempD = r1.get_z_bits(size);
    if( (tempD < phi) && (tempD > 1)){
      //ensure that the gcd of d and phi is exactly 1
      //gcd function takes mp_int
      mpz_gcd(gcd.get_mpz_t(),tempD.get_mpz_t(),phi.get_mpz_t());
      if(gcd ==1){
        *d = tempD;
        return;
      }
    }
  }
}

//get random number. used for P and Q
void getRand(mpz_class * p,mpz_class size){
 mpz_class tempP;
 while(1){
   tempP  = r1.get_z_bits(size);
  // mpz probab_prime takes mpz_t
   if(mpz_probab_prime_p(tempP.get_mpz_t(),100) == 1){
    *p = tempP;
    return;
  }
}
}
