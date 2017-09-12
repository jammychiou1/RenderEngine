#ifndef UNIFORM_H
#define UNIFORM_H

#include <GL/glew.h>

#include <string>

class Uniform
{
    public:
        Uniform(const std::string& name);
        virtual ~Uniform();

        void setHandle(GLint handle) {_handle = handle;}
        const std::string& getName() {return _name;}

        virtual void load() = 0;

    protected:
        GLint _handle;
        std::string _name;
};

#endif // UNIFORM_H
