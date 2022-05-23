// Copyright (c) 2008-2022 the Urho3D project
// Copyright © Amer Koleci and Contributors.
// Licensed under the MIT License (MIT). See LICENSE in the repository root for more information.

#include "../Precompiled.h"

#include "../Graphics/Graphics.h"
#include "../GraphicsAPI/Shader.h"
#include "../GraphicsAPI/ShaderVariation.h"

#include "../DebugNew.h"

using namespace Urho3D;

ShaderParameter::ShaderParameter(const String& name, unsigned glType, int location) :   // NOLINT(hicpp-member-init)
    name_{name},
    glType_{glType},
    location_{location}
{
}

ShaderParameter::ShaderParameter(ShaderType type, const String& name, unsigned offset, unsigned size, unsigned buffer) :    // NOLINT(hicpp-member-init)
    type_{type},
    name_{name},
    offset_{offset},
    size_{size},
    buffer_{buffer}
{
}

ShaderVariation::ShaderVariation(Shader* owner, ShaderType type)
    : GPUObject(owner->GetSubsystem<Graphics>())
    , owner_(owner)
    , type_(type)
{
}

ShaderVariation::~ShaderVariation()
{
    Release();
}

void ShaderVariation::SetName(const String& name)
{
    name_ = name;
}

Shader* ShaderVariation::GetOwner() const
{
    return owner_;
}

void ShaderVariation::OnDeviceLost()
{
    GAPI gapi = Graphics::GetGAPI();

#ifdef URHO3D_OPENGL
    if (gapi == GAPI_OPENGL)
        return OnDeviceLost_OGL();
#endif

#ifdef URHO3D_D3D11
    if (gapi == GAPI_D3D11)
        return OnDeviceLost_D3D11();
#endif
}

void ShaderVariation::Release()
{
    GAPI gapi = Graphics::GetGAPI();

#ifdef URHO3D_OPENGL
    if (gapi == GAPI_OPENGL)
        return Release_OGL();
#endif

#ifdef URHO3D_D3D11
    if (gapi == GAPI_D3D11)
        return Release_D3D11();
#endif
}

bool ShaderVariation::Create()
{
    GAPI gapi = Graphics::GetGAPI();

#ifdef URHO3D_OPENGL
    if (gapi == GAPI_OPENGL)
        return Create_OGL();
#endif

#ifdef URHO3D_D3D11
    if (gapi == GAPI_D3D11)
        return Create_D3D11();
#endif

    return {}; // Prevent warning
}

void ShaderVariation::SetDefines(const String& defines)
{
    GAPI gapi = Graphics::GetGAPI();

#ifdef URHO3D_OPENGL
    if (gapi == GAPI_OPENGL)
        return SetDefines_OGL(defines);
#endif

#ifdef URHO3D_D3D11
    if (gapi == GAPI_D3D11)
        return SetDefines_D3D11(defines);
#endif
}
