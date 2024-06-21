#pragma once
#include "TransformedImage.h"
#include "Vector.hpp"

class Session
{
public:
    Session() = default;

    void addImage(const Image& image);
    void addImage(Image&& image);
    const Image& getImage(size_t index) const;
    Image& getImage(size_t index);

    void addTransform(const SubclassPtr<ITransform>& transform);
    void addTransform(SubclassPtr<ITransform>&& transform);
    void popTransform();
    void transformImages();

private:
    Vector<TransformedImage> images;
};