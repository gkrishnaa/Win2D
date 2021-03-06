// Copyright (c) Microsoft Corporation. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may
// not use these files except in compliance with the License. You may obtain
// a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
// License for the specific language governing permissions and limitations
// under the License.

#include "pch.h"
#include "CanvasBrush.h"

namespace ABI { namespace Microsoft { namespace Graphics { namespace Canvas
{
    using ABI::Windows::UI::Color;
    using namespace ABI::Windows::Foundation;
    using namespace ::Microsoft::WRL::Wrappers;

    IFACEMETHODIMP CanvasBrush::get_Opacity(float *value)
    {
        return ExceptionBoundary(
            [&]()
            {
                CheckInPointer(value);
                *value = GetD2DBrush(nullptr, false)->GetOpacity();
            });
    }

    IFACEMETHODIMP CanvasBrush::put_Opacity(float value)
    {
        return ExceptionBoundary(
            [&]()
            {
                GetD2DBrush(nullptr, false)->SetOpacity(value);
            });
    }


    IFACEMETHODIMP CanvasBrush::get_Transform(Numerics::Matrix3x2 *value)
    {
        return ExceptionBoundary(
            [&]()
            {
                CheckInPointer(value);

                GetD2DBrush(nullptr, false)->GetTransform(ReinterpretAs<D2D1_MATRIX_3X2_F*>(value));
            });
    }

    IFACEMETHODIMP CanvasBrush::put_Transform(Numerics::Matrix3x2 value)
    {
        return ExceptionBoundary(
            [&]()
            {
                GetD2DBrush(nullptr, false)->SetTransform(ReinterpretAs<D2D1_MATRIX_3X2_F*>(&value));
            });
    }

    IFACEMETHODIMP CanvasBrush::get_Device(ICanvasDevice** value)
    {
        return ExceptionBoundary(
            [&]
            {
                CheckInPointer(value);
                ThrowIfFailed(m_device.EnsureNotClosed().CopyTo(value));
            });
    }

    void CanvasBrush::Close()
    {
        m_device.Close();
    }

} } } }
