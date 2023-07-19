#pragma once

#include "ShadingStrategy.hh"

class ColorShadow : public ShadingStrategy
{
public:
    ColorShadow(){}
    vec3 shading(shared_ptr<Scene> scene, HitInfo& info, vec3 lookFrom, vector<shared_ptr<Light>> lights, vec3 globalLight) override;
    float computeShadow(shared_ptr<Scene> scene, shared_ptr<Light> light, vec3 point);
    ~ColorShadow() {}
};

