#ifndef REGEXER_H
#define REGEXER_H
#include "QString"
#include <regex>

class RegExer
{
public:
    RegExer(QString regex, QString text);
    RegExer();
    ~RegExer();

    QString match_pattern();
    void set_regex_pattern(QString pattern);
    void set_match_text(QString text);
    QString get_regex_pattern();
    QString get_match_text();
private:
    QString regex_pattern;
    QString match_text;
    std::regex rex;
};

#endif // REGEXER_H
