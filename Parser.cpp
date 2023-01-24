#include "Parser.hpp"

Parser::Parser(int argc, char *argv[])
{
    int arg = 0;
    while (arg < argc)
    {
        arg++;
        string tmp(argv[arg]);
        if (tmp == "-f")
        {
            arg++;
            cowsource = argv[arg];
            flags.cowsource = true;
        }
        else if (tmp == "-c")
        {
            arg++;
            cloudsource = argv[arg];
            flags.cloudsource = true;
        }
        else if (tmp == "-s")
            flags.snow = true;
        else if (tmp == "-r")
            flags.rain = true;
        else while (arg < argc)
        {
            string tmp(argv[arg]);
            message += tmp;
            message += ' ';
            arg++;
        }
    }
}

Parser::~Parser() {}

string Parser::getCow()
{
    if (flags.cowsource)
        return cowsource;
    else
        return "cow";
}

string Parser::getCloud()
{
    if (flags.cloudsource)
        return cloudsource;
    else
        return "cloud";
}

char Parser::getFill()
{
    if (flags.snow)
        return '*';
    else if (flags.rain)
        return '.';
    else 
        return ' ';
}

string Parser::getMessage()
{
    return message;
}
