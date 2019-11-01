//
// Created by stu on 01/11/2019.
//

#ifndef MPAGSCIPHER_CAESERCIPHER_H
#define MPAGSCIPHER_CAESERCIPHER_H

#include <sys/param.h>
#include <vector>

class CaeserCipher {
  public:
    const size_t& key_;

  explicit CaeserCipher(const size_t& caeser_key);
};

#endif // MPAGSCIPHER_CAESERCIPHER_H
