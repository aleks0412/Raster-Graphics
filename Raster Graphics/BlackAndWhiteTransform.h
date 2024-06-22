#pragma once
#include "ITransform.h"

class BlackAndWhiteTransform : public ITransform
{
public:
    void transformImage(Image& image) const override;
    ITransform* clone() const override;
};