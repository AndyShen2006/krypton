#include "GMPWrapper.hpp"
#include "Utilities.hpp"
#include <gtest/gtest.h>
#include <string>

using namespace Krypton;

TEST(ByteArrayTest, HexTest)
{
    std::string s = "ab01934f8D2e0f";
    ByteArray buf = fromHex(s);
    ASSERT_EQ(static_cast<uint8_t>(buf[0]), 0xab);
    std::string res = toHex(buf);
    std::string ans = "AB01934F8D2E0F";
    ASSERT_EQ(res, ans);
}

TEST(ByteArrayTest, Base64Test1)
{
    std::string base64 = "WW9pbWl5YSE=";
    ByteArray buf = fromBase64(base64);
    ByteArray res = toBuffer("Yoimiya!");
    ASSERT_EQ(buf, res);
}

TEST(ByteArrayTest, Base64Test2)
{
    ByteArray plain = toBuffer("KamisatoAyaka");
    std::string res = "S2FtaXNhdG9BeWFrYQ==";
    ASSERT_EQ(toBase64(plain), res);
}

using GMPWrapper::BigInt;

TEST(ByteArrayTest, BigIntTest1)
{
    BigInt bint = "112233445566"_bix;
    auto ba = bint.toByteArray();
    ASSERT_EQ(toHex(ba), "665544332211");
}

TEST(ByteArrayTest, BigIntTest2)
{
    using Krypton::operator""_ba;
    auto ba = "665544332211"_ba;
    auto bint = BigInt(ba);
    ASSERT_EQ(bint.toString(16), "112233445566");
    ASSERT_EQ(bint, "112233445566"_bix);
}
