#ifndef __QUATERNION_BASE_H__
#define __QUATERNION_BASE_H__

#include "typedef.h"

namespace QuatLib
{
    template<typename _T>
    class CQuaternion
    {
    public:
        CQuaternion();
        CQuaternion(const _T (&arfVal)[4U]);

        inline _T& operator[](const uint32_t u32Idx);
        inline const _T& operator[](const uint32_t u32Idx) const;

        CQuaternion operator+(const CQuaternion<_T>& op) const;
        CQuaternion operator-(const CQuaternion<_T>& op) const;
        CQuaternion operator*(const CQuaternion<_T>& op) const;
        
        CQuaternion Conjugate() const;
        CQuaternion rotate(const CQuaternion<_T>& op) const;


    private:
        static const uint32_t m_u32N = 4U;
        _T m_arfQuaternion[m_u32N];
    };

}

#endif      // __QUATERNION_BASE_H__
