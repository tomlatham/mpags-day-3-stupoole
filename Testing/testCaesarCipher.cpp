//
// Created by stu on 06/11/2019.
//
#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"
#include "TransformChar.hpp"


TEST_CASE("Encrypted output is as expected with key 5 as a string","[]")
{
  CaesarCipher cipher_5 {"5"};
  CipherMode encrypt { CipherMode::Encrypt };
  const std::string input{"TESTONETWOTHREEFOUR"};
  const std::string result_5{"YJXYTSJYBTYMWJJKTZW"};
  REQUIRE(cipher_5.applyCipher(input, encrypt) == result_5);
}

TEST_CASE("Encryption is reversible with decryption with key as 5 with a number","[]")
{
  CaesarCipher caeserCipher {"5"};
  CipherMode encrypt { CipherMode::Encrypt };
  CipherMode decrypt { CipherMode::Decrypt };
  const std::string input{"TESTONETWOTHREEFOUR"};
  const std::string output {caeserCipher.applyCipher(input, encrypt)};
  REQUIRE(caeserCipher.applyCipher(output,decrypt) == input);
}

TEST_CASE("Encryption works with large keys as string","[]")
{
  CaesarCipher cipher_large {"28"};
  CipherMode encrypt { CipherMode::Encrypt };
  const std::string input{"TESTONETWOTHREEFOUR"};
  const std::string result_large {"VGUVQPGVYQVJTGGHQWT"};
  REQUIRE(cipher_large.applyCipher(input,  encrypt) == result_large);
}
