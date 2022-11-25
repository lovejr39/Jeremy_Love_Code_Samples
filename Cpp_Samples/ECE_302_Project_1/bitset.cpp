#include "bitset.hpp"

//Default Constructor
//Set bitset variables to default values.
    Bitset::Bitset()
    {
        bitsetSize = 8 ;
        bitsetData = new int[bitsetSize] ;

        for(intmax_t i = 0 ; i < bitsetSize ; i++)
            *(bitsetData + i) = 0 ;

        bitsetValidity = true ;
    }

//Alternate Constructor
//  Custom size of bitset accepted as a parameter of type intmax_t.
//  If size <= 0, bitset will be declared as invalid.
    Bitset::Bitset(intmax_t size)
    {
        bitsetSize = size ;

        if(bitsetSize > 0)
        {
            bitsetData = new int[bitsetSize] ;

            for(intmax_t i = 0 ; i < bitsetSize ; i++)
                *(bitsetData + i) = 0 ;
        }
        else
            bitsetValidity = false ;
    }

//Alternate Constructor
//  Custom bitset contents accepted as a parameter of type string.
//  If bitset contents contain a value other than 0 or 1, the bitset will be declared as invalid
    Bitset::Bitset(const std::string & value)
    {
        bitsetSize = value.length() ;
        bitsetData = new int[bitsetSize] ;
        bitsetValidity = true ;
        
        for(int i = 0 ; i < bitsetSize ; i++)
        {
            if(value.at(i) == '0')
                *(bitsetData + i) = 0 ;
            else if(value.at(i) == '1')
                *(bitsetData + i) = 1 ;
            else
            {
                bitsetValidity = false ;
                break ;
            }
        }
    }

//Deconstructors
    Bitset::~Bitset()
    {
        delete[] bitsetData ;
    }

//Accessor - Return intmax_t size of bitset.
    intmax_t Bitset::size() const
    {
        return bitsetSize ;
    }

//Accessor - Return bitsetValidity.
    bool Bitset::good() const
    {
        return bitsetValidity ;
    }

//Set the bit located at the parameter index to 1.
//If index is out of range, bitset becomes invalid.
    void Bitset::set(intmax_t index)
    {
        if(index < 0 || index >= bitsetSize)
            bitsetValidity = false ;
        else
            *(bitsetData + index) = 1 ;
    }

//Reset the bit located at the parameter index to 0.
//If index is out of range, bitset becomes invalid.
    void Bitset::reset(intmax_t index)
    {
        if(index < 0 || index >= bitsetSize)
            bitsetValidity = false ;
        else
            *(bitsetData + index) = 0 ;
    }

//Toggle the bit located at the paramter index.
//If index is out of range, bitset becomes invalid.
    void Bitset::toggle(intmax_t index)
    {
        if(index < 0 || index >= bitsetSize)
            bitsetValidity = false ;
        else
        {
            if(*(bitsetData + index) == 0)
                set(index) ;
            else
                reset(index) ;
        }
    }

//Check bit value at parameter index.
//Return bool state of bit; true if 1, false if 0 or out of range index.
//If index is out of range, bitset becomes invalid.
    bool Bitset::test(intmax_t index)
    {
        if(index < 0 || index >= bitsetSize)
        {
            bitsetValidity = false ;
            return false ;
        }
        else
        {
            if(*(bitsetData + index) == 0)
                return false ;
            else  
                return true ;
        }
    }

//Accessor - Return full bitsetString.
    std::string Bitset::asString() const
    {
        std::string bitsetString = "" ;

        for(int i = 0 ; i < bitsetSize ; i++)
            bitsetString += std::to_string(*(bitsetData + i)) ;

        return bitsetString ;
    }