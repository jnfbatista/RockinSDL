#pragma once
#include <vector>

class Drawable
{
	std::vector<Drawable> *children;

	Drawable* parent;

public:

	~Drawable();

	virtual bool Render() = 0;

	Drawable* getParent() {  return parent; }
	std::vector<Drawable>* getChildren() { return children; }
};

