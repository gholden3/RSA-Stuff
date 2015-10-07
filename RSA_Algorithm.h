// RSA Assignment for ECE4122/6122 Fall 2015
// There should be no need to edit this file at all, but change if you feel the need.

#ifndef __RSA_ALGORITHM_H__
#define __RSA_ALGORITHM_H__

#include <gmpxx.h>

class RSA_Algorithm 
{
public:
  // Default Constructor
  RSA_Algorithm();

  // Generate key
  void GenerateRandomKeyPair(size_t sz);


  // Encrypt plaintext message M with key  pair n/e
  // By convention, we will make the encryption key e the public key
  // and the decryption key d the private key.
  mpz_class Encrypt(mpz_class M);

  // Decrypt ciphertext message C with key pair n/d
  mpz_class Decrypt(mpz_class C);

  // Debug printing
  // Print n and d
  void PrintND();

  // print n and e
  void PrintNE();

  void PrintPQ();

  // Print n, d, and e
  void PrintNDE();

  // Print plaintext message
  void PrintM(mpz_class M);

  //print ouput M 
  void PrintoutM(mpz_class outM);
  // Print Ciphertext message
  void PrintC(mpz_class C);

public:
  // Member variables
  mpz_class n;  // p * q
  mpz_class e;  // Public encryption key
  mpz_class d;  // Private decryption key
  mpz_class p;
  mpz_class q;
  // Public Random number generator
public:
  gmp_randclass rng;

};
#endif
