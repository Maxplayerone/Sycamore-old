#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include"../Utils/ErrorHandling.h"
#include"glm/glm.hpp"

struct ShaderSources {
    std::string vertexShader;
    std::string fragmentShader;
};

class Shader {
private:
    unsigned int m_ProgramID;

    ShaderSources ParseShader(const std::string& filepath);
    unsigned int CompileShader(unsigned int type, const std::string& source);
    unsigned int CreateProgram(const std::string& vertexSource, const std::string& fragmentSource);

    int GetUniformLocation(const std::string& name);
public:
    Shader(const std::string& filepath);
    ~Shader();

    void UseProgram();
    void UnuseProgram();

    void SetUniformMat4f(const std::string& uniformName, const glm::mat4 matrix);
};