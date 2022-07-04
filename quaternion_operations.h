#ifndef __QUATERNION_OPERATIONS_H__
#define __QUATERNION_OPERATIONS_H__

#include "quaternion.h"

namespace QuatLib
{
    template<typename _T>
    CQuaternion<_T>::CQuaternion()
    {
        m_arfQuaternion[0U] = static_cast<_T>(0.0);
        m_arfQuaternion[1U] = static_cast<_T>(0.0);
        m_arfQuaternion[2U] = static_cast<_T>(0.0);
        m_arfQuaternion[3U] = static_cast<_T>(0.0);
    }

    template<typename _T>
    CQuaternion<_T>::CQuaternion(const _T (&arfVal)[4U])
    {
        m_arfQuaternion[0U] = arfVal[0U];
        m_arfQuaternion[1U] = arfVal[1U];
        m_arfQuaternion[2U] = arfVal[2U];
        m_arfQuaternion[3U] = arfVal[3U];
    }

    template<typename _T>
    _T& CQuaternion<_T>::operator[](const uint32_t u32Idx)
    {
        return m_arfQuaternion[u32Idx];
    }

    template<typename _T>
    const _T& CQuaternion<_T>::operator[](const uint32_t u32Idx) const
    {
        return m_arfQuaternion[u32Idx];
    }

    template<typename _T>
    CQuaternion<_T> CQuaternion<_T>::operator+(const CQuaternion<_T>& op) const
    {
        CQuaternion<_T> oY;
        oY.m_arfQuaternion[0U] = m_arfQuaternion[0U] + op.m_arfQuaternion[0U];
        oY.m_arfQuaternion[1U] = m_arfQuaternion[1U] + op.m_arfQuaternion[1U];
        oY.m_arfQuaternion[2U] = m_arfQuaternion[2U] + op.m_arfQuaternion[2U];
        oY.m_arfQuaternion[3U] = m_arfQuaternion[3U] + op.m_arfQuaternion[3U];
        return oY;
    }

    template<typename _T>
    CQuaternion<_T> CQuaternion<_T>::operator-(const CQuaternion<_T>& op) const
    {
        CQuaternion<_T> oY;
        oY.m_arfQuaternion[0U] = m_arfQuaternion[0U] - op.m_arfQuaternion[0U];
        oY.m_arfQuaternion[1U] = m_arfQuaternion[1U] - op.m_arfQuaternion[1U];
        oY.m_arfQuaternion[2U] = m_arfQuaternion[2U] - op.m_arfQuaternion[2U];
        oY.m_arfQuaternion[3U] = m_arfQuaternion[3U] - op.m_arfQuaternion[3U];
        return oY;
    }

    template<typename _T>
    CQuaternion<_T> CQuaternion<_T>::operator*(const CQuaternion<_T>& op) const
    {
        const _T fa1 = m_arfQuaternion[0U];
        const _T fb1 = m_arfQuaternion[1U];
        const _T fc1 = m_arfQuaternion[2U];
        const _T fd1 = m_arfQuaternion[3U];

        const _T fa2 = op.m_arfQuaternion[0U];
        const _T fb2 = op.m_arfQuaternion[1U];
        const _T fc2 = op.m_arfQuaternion[2U];
        const _T fd2 = op.m_arfQuaternion[3U];

        const _T fa3 = (fa1*fa2) - (fb1*fb2) - (fc1*fc2) - (fd1*fd2);  // real
        const _T fb3 = (fa1*fb2) + (fb1*fa2) + (fc1*fd2) - (fd1*fc2);  // i
        const _T fc3 = (fa1*fc2) - (fb1*fd2) + (fc1*fa2) + (fd1*fb2);  // j
        const _T fd3 = (fa1*fd2) + (fb1*fc2) - (fc1*fb2) + (fd1*fa2);  // k

        CQuaternion<_T> oY;
        oY.m_arfQuaternion[0U] = fa3;
        oY.m_arfQuaternion[1U] = fb3;
        oY.m_arfQuaternion[2U] = fc3;
        oY.m_arfQuaternion[3U] = fd3;

        return oY;
    }

    template<typename _T>
    CQuaternion<_T> CQuaternion<_T>::Conjugate() const
    {
        CQuaternion<_T> oY;
        oY.m_arfQuaternion[0U] = m_arfQuaternion[0U];
        oY.m_arfQuaternion[1U] = -m_arfQuaternion[1U];
        oY.m_arfQuaternion[2U] = -m_arfQuaternion[2U];
        oY.m_arfQuaternion[3U] = -m_arfQuaternion[3U];
    }

    template<typename _T>
    CQuaternion<_T> CQuaternion<_T>::rotate(const CQuaternion<_T>& op) const
    {
        CQuaternion<_T> oY = op * (*this) * op.Conjugate();
        return oY;
    }
}


#endif  // __QUATERNION_OPERATIONS_H__


