#ifndef __QUATERNION_OPERATIONS_H__
#define __QUATERNION_OPERATIONS_H__

#include "quaternion.h"
#include <cmath>
#include <stdio.h>

namespace QuatLib
{
    template<typename _T>
    CQuaternion<_T>::CQuaternion()
    {
        m_arfQ[0U] = static_cast<_T>(0.0);
        m_arfQ[1U] = static_cast<_T>(0.0);
        m_arfQ[2U] = static_cast<_T>(0.0);
        m_arfQ[3U] = static_cast<_T>(0.0);
    }

    template<typename _T>
    CQuaternion<_T>::CQuaternion(const _T (&arfVal)[4U])
    {
        m_arfQ[0U] = arfVal[0U];
        m_arfQ[1U] = arfVal[1U];
        m_arfQ[2U] = arfVal[2U];
        m_arfQ[3U] = arfVal[3U];
    }

    template<typename _T>
    CQuaternion<_T>::CQuaternion(const CQuaternion<_T>& op)
    {
        m_arfQ[0U] = op.m_arfQ[0U];
        m_arfQ[1U] = op.m_arfQ[1U];
        m_arfQ[2U] = op.m_arfQ[2U];
        m_arfQ[3U] = op.m_arfQ[3U];
    }

    template<typename _T>
    CQuaternion<_T>::CQuaternion(const CQuaternion<_T>&& op)
    {
        m_arfQ[0U] = op.m_arfQ[0U];
        m_arfQ[1U] = op.m_arfQ[1U];
        m_arfQ[2U] = op.m_arfQ[2U];
        m_arfQ[3U] = op.m_arfQ[3U];
    }

    template<typename _T>
    _T& CQuaternion<_T>::operator()(const uint32_t u32Idx)
    {
        return m_arfQ[u32Idx];
    }

    template<typename _T>
    const _T& CQuaternion<_T>::operator()(const uint32_t u32Idx) const
    {
        return m_arfQ[u32Idx];
    }

    template<typename _T>
    CQuaternion<_T> CQuaternion<_T>::operator=(const CQuaternion<_T>& op)
    {
        m_arfQ[0U] = op.m_arfQ[0U];
        m_arfQ[1U] = op.m_arfQ[1U];
        m_arfQ[2U] = op.m_arfQ[2U];
        m_arfQ[3U] = op.m_arfQ[3U];
        return *this;
    }

    template<typename _T>
    CQuaternion<_T> CQuaternion<_T>::operator=(const CQuaternion<_T>&& op)
    {
        m_arfQ[0U] = op.m_arfQ[0U];
        m_arfQ[1U] = op.m_arfQ[1U];
        m_arfQ[2U] = op.m_arfQ[2U];
        m_arfQ[3U] = op.m_arfQ[3U];
        return *this;
    }

    template<typename _T>
    CQuaternion<_T> CQuaternion<_T>::operator+(const CQuaternion<_T>& op) const
    {
        CQuaternion<_T> oY;
        oY.m_arfQ[0U] = m_arfQ[0U] + op.m_arfQ[0U];
        oY.m_arfQ[1U] = m_arfQ[1U] + op.m_arfQ[1U];
        oY.m_arfQ[2U] = m_arfQ[2U] + op.m_arfQ[2U];
        oY.m_arfQ[3U] = m_arfQ[3U] + op.m_arfQ[3U];
        return oY;
    }

    template<typename _T>
    CQuaternion<_T> CQuaternion<_T>::operator-(const CQuaternion<_T>& op) const
    {
        CQuaternion<_T> oY;
        oY.m_arfQ[0U] = m_arfQ[0U] - op.m_arfQ[0U];
        oY.m_arfQ[1U] = m_arfQ[1U] - op.m_arfQ[1U];
        oY.m_arfQ[2U] = m_arfQ[2U] - op.m_arfQ[2U];
        oY.m_arfQ[3U] = m_arfQ[3U] - op.m_arfQ[3U];
        return oY;
    }

    template<typename _T>
    CQuaternion<_T> CQuaternion<_T>::operator*(const CQuaternion<_T>& op) const
    {
        const _T fa1 = m_arfQ[0U];
        const _T fb1 = m_arfQ[1U];
        const _T fc1 = m_arfQ[2U];
        const _T fd1 = m_arfQ[3U];

        const _T fa2 = op.m_arfQ[0U];
        const _T fb2 = op.m_arfQ[1U];
        const _T fc2 = op.m_arfQ[2U];
        const _T fd2 = op.m_arfQ[3U];

        const _T fa3 = (fa1*fa2) - (fb1*fb2) - (fc1*fc2) - (fd1*fd2);  // real
        const _T fb3 = (fa1*fb2) + (fb1*fa2) + (fc1*fd2) - (fd1*fc2);  // i
        const _T fc3 = (fa1*fc2) - (fb1*fd2) + (fc1*fa2) + (fd1*fb2);  // j
        const _T fd3 = (fa1*fd2) + (fb1*fc2) - (fc1*fb2) + (fd1*fa2);  // k

        CQuaternion<_T> oY;
        oY.m_arfQ[0U] = fa3;
        oY.m_arfQ[1U] = fb3;
        oY.m_arfQ[2U] = fc3;
        oY.m_arfQ[3U] = fd3;

        return oY;
    }

    template<typename _T>
    CQuaternion<_T> CQuaternion<_T>::Conjugate() const
    {
        CQuaternion<_T> oY;
        oY.m_arfQ[0U] = m_arfQ[0U];
        oY.m_arfQ[1U] = -m_arfQ[1U];
        oY.m_arfQ[2U] = -m_arfQ[2U];
        oY.m_arfQ[3U] = -m_arfQ[3U];
        return oY;
    }

    template<typename _T>
    _T CQuaternion<_T>::Norm() const
    {
        const _T fa = m_arfQ[0U];
        const _T fb = m_arfQ[1U];
        const _T fc = m_arfQ[2U];
        const _T fd = m_arfQ[3U];
        const _T fSqrNorm = (fa*fa) + (fb*fb) + (fc*fc) + (fd*fd);
        return static_cast<_T>(sqrtf(static_cast<float32_t>(fSqrNorm)));
    }

    template<typename _T>
    CQuaternion<_T> CQuaternion<_T>::Invert() const
    {
        const _T fa = m_arfQ[0U];
        const _T fb = m_arfQ[1U];
        const _T fc = m_arfQ[2U];
        const _T fd = m_arfQ[3U];
        const _T fInvSqrNorm = static_cast<_T>(1.0) / ((fa*fa) + (fb*fb) + (fc*fc) + (fd*fd));

        CQuaternion<_T> oY;
        oY.m_arfQ[0U] =  m_arfQ[0U] * fInvSqrNorm;
        oY.m_arfQ[1U] = -m_arfQ[1U] * fInvSqrNorm;
        oY.m_arfQ[2U] = -m_arfQ[2U] * fInvSqrNorm;
        oY.m_arfQ[3U] = -m_arfQ[3U] * fInvSqrNorm;

        return oY;
    }


    template<typename _T>
    CQuaternion<_T> CQuaternion<_T>::Rotate(const CQuaternion<_T>& oQr) const
    {
        CQuaternion<_T> oY;

        const float32_t f32x = m_arfQ[1];
        const float32_t f32y = m_arfQ[2];
        const float32_t f32z = m_arfQ[3];

        const float32_t f32qr = oQr.m_arfQ[0];
        const float32_t f32qx = oQr.m_arfQ[1];
        const float32_t f32qy = oQr.m_arfQ[2];
        const float32_t f32qz = oQr.m_arfQ[3];

        const float32_t f32r00 = static_cast<_T>(1.0) - static_cast<_T>(2.0)*((f32qy*f32qy) + (f32qz*f32qz));
        const float32_t f32r01 = static_cast<_T>(2.0)*((f32qx*f32qy) - (f32qr*f32qz));
        const float32_t f32r02 = static_cast<_T>(2.0)*((f32qr*f32qy) + (f32qx*f32qz));

        const float32_t f32r10 = static_cast<_T>(2.0)*((f32qx*f32qy) + (f32qr*f32qz));
        const float32_t f32r11 = static_cast<_T>(1.0) - static_cast<_T>(2.0)*((f32qx*f32qx) + (f32qz*f32qz));
        const float32_t f32r12 = static_cast<_T>(2.0)*((f32qy*f32qz) - (f32qr*f32qx));

        const float32_t f32r20 = static_cast<_T>(2.0)*((f32qx*f32qz) - (f32qr*f32qy));
        const float32_t f32r21 = static_cast<_T>(2.0)*((f32qr*f32qx) + (f32qy*f32qz));
        const float32_t f32r22 = static_cast<_T>(1.0) - static_cast<_T>(2.0)*((f32qx*f32qx) + (f32qy*f32qy));

        oY.m_arfQ[0] = static_cast<_T>(0.0);
        oY.m_arfQ[1] = (f32r00*f32x) + (f32r01*f32y) + (f32r02*f32z);
        oY.m_arfQ[2] = (f32r10*f32x) + (f32r11*f32y) + (f32r12*f32z);
        oY.m_arfQ[3] = (f32r20*f32x) + (f32r21*f32y) + (f32r22*f32z);


        return oY;
    }

    template<typename _T>
    void CQuaternion<_T>::ToEulerAngles(_T (&arfAngles)[3U]) const
    {
        const float32_t fq0 = static_cast<float32_t>(m_arfQ[0]);
        const float32_t fq1 = static_cast<float32_t>(m_arfQ[1]);
        const float32_t fq2 = static_cast<float32_t>(m_arfQ[2]);
        const float32_t fq3 = static_cast<float32_t>(m_arfQ[3]);

        const float32_t fRoll  = atan2f(2.0F*((fq0*fq1) + (fq2*fq3)), 1.0F - 2.0F*((fq1*fq1) + (fq2*fq2)));
        const float32_t fPitch =  asinf(2.0F*((fq0*fq2) - (fq3*fq1)));
        const float32_t fYaw   = atan2f(2.0F*((fq0*fq3) + (fq1*fq2)), 1.0F - 2.0F*((fq2*fq2) + (fq3*fq3)));

        arfAngles[0] = static_cast<_T>(fRoll);
        arfAngles[1] = static_cast<_T>(fPitch);
        arfAngles[2] = static_cast<_T>(fYaw);
    }

    template<typename _T>
    CQuaternion<_T> CQuaternion<_T>::ToQuaternion(const _T (arfAngles)[3U])
    {
        const float32_t f32Roll  = static_cast<float32_t>(arfAngles[0]);
        const float32_t f32Pitch = static_cast<float32_t>(arfAngles[1]);
        const float32_t f32Yaw   = static_cast<float32_t>(arfAngles[2]);

        const float32_t f32C_roll  = cosf(f32Roll * 0.5);
        const float32_t f32C_pitch = cosf(f32Pitch * 0.5);
        const float32_t f32C_yaw   = cosf(f32Yaw * 0.5);

        const float32_t f32S_roll  = sinf(f32Roll * 0.5);
        const float32_t f32S_pitch = sinf(f32Pitch * 0.5);
        const float32_t f32S_yaw   = sinf(f32Yaw * 0.5);

        const float32_t fq0 = ((f32C_roll*f32C_pitch)*f32C_yaw) + ((f32S_roll*f32S_pitch)*f32S_yaw);
        const float32_t fq1 = ((f32S_roll*f32C_pitch)*f32C_yaw) - ((f32C_roll*f32S_pitch)*f32S_yaw);
        const float32_t fq2 = ((f32C_roll*f32S_pitch)*f32C_yaw) + ((f32S_roll*f32C_pitch)*f32S_yaw);
        const float32_t fq3 = ((f32C_roll*f32C_pitch)*f32S_yaw) - ((f32S_roll*f32S_pitch)*f32C_yaw);

        m_arfQ[0] = static_cast<_T>(fq0);
        m_arfQ[1] = static_cast<_T>(fq1);
        m_arfQ[2] = static_cast<_T>(fq2);
        m_arfQ[3] = static_cast<_T>(fq3);
        return (*this);
    }

    template<typename _T>
    void CQuaternion<_T>::ToRotationMatrix(_T (&arfRotation)[9U]) const
    {
        const float32_t f32qr = static_cast<float32_t>(m_arfQ[0]);
        const float32_t f32qx = static_cast<float32_t>(m_arfQ[1]);
        const float32_t f32qy = static_cast<float32_t>(m_arfQ[2]);
        const float32_t f32qz = static_cast<float32_t>(m_arfQ[3]);

        const float32_t f32r0 = 1.0F - 2.0F*(f32qy*f32qy + f32qz*f32qz);
        const float32_t f32r1 = 2.0F*(f32qx*f32qy - f32qr*f32qz);
        const float32_t f32r2 = 2.0F*(f32qr*f32qy + f32qx*f32qz);

        const float32_t f32r3 = 2.0F*(f32qx*f32qy + f32qr*f32qz);
        const float32_t f32r4 = 1.0F - 2.0F*(f32qx*f32qx + f32qz*f32qz);
        const float32_t f32r5 = 2.0F*(f32qy*f32qz - f32qr*f32qx);

        const float32_t f32r6 = 2.0F*(f32qx*f32qz - f32qr*f32qy);
        const float32_t f32r7 = 2.0F*(f32qr*f32qx + f32qy*f32qz);
        const float32_t f32r8 = 1.0F - 2.0F*(f32qx*f32qx + f32qy*f32qy);

        arfRotation[0] = f32r0;
        arfRotation[1] = f32r1;
        arfRotation[2] = f32r2;
        
        arfRotation[3] = f32r3;
        arfRotation[4] = f32r4;
        arfRotation[5] = f32r5;

        arfRotation[6] = f32r6;
        arfRotation[7] = f32r7;
        arfRotation[8] = f32r8;
    }

    template<typename _T>
    void CQuaternion<_T>::Print()
    {
        printf("%f + %fi + %fj + %fk\n", m_arfQ[0], m_arfQ[1], m_arfQ[2], m_arfQ[3]);
    }
}


#endif  // __QUATERNION_OPERATIONS_H__


