#pragma once
#include "Image.h"
#include "ITransform.h"
#include "SubclassPtr.hpp"
#include "Vector.hpp"

class TransformedImage
{
public:
    TransformedImage() = default;
    TransformedImage(const Image& image);
    TransformedImage(Image&& image);

    void addTransform(const SubclassPtr<ITransform>& transform);
    void addTransform(SubclassPtr<ITransform>&& transform);
    void popTransform();
    void transformImage();

    const Image& getImage() const;
    Image& getImage();
private:
    Image image;
    Vector<SubclassPtr<ITransform>> transforms;
};