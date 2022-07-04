/**
 * @file ut_quaternion.cpp
 * @brief Unit test using googletest (https://github.com/google/googletest)
 * @author Jongmin Park
*/

#include "gtest/gtest.h"
#include "quaternion.h"

using QuatLib::CQuaternion;

class TestQuaternion : public ::testing::Test
{
protected:
    void SetUp()
    {

    }

    void TearDown()
    {

    }
    
};


TEST_F(TestQuaternion, Constructor)
{
    float32_t arf32q[4U] = {1.0F, 2.0F, 3.0F, 4.0F};
    CQuaternion<float32_t> q1(arf32q);

    EXPECT_EQ(q1(0), arf32q[0]);
    EXPECT_EQ(q1(1), arf32q[1]);
    EXPECT_EQ(q1(2), arf32q[2]);
    EXPECT_EQ(q1(3), arf32q[3]);
}

TEST_F(TestQuaternion, Add)
{
    float32_t arf32q1[4U] = {1.0F, 2.0F, 3.0F, 4.0F};
    float32_t arf32q2[4U] = {3.0F, 4.0F, 5.0F, 6.0F};

    CQuaternion<float32_t> q1(arf32q1);
    CQuaternion<float32_t> q2(arf32q2);

    CQuaternion<float32_t> q3 = q1 + q2;

    for(uint32_t u32I = 0U; u32I < 4U; u32I++){
        EXPECT_FLOAT_EQ(q3(u32I), arf32q1[u32I] + arf32q2[u32I]);
    }
}

TEST_F(TestQuaternion, Sub)
{
    float32_t arf32q1[4U] = {1.0F, 2.0F, 3.0F, 4.0F};
    float32_t arf32q2[4U] = {3.0F, 4.0F, 5.0F, 6.0F};

    CQuaternion<float32_t> q1(arf32q1);
    CQuaternion<float32_t> q2(arf32q2);

    CQuaternion<float32_t> q3 = q1 - q2;

    for(uint32_t u32I = 0U; u32I < 4U; u32I++){
        EXPECT_FLOAT_EQ(q3(u32I), arf32q1[u32I] - arf32q2[u32I]);
    }
}

TEST_F(TestQuaternion, Mul)
{
    float32_t arf32q1[4U] = {1.0F, 2.0F, 3.0F, 4.0F};       // 1 + 2i + 3j + 4k
    float32_t arf32q2[4U] = {3.0F, 4.0F, 5.0F, 6.0F};       // 3 + 4i + 5j + 6k

    const float32_t fa1 = 1.0F;
    const float32_t fb1 = 2.0F;
    const float32_t fc1 = 3.0F;
    const float32_t fd1 = 4.0F;

    const float32_t fa2 = 3.0F;
    const float32_t fb2 = 4.0F;
    const float32_t fc2 = 5.0F;
    const float32_t fd2 = 6.0F;

    const float32_t fa3 = (fa1*fa2) - (fb1*fb2) - (fc1*fc2) - (fd1*fd2);  // real
    const float32_t fb3 = (fa1*fb2) + (fb1*fa2) + (fc1*fd2) - (fd1*fc2);  // i
    const float32_t fc3 = (fa1*fc2) - (fb1*fd2) + (fc1*fa2) + (fd1*fb2);  // j
    const float32_t fd3 = (fa1*fd2) + (fb1*fc2) - (fc1*fb2) + (fd1*fa2);  // k


    CQuaternion<float32_t> q1(arf32q1);
    CQuaternion<float32_t> q2(arf32q2);

    CQuaternion<float32_t> q3 = q1 * q2;

    EXPECT_FLOAT_EQ(q3(0), fa3);
    EXPECT_FLOAT_EQ(q3(1), fb3);
    EXPECT_FLOAT_EQ(q3(2), fc3);
    EXPECT_FLOAT_EQ(q3(3), fd3);    
}


TEST_F(TestQuaternion, Conjugate)
{
    float32_t arf32q1[4U] = {1.0F, 2.0F, 3.0F, 4.0F};       // 1 + 2i + 3j + 4k    
    CQuaternion<float32_t> q1(arf32q1);
    CQuaternion<float32_t> q3 = q1 * q1.Conjugate();

    // 1 + 4 + 9 + 16 = 30
    EXPECT_NEAR(q3(0), 30.0F, 1e-6);
    EXPECT_NEAR(q3(1), 0.0F, 1e-6);
    EXPECT_NEAR(q3(2), 0.0F, 1e-6);
    EXPECT_NEAR(q3(3), 0.0F, 1e-6);

    q3.Print();
}

TEST_F(TestQuaternion, Invert)
{
    float32_t arf32q1[4U] = {1.0F, 2.0F, 3.0F, 4.0F};       // 1 + 2i + 3j + 4k

    CQuaternion<float32_t> q1(arf32q1);

    CQuaternion<float32_t> q3 = q1 * q1.Invert();

    EXPECT_NEAR(q3(0), 1.0F, 1e-6);
    EXPECT_NEAR(q3(1), 0.0F, 1e-6);
    EXPECT_NEAR(q3(2), 0.0F, 1e-6);
    EXPECT_NEAR(q3(3), 0.0F, 1e-6);

    q3.Print();
}

TEST_F(TestQuaternion, Rotation)
{
    CQuaternion<float32_t> qr;
    const float32_t arf32EulerAngles[3U] = {
        3.14F / 3.0F,
        3.14F / 4.0F,
        3.14F / 6.0F
    };
    qr.ToQuaternion(arf32EulerAngles);
    qr.Print();
    
    float32_t arf32ConvAngles[3U];
    qr.ToEulerAngles(arf32ConvAngles);

    EXPECT_NEAR(arf32ConvAngles[0], arf32EulerAngles[0], 1e-6);
    EXPECT_NEAR(arf32ConvAngles[1], arf32EulerAngles[1], 1e-6);
    EXPECT_NEAR(arf32ConvAngles[2], arf32EulerAngles[2], 1e-6);
}

