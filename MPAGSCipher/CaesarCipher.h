//
// Created by stu on 01/11/2019.
//

#ifndef MPAGSCIPHER_CAESARCIPHER_H
#define MPAGSCIPHER_CAESARCIPHER_H

#include "CipherMode.h"
#include <iostream>
#include <string>
#include <sys/param.h>
#include <vector>

class CaesarCipher {
  private:
    const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    const size_t alphabetSize_ = alphabet_.size();
    size_t key_;
  public:

  explicit CaesarCipher(const size_t& caeser_key);
  explicit CaesarCipher(const std::string& caeser_key);
  std::string applyCaesar(const std::string& inputText, CipherMode cipherMode);
};

#endif // MPAGSCIPHER_CAESARCIPHER_H
