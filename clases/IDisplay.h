#pragma once

class IDisplay
{
public:
    virtual void display() const = 0;
    virtual ~IDisplay() = default;
};
