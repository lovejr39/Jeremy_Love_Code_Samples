#ifndef BITSET_HPP
#define BITSET_HPP
#include <string>

class Bitset{
public:

//Default Constructor
//Set bitset variables to default values.
  Bitset();

//Alternate Constructor
//  Custom size of bitset accepted as a parameter of type intmax_t.
//  If size <= 0, bitset will be declared as invalid.
  Bitset(intmax_t size);

//Alternate Constructor
//  Custom bitset contents accepted as a parameter of type string.
//  If bitset contents contain a value other than 0 or 1, the bitset will be declared as invalid
  Bitset(const std::string & value);

//Deconstructors
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

//Accessor - Return intmax_t size of bitset.
  intmax_t size() const;

//Accessor - Return bitsetValidity.
  bool good() const;

//Set the bit located at the parameter index to 1.
//If index is out of range, bitset becomes invalid.
  void set(intmax_t index);

//Reset the bit located at the parameter index to 0.
//If index is out of range, bitset becomes invalid.
  void reset(intmax_t index);

//Toggle the bit located at the paramter index.
//If index is out of range, bitset becomes invalid.
  void toggle(intmax_t index);

//Check bit value at parameter index.
//Return bool state of bit; true if 1, false if 0 or out of range index.
//If index is out of range, bitset becomes invalid.
  bool test(intmax_t index);

//Accessor - Return full bitsetString.
  std::string asString() const;

private:

  

  int *bitsetData ;
  intmax_t bitsetSize ;
  bool bitsetValidity ;
};

#endif
