#include "regexer.h"
#include <regex>
#include <cstring>
#include <vector>
#include <QDebug>

RegExer::RegExer(QString regex, QString text):regex_pattern(regex), match_text(text){};

RegExer::~RegExer(){};

QString RegExer::match_pattern(){
    QString qstr_match = nullptr;
    std::regex rex;
    std::smatch match;
    std::string s = this->match_text.toUtf8().constData();
    std::string delim = "\n";

//    std::regex delim("[\n\r]+");

//    std::sregex_iterator begin =std::sregex_iterator(s.begin(),s.end(), delim);
//    auto end = std::sregex_iterator();
//    long nol = std::distance(begin, end);
//    std::string count_res = "found " + std::to_string(nol) + " lines.";

    size_t pos = 0;
    std::vector<std::string> lines;
    while((pos = s.find(delim)) != std::string::npos){
        lines.push_back(s.substr(0, pos));
        s.erase(0, pos + delim.length());
//        qInfo() << "test";
    }
    lines.push_back(s.substr(0,s.length()));

    bool debug = false;
    if (debug){
        return QString::fromStdString(std::to_string(lines.size()));
        //return QString::fromStdString(count_res);
    }

    try {
        rex.assign(this->regex_pattern.toUtf8().constData());
    } catch (const std::regex_error& e) {
        qstr_match = "Your RegEx has an Error: ";
        return qstr_match + e.what();
    }
    std::string res = "";
    qstr_match = "";
    for(auto s : lines){
        if ( std::regex_search(s, match, rex) ){
            std::string subres = "";
            for (unsigned i=1; i<match.size(); i++){
                subres += "group(" + std::to_string(i) + ")=";
                subres += match[i];
                subres += "; ";
            }
            qstr_match += QString::fromStdString(subres);
            qstr_match += "\n";
        }
    }
//    if ( std::regex_search(s, match, rex) ){
//        for (unsigned i=1; i<match.size(); i++){
//            res += "group(" + std::to_string(i) + ")=";
//            res += match[i];
//            res += "; ";
//        }
//        qstr_match = QString::fromStdString(res);
//    } else {
//        qstr_match = "nope, your regex sucks ass!";
//    }

    return qstr_match;
}

void RegExer::set_match_text(QString text){
    this->match_text = text;
}

QString RegExer::get_match_text(){
    return this->match_text;
}

void RegExer::set_regex_pattern(QString pattern){
    this->regex_pattern = pattern;
}

QString RegExer::get_regex_pattern(){
    return this->match_text;
}
