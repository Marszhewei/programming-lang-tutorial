/**
 * @file base_type.cc
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief c++ basic type
 * @version 0.1
 * @date 2022-10-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
/* int and float limits */
#include <climits>
#include <cfloat>

/**
 * @brief just for __int128_t and __uint128_t
 * 
 */
namespace IO    {
    template<typename T> inline T read()    {
        T x = 0, w = 1; char ch = getchar();
        while (!isdigit(ch)) {if (ch == '-')w *= -1; ch = getchar();}
        while (isdigit(ch)) { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
        return x * w;
    }
    template<typename T> inline void write(T x, char end_ch)    {
        if (x < 0) {x = -x; putchar('-');}
        static int sta[101]; int top = 0;
        do {sta[top++] = x % 10; x /= 10;} while (x);
        while (top) putchar(sta[--top] + 48);
        putchar(end_ch);
    }
}using namespace IO;


int main(int argc, char **argv)
{
    /* type conversion */
    // c style
    int64_t a = (int64_t)32;
    // cpp style
    int64_t b = int64_t(32);
    
    /* short, int, long, long long, unsigned xx */
    signed int i = 0;                   // __int32_t
    unsigned int ui = 1;                // u_int (unsigned __int32_t)
    signed long int li = 2;             // __int64_t
    unsigned long int uli = 3;          // u_long (unsigned __int64_t)
    signed long long int lli = 4;       
    unsigned long long int ulli = 5;
    signed short int si = 6;            // __int16_t
    unsigned short int usi = 7;         // u_short (unsigned __int16_t)
    std::cout << "int : " << i << std::endl << "unsigned int : " << ui << std::endl;
    std::cout << "long int : " << li << std::endl << "unsigned long int : " << uli << std::endl;
    std::cout << "long long int : " << lli << std::endl << "unsigned long long int : " << ulli << std::endl;
    std::cout << "short int : " << si << std::endl << "unsigned short int : " << usi << std::endl;

    std::cout << "size of short & unsigned short : " << sizeof(short) << std::endl
              << "size of int & unsigned int : " << sizeof(int) << std::endl
              << "size of long & unsigned long : " << sizeof(long) << std::endl
              << "size of long long & unsigned long long : " << sizeof(long long) << std::endl;

    /* intxx_t uintxx_t */
    int8_t i8 = 'a';        // signed char
    uint8_t ui8 = 'b';      // unsigned char
    int16_t i16 = 2;        // signed short
    uint16_t ui16 = 3;      // unsigned short 
    int32_t i32 = 4;        // signed int
    uint32_t ui32 = 5;      // unsigned int
    int64_t i64 = 6;        // signed long
    uint64_t ui64 = 7;      // unsigned long
    __int128_t i128 = 8;
    __uint128_t ui128 = 9;
    std::cout << "int8_t : " << i8 << std::endl << "uint8_t : " << ui8 << std::endl;
    std::cout << "int16_t : " << i16 << std::endl << "uint16_t : " << ui16 << std::endl;
    std::cout << "int32_t : " << i32 << std::endl << "uint32_t : " << ui32 << std::endl;
    std::cout << "int64_t : " << i64 << std::endl << "uint64_t : " << ui64 << std::endl;

    std::cout << "size of int8_t & uint8_t : " << sizeof(int8_t) << std::endl
              << "size of int16_t & uint16_t : " << sizeof(int16_t) << std::endl
              << "size of int32_t & uint32_t : " << sizeof(int32_t) << std::endl
              << "size of int64_t & uint64_t : " << sizeof(int64_t) << std::endl;
    // this is not in standard, you can output it byself
    std::cout << "__int128_t : ";
    IO::write(i128, '\n');
    std::cout << "__uint128_t : ";
    IO::write(ui128, '\n');
    // std::cout << "__int128_t : " << i128 << std::endl << "__uint128_t : " << ui128 << std::endl;
    std::cout << "size of __int128_t : " << sizeof(__int128_t) << std::endl
              << "size of __uint128_t : " << sizeof(__uint128_t) << std::endl;

    /* hex oct dec binary */
    unsigned int hex = 0xff;
    unsigned int oct = 077;
    unsigned int dec = 47'458'121;
    auto bin = 0b00000011;
    std::cout << "Hex val : " << std::hex << hex << std::endl
              << "Oct val : " << std::oct << oct << std::endl
              << "Dec val : " << std::dec << dec << std::endl
              << "Bin val : " << bin << std::endl;

    /* boolean */
    bool flag = true;
    std::cout << "boolean : " << std::boolalpha << flag << std::endl;
    std::cout << "size of boolean : " << sizeof(bool) << std::endl;

    /* float double */
    float f = 3.14;
    double d = 2.7;
    long double ld = 4.23;
    std::cout << "float : " << f << std::endl << "double : " << d << std::endl
              << "long double : " << ld << std::endl;
    std::cout << "size of float : " << sizeof(float) << std::endl
              << "size of double : " << sizeof(double) << std::endl
              << "size of long double : " << sizeof(long double) << std::endl;
    _Float32 f32 = 1.1;     // float
    _Float32x f32x = 1.2;   // double
    _Float64 f64 = 1.3;     // double
    _Float64x f64x = 1.4;   // long double
    std::cout << "_Float32 : " << f32 << std::endl << "_Float32x : " << f32x << std::endl;
    std::cout << "_Float64 : " << f64 << std::endl << "_Float64x : " << f64x << std::endl;
    std::cout << "size of _Float32 : " << sizeof(_Float32) << std::endl
              << "size of _Float32x : " << sizeof(_Float32x) << std::endl;
    std::cout << "size of _Float64 : " << sizeof(_Float64) << std::endl
              << "size of _Float64x : " << sizeof(_Float64x) << std::endl;
    /* float text */
    float f1 = 18.46f;
    f1 = 18.;
    f1 = 16.87e2;
    f1 = 3.1415e-1;
    std::cout << "float with e&E : " << f1 << std::endl;

    /* void void* */
    void *vp;
    int val = 1;
    vp = &val;
    int *pval = (int *)vp;
    std::cout << "void * val : " << *pval << std::endl;
    std::cout << "size of void * : " << sizeof(void *) << std::endl;

    /* 0 NULL nullptr(std::nullptr_t) */
    // recommand using nullptr, it's better
    void *p = nullptr;

    return 0;
}