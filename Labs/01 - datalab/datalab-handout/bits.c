/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  // This solution takes the two parts of a XOR gate ((NOT a AND b) OR (a AND NOT b)), 
  // and transforms it to an OR gate using three NOT operations and one AND operation
  int first_part = ~x & y;
  int second_part = x & ~y;
  int or_gate_with_and = ~(~first_part & ~second_part);
  return or_gate_with_and;
  // return ~(~(~x & y) & ~(x & ~y)) ;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  // Tmin is the number 1 in the MSB and all zeros.
  // And int has size 4 bites, so 32 bits. This number should be one 1 
  // followed by 31 zeros
  int result = 1 << 31;
  return result;
  // return 2;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 2
 */
int isTmax(int x) {
  // Tmax is 0 followed by 31 ones, so I need to build Tmax
  // and compare using XOR. When everything is equal, I got 0.


  // First let's build tmax (01...1)
  int first_byte  = 0x7f;
  int second_byte = (first_byte  << 8) | 0xff;
  int third_byte  = (second_byte << 8) | 0xff;
  int tmax        = (third_byte  << 8) | 0xff;

  // Let's compare the two numbers. We will get all 0's if they are equal
  int comparison  = tmax^x;
    
  return !comparison;
  // return 2;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  // I need to check every odd number is set. I can do that by
  // masking.

  // int first_byte  = 0xAA;
  // int second_byte = (first_byte  << 8) | 0xAA;
  // int third_byte  = (second_byte << 8) | 0xAA;
  // int all_bytes   = (third_byte  << 8) | 0xAA;

  int first_mask  = 0xAA;
  int second_mask = (first_mask  << 8) | 0xAA;
  int third_mask  = (second_mask << 8) | 0xAA;
  int mask        = (third_mask  << 8) | 0xAA;

  int comparison = mask^(x & mask);
  return !comparison;
  // return 2;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  // As per definition, we need to invert and sum 1
  int result = ~x;
  result += 1;
  return result;
  // return 2;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  // I compare the upper part of the number. If it is Ascii digit
  // it must be in the range 30 to 39, so everything above must be
  // 0 and the second digit must be 3. The first digit should be 
  // between 0 and 9.

  int base = x >> 8;
  int comparison = base^0x00;
  base = base >> 8;
  comparison = comparison | (base^0x00);
  base = base >> 8;
  comparison = comparison | (base^0x00);   
  comparison = !comparison;
   

  int first_half = 0xf0 & x;
  int first_comparison = !(first_half^0x30);

  int second_half = 0xF & x;
  int second_comparison = !(0x0^second_half) | !(0x1^second_half) |
                          !(0x2^second_half) | !(0x3^second_half) |
                          !(0x4^second_half) | !(0x5^second_half) |
                          !(0x6^second_half) | !(0x7^second_half) |
                          !(0x8^second_half) | !(0x9^second_half);

  // int second_comparison_2 = !(0xA^second_half) | !(0xB^second_half) |
  //                           !(0xC^second_half) | !(0xD^second_half) |
  //                           !(0xE^second_half) | !(0xF^second_half);
  // second_comparison_2 = !second_comparison_2;
  return first_comparison & second_comparison & comparison;   
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // This relies on the fact that either x or ~x will be true.
  // In this case the OR will produce only one of the results.
  x = !!x;
  x = x << 31;
  x = x >> 31;

  return (x & y) | (~x & z);
  // return 2;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // I check if x and y are positive or negative
  // I can calculate if the number is less or equal by checking
  // if the difference is either positive or negative and
  // depending on the value of x and y, infer their sign based on 
  // the result's sign

  int x_neg = (x >> 31) & 0x1; int x_pos = !((x >> 31) & 0x1);
  
  int y_neg = (y >> 31) & 0x1; int y_pos = !((y >> 31) & 0x1);

  // int sum = x + y;
  // int sum_neg = (sum >> 31) & (0x1); int sum_pos = !((sum >> 31) & (0x1));
  // int overflows = (x_pos & y_pos & sum_neg) | (x_neg & y_neg & sum_pos );
   
  int dif_pos = y + (~x + 1);  int dif_neg = (~x + 1) + y;
  int dif_pos_bigger_or_equal_zero = !((dif_pos >> 31) & 0x01);
  int dif_neg_lesser_or_equal_zero = !((dif_neg >> 31) & 0x01);

  
  int TMAX = 0x7FFFFFFF;
  // int TMIN = ~TMAX;
  
  int x_is_TMIN = !(x + TMAX + 1);
  int y_is_TMIN = !(y + TMAX + 1);

  // printf("\n");
  // printf("y inverted: %x\n", (~y + 1));
  // printf("y inverted + x: %x or %d\n", (~y + 1) + x, (~y + 1) + x);
  // printf("dif_neg? %x\n", dif_neg);
  // printf("dif_neg_lesser_or_equal_zero? %x\n", dif_neg_lesser_or_equal_zero);

  int result = x_is_TMIN |
              (x_is_TMIN & y_is_TMIN) |
              (x_neg & y_pos) |            
              (x_pos & y_pos & dif_pos_bigger_or_equal_zero) |
              (x_neg & y_neg & dif_neg_lesser_or_equal_zero)
               ;

  return result;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  // I progressively compute the OR among the bits
  // if everything is zero, I will get zero

  int acc = x;
  acc = acc | (x >> 8);
  acc = acc | (x >> 16);
  acc = acc | (x >> 24);
  
  acc = acc | (acc >> 4);
  acc = acc | (acc >> 2);
  acc = acc | (acc >> 1);

  int mask = 0x00;
  mask = 0x00 << 24;
  mask += 1;

  acc = mask & acc;

  // Change negate to two's complement
  return 1 + negate(acc);
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  
  return 2;
}
//float
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
    unsigned sign = uf >> 31;
    unsigned exp = (uf >> 23) & 0xFF;
    unsigned frac = uf & 0x7FFFFF;
    unsigned inf = 0x7f800000; 
    unsigned minus_inf = 0xff800000; 

    // Special cases (NaN and Infinity)
    if (exp == 0xFF) return uf;        

    // Denormalized zero
    if (exp == 0 && frac == 0)  return uf;

    // Denormalized
    if (exp == 0 && frac != 0) {
        int hasOverflow = (frac >> 22) & 0x1;
        if (hasOverflow) {
            return (sign << 31) | ((exp << 23) & 0x1) | (frac << 1);
        }
        else {
            return (sign << 31) | ((exp << 23) & 0x1) | (frac << 1);
        }
    }

    // Normalized case
    exp = (exp + 1) & 0xFF;
    if (exp == 0xFF) {
        if (sign)
            return minus_inf;
        else
            return inf;
    }

    return (sign << 31) | (exp << 23) | frac;         
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
#include <stdio.h>

unsigned float_i2f(int x) {
  if (x == 0) return 0;                     // Case 0
  if (x == (1 << 31)) return 0xCF000000;    // Case infinity
  
  unsigned sign, exp, frac, significand;
  unsigned mask;
  int msb;

  sign = (x >> 31) & 0x1;
  if (sign)          // negative number   
    x = -x;        // IEEE 754 floating point does not use two's complement     

  msb = 32;           // first set bit from left to right
  while (msb--) if ((x >> msb) & 0x1) break;  

  mask = (1 << (msb + 1)) - 1;

  significand = x & mask;

  exp = 127 + msb;
  

  if (msb < 23)        // number must be pushed to the left until it gets to position
  {
    frac = (significand << (23 - msb)) & 0x7FFFFF  ;    // frac should have 23 bits 
  } 
  else                  // Now we're dealing with end > 23
  {

    // Isso constrói frac, mas não permite analisar o final de x
    // frac = (significand >> (msb - 23)) & 0x7FFFFF; 

    // Essa solução não é minha
    // O que foi feito foi levar os bits para a esquerda e em seguida
    // analisar os bits finais que serão a diferença entre 31 e 23 bits (8)
    // que serão responsáveis pelo arredondamento
    x = x << (31 - msb);         
    frac = (x >> 8) & 0x7FFFFF;  

    int tailb = x & 0xFF; 
    
    // Se a parte final do número for maior que 128, arredonda para cima
    // se o bit 128 está ativo e o último bit da fração é 1, arredonda para cima
    if ((tailb > 128) || ((tailb == 128) && (frac & 1))) {
      frac += 1;
          if (frac >> 23) {
            exp += 1;
            frac = 0;
            } 
    }
  }
  return (sign << 31) | (exp << 23) | frac;
}

/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  unsigned sign = (uf >> 31) & 0x1;
  unsigned exp  = (uf >> 23) & 0xFF;
  unsigned frac = uf & 0x7FFFFF;

  const unsigned MAX_INT = 0x7FFFFFFF;
  const unsigned MIN_INT = 0x80000000;

  // Number of form 0.xyz...
  if (exp == 0) return 0;
  
  
  if (exp == 0xFF) {
    if (frac != 0) // NaN
      return 0;
    else {             // infinity
      if (sign) // negative
        return MIN_INT;
      else 
        return MAX_INT;
    }
  }

  // There is a problem when comparing signed and unsigned.
  // exp - 127 > 31 does not work.
  // Numbers that are bigger than an integer can represent
  if (exp > 31 + 127) {  
    if (sign)
      return 0x80000000;
    else
      return 0x7fffffff;  
  }

  int big_e = exp - 127;

  // Calculating 2^E
  int power_of_2 = 1;
  if (big_e > 0)
    power_of_2 <<= big_e;
  else
    power_of_2 >>= big_e;

  if ((power_of_2 != 0u) && ((frac << power_of_2) > 4194304))
    power_of_2 += 1;

  
  if (sign)
    return -power_of_2;
  return power_of_2;

}
