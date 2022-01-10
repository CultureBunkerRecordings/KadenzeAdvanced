/*
  ==============================================================================

    KAPHelpers.h
    Created: 5 Dec 2021 9:56:17pm
    Author:  William

  ==============================================================================
*/

#pragma once

#define ParameterSmoothBlock 0.04f
#define ParameterSmoothSample 0.002f


const static int MaxBufferSize = 192000;

inline float KAPLinearInterpolation(float v0, float v1, float t)
{
    return (1 - t)* v0 + t * v1;
}
