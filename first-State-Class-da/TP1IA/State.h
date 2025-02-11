#pragma once
class Gun;

class State {
protected:
    Gun* gun;
public:
    State(Gun* gun) : gun(gun) {}

    virtual void Start() = 0;
    virtual void Update(float deltaTime) = 0;
};