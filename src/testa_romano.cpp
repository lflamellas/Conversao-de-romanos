#include "romano.hpp"
#include "gtest/gtest.h"
namespace {

TEST(RomantoArabic, ConvertBasicRoman) {
    EXPECT_EQ(roman_to_arabic("I"), 1);
    EXPECT_EQ(roman_to_arabic("V"), 5);
    EXPECT_EQ(roman_to_arabic("X"), 10);
    EXPECT_EQ(roman_to_arabic("L"), 50);
    EXPECT_EQ(roman_to_arabic("C"), 100);
    EXPECT_EQ(roman_to_arabic("D"), 500);
    EXPECT_EQ(roman_to_arabic("M"), 1000);
}

TEST(RomantoArabic, ConvertRoman) {
    EXPECT_EQ(roman_to_arabic("CCXIX"), 219);
    EXPECT_EQ(roman_to_arabic("CDXX"), 420);
    EXPECT_EQ(roman_to_arabic("DCCCXCIX"), 899);
    EXPECT_EQ(roman_to_arabic("MDCCXXXVII"), 1737);
    EXPECT_EQ(roman_to_arabic("CC"), 200);
    EXPECT_EQ(roman_to_arabic("LXXVIII"), 78);
    EXPECT_EQ(roman_to_arabic("MMM"), 3000);
}

TEST(ArabictoRoman, ConvertArabic) {
    EXPECT_TRUE(arabic_to_roman(333) == "CCCXXXIII");
    EXPECT_TRUE(arabic_to_roman(567) == "DLXVII");
    EXPECT_TRUE(arabic_to_roman(987) == "CMLXXXVII");
    EXPECT_TRUE(arabic_to_roman(2879) == "MMDCCCLXXIX");
    EXPECT_TRUE(arabic_to_roman(432) == "CDXXXII");
    EXPECT_TRUE(arabic_to_roman(63) == "LXIII");
    EXPECT_TRUE(arabic_to_roman(314) == "CCCXIV");
}

TEST(ValidateConvertArabic, CorrectCases) {
    EXPECT_EQ(validate_convert("CCXCVIII"), 298);
    EXPECT_EQ(validate_convert("CDXIII"), 413);
    EXPECT_EQ(validate_convert("DCCVI"), 706);
    EXPECT_EQ(validate_convert("DCCXXXIX"), 739);
    EXPECT_EQ(validate_convert("MCXCIV"), 1194);
    EXPECT_EQ(validate_convert("MMCCXCIII"), 2293);
    EXPECT_EQ(validate_convert("CXXIX"), 129);
}

TEST(ValidateConvertArabic, InvalidCases) {
    EXPECT_EQ(validate_convert("CCXCIVI"), -1);
    EXPECT_EQ(validate_convert("XXXX"), -1);
    EXPECT_EQ(validate_convert("MMMI"), -1);
    EXPECT_EQ(validate_convert("LL"), -1);
    EXPECT_EQ(validate_convert("XM"), -1);
    EXPECT_EQ(validate_convert("xiv"), -1);
    EXPECT_EQ(validate_convert("IIIIIIIIIIIIIIIIIIIIIIIIIIIIIII"), -1);
    EXPECT_EQ(validate_convert("ANA"), -1);
}

} // namespace