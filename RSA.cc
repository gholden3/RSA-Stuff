// ECE4122/6122 RSA Encryption/Decryption assignment
// Fall Semester 2015

#include <iostream>
#include "RSA_Algorithm.h"

using namespace std;

gmp_randclass r1 (gmp_randinit_default);
//void createKeyPair(mpz_class, mpz_class, mpz_class, mpz_class * d, mpz_class *e);
void getRand(mpz_class *, mpz_class);
void getD(mpz_class *, mpz_class, mpz_class);
void getM(mpz_class *, mpz_class, mpz_class);
void getC(mpz_class *, mpz_class *, mpz_class, mpz_class);

int main()
{
  // Instantiate the one and only RSA_Algorithm object
  RSA_Algorithm RSA;
  
  // Loop from sz = 32 to 1024 inclusive
  for(mpz_class sz =32;sz<1024;sz*=2){
    mpz_class p, q, n, d, e, phiN;
    mpz_class M, outM, C;
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
      for(int j = 0;j<10;j++){
        getM(&M, (sz*2)-1, n);
        RSA.PrintM(M);
        //encrypt each message using public key (n,e).
        getC(&C, &M, e, n);
        RSA.PrintC(C);
        //decrypt it 
        getC(&outM, &C, d, n);
        //RSA.PrintoutM(outM);
      }
    }

  // After encryption, decrypt the ciphertext using the private
  // key (n,d) and verify it matches the original message.

  // your code here
  }
}

void getC(mpz_class *C, mpz_class *M, mpz_class e, mpz_class n){
  // C = (M^e)%n
  mpz_powm((*C).get_mpz_t(), (*M).get_mpz_t(), e.get_mpz_t(), n.get_mpz_t());

}

 
void getM(mpz_class *M, mpz_class size, mpz_class n){
  mpz_class tempM;
  while(1){
    tempM = r1.get_z_bits(size);
    if(tempM<n){
      *M = tempM;
      return;
    }
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
