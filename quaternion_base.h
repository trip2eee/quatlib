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
        CQuaternion(const CQuaternion<_T>& op);
        CQuaternion(const CQuaternion<_T>&& op);

        inline _T& operator()(const uint32_t u32Idx);
        inline const _T& operator()(const uint32_t u32Idx) const;

        CQuaternion operator=(const CQuaternion<_T>& op);
        CQuaternion operator=(const CQuaternion<_T>&& op);
        
        CQuaternion operator+(const CQuaternion<_T>& op) const;
        CQuaternion operator-(const CQuaternion<_T>& op) const;
        
        /**
         * @brief This method multiplies two quaternions (Hamilton product).
        */
        CQuaternion operator*(const CQuaternion<_T>& op) const;
        
        /**
         * @brief This method computes its inverse with respect to the Hamilton product.
         *        q * q.Inverse() = 1
        */
        CQuaternion Invert() const;

        /**
         * @brief This method computes complex conjugate q*=a-bi-cj-dk of a quaternion q=a+bi+cj+dk.
        */
        CQuaternion Conjugate() const;

        CQuaternion Rotate(const CQuaternion<_T>& oQr) const;
        void ToEulerAngles(_T (&arfAngles)[3U]) const;
        CQuaternion<_T> ToQuaternion(const _T (arfAngles)[3U]);
        void ToRotationMatrix(_T (&arfRotation)[9U]) const;
        

        _T Norm() const;
        
        void Print();

    private:
        static const uint32_t m_u32N = 4U;
        _T m_arfQ[m_u32N];
    };

}

#endif      // __QUATERNION_BASE_H__
