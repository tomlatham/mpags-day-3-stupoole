//
// Created by stu on 01/11/2019.
//

#include "CaesarCipher.hpp"
#include <iostream>

CaesarCipher::CaesarCipher(const size_t& caeser_key) : key_ {caeser_key}
{

}


CaesarCipher::CaesarCipher(const std::string& caeser_key)  : key_ {0}
{
  bool isNum {true};
  if ( ! caeser_key.empty() ) {

    for (const auto &elem : caeser_key) {
      if (!std::isdigit(elem)) {
        std::cerr << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
                  << "        the supplied key (" << caeser_key
                  << ") could not be successfully converted" << std::endl;
        isNum = false;
	break;
      }
    }

    if (isNum){
      key_ = std::stoul(caeser_key);
    }
  }
}


std::string CaesarCipher::applyCipher(const std::string &inputText,
  const CipherMode cipherMode) const {

  // Create the output string
  std::string outputText {};

  // Create the alphabet container
  // Make sure that the key is in the range 0 - 25
  const size_t truncatedKey { key_ % alphabetSize_};

  // Loop over the input text
  char processedChar {'x'};
  for ( const auto& origChar : inputText ) {

    // For each character in the input text, find the corresponding position in
    // the alphabet by using an indexed loop over the alphabet container
    for ( size_t i{0}; i < alphabetSize_; ++i ) {

      if ( origChar == alphabet_[i] ) {

        // Apply the appropriate shift (depending on whether we're encrypting
        // or decrypting) and determine the new character
        // Can then break out of the loop over the alphabet
        switch (cipherMode){
        case CipherMode::Encrypt:
          processedChar = alphabet_[ (i + truncatedKey) % alphabetSize_];
          break;
        case CipherMode::Decrypt:
          processedChar = alphabet_[ (i + alphabetSize_ - truncatedKey) % alphabetSize_];
          break;
        default:
          break;
        }

      }
    }

    // Add the new character to the output text
    outputText += processedChar;
  }

  return outputText;
}

