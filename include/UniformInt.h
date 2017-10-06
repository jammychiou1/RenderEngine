#ifndef UNIFORMINT_H
#define UNIFORMINT_H

#include "Uniform.h"

class UniformInt : public Uniform
{
    public:
        UniformInt(const std::string& name);
        virtual ~UniformInt();

        void setInt(int integer) {_integer = integer;}
        void load() override;

    private:
        int _integer;
};

#endif // UNIFORMINT_H
