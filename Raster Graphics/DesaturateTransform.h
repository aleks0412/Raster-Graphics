#pragma once
#include "ITransform.h"

class DesaturateTransform : public ITransform
{
public:
    void transformImage(Image& image) const override;
};