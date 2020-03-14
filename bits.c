/* TODO: 最后一题待做
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
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {

  return ~(~x|~y) ;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
	int m;
    m = x>>(n<<3); 
    m = m& 0xff;
  




  return m;

}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
	
  x = x>>n;
	int mask = ((~(1<<31)>>n)<<1)|1;
  return mask & x;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  // int m = 0;
	// while (x!=0)
  // {
  //   x = x&(x-1);
  //   m++;
  // }
  // return m;
//在笔记位运算的分治法中有写。
  int mask1 = 0x55 | (0x55 << 8);//ox5555 下面等同
  int mask2 = 0x33 | (0x33 << 8);
  int mask3 = 0xf | (0xf << 8);//0x0f0f
  int mask4 = 0xff | (0xff << 16);//0x00ff00ff
  int mask5 = 0xff | (0xff << 8);//0x0000ffff
  int count;
  mask1 = mask1 | (mask1 << 16);//0x5555 5555
  mask2 = mask2 | (mask2 << 16);//0x3333 3333
  mask3 = mask3 | (mask3 << 16);//0x0f0f 0f0f
  count = (x & mask1) +((x >> 1) & mask1); //记录两个一组的1个数。count中的每两位记录该组数量。
  count = (count & mask2) + ((count >> 2) &mask2);//四位为一组，组内每两位相加，记录四位一组中的1的数量
  count = (count & mask3) + ((count >> 4) & mask3);
  count = (count & mask4) + ((count >> 8) & mask4);
  count = (count & mask5) + ((count >> 16) & mask5);
  return count;

}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  int t=(~x)+1;                       //求相反数
  int flag=~((x|t)>>31)&0x01;         //相反数和自身相或保留符号位
  return flag;
  return 2;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 1<<31;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  int tmp = x>>(n+~(0));
  return (!tmp | !(tmp+1));
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  if(x>= 0)
    return x>>n;
  else
    return (x+(1<<n)-1)>>n;

}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 * ispos(x)
 */
int isPositive(int x) {
  
  // int flag = (~x+1)>>31; //有溢出风险
  // return (flag&1);
  
  int flagp =(x>>31)&1;// 负为1，正为0
  int flag0 = !x; //0位0，非0为1
  return !flagp & !flag0;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    int signx=(x>>31)&1;//x的符号位 
  	int signy=(y>>31)&1;//y的符号位 
  	int signy_x=((y+~x+1)>>31)&1;//y-x的符号位  考虑溢出 只有x-y存在。
  	return (!(signx^signy)&!signy_x) | ((signx^signy)&signx);

}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  // int num = 0;
  // while(x!= 0)
  // {
  //   x= x<<1;
  //   num++;
  // }
  // return num;
  //找最高位1的位数。都是正数。先找是否在前16位中，如果在，则为1，如果不在则为0。记录在第四位
  //以第四位的记录找是否在前/后16的前8位与否。 在，则为，不在为0，记录在第三位。
  //tmp可移植指示范围。最开始是0，分前16后16.第四位指示后，tmp+8就是 11000=24或者01000=8. 后续在细分
    int tmp;
    tmp = (!!(x >> 16)) << 4;
    tmp = tmp + ((!!(x >> (tmp + 8))) << 3);
    tmp = tmp + ((!!(x >> (tmp + 4))) << 2);
    tmp = tmp + ((!!(x >> (tmp + 2))) << 1);
    tmp = tmp + ((!!(x >> (tmp + 1))) << 0); 
    return tmp;

}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2 
 *   返回无符号数的float的负值。虽然返回的是unsigned，但是按照float的格式
 */
unsigned float_neg(unsigned uf) {



  int flag1 = ((uf>>23)& 0xff)^0xff; //取高9位，并用0xff取其中低8位，判断是否为全1
  int flag2 = uf & ((1<<23)-1);     //取后22位。判断是否为0
  //return flag1;
  if (!flag1 && flag2)
    return uf;
  else
    return uf ^= (1<<31);
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
unsigned float_i2f(int x) {

// there is a method in csapp page 82
    unsigned s = x & (1 << 31);
    int pos = 30;
    int frac_mask = (1 << 23) - 1;
    int frac, exp;
    int delta;
    //处理两个特殊值 0 和 -TMIN  -TMIN的负数是本身，作为特殊值处理。
    if (!x) {
        return x;
    }
    if (x == 0x80000000) {
        return 0xcf000000;
    }
    //将负数变为正数，原码表示
    if (x < 0) {
        x = -x;
    }
    while (!(x >> pos)) {
        pos--;
    }
    exp = pos + 127;

    x = x << (31 - pos);//pos最高位的位数（出开sign），将x右移，最高位占据sign位
    frac = (x >> 8) & frac_mask; //将低的1-22位提出来。
    x = x & 0xff;//提取出最低的8位
    delta = (x > 128) || ((x == 128) && (frac & 1));//如果大于128（255=0xff的一半），或者=128且为奇数（末位为0），则向上舍入
    frac += delta; 
    // if (frac >> 23) {//如果舍入后，进位，则exp需要加1，并消掉 这里根本不需要。
    //     frac = frac & frac_mask;
    //     exp++;
    // }
    return s + (exp << 23) + frac; 

}
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
  return 2;
}
