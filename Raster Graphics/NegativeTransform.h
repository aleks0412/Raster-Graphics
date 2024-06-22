#pragma once
#include "ITransform.h"

class NegativeTransform : public ITransform
{
public:
    void transformImage(Image& image) const override;
    ITransform* clone() const override;
};