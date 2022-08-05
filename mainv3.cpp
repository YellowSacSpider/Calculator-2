#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

enum ops{
    PLUS,
    MINUS,
    MUL,
    DIV,
};

std::vector<std::string> tokens;
std::vector<std::string> operators;
void advance(char** textptr)
{
    if((*textptr) != nullptr || (**textptr) == ' ') // ????
        (*textptr)++;
}

int parse(std::vector<std::string>& tokens)
{
    int value = 0;
    
    for(int i = 0; i < tokens.size(); i++){
        if(tokens[i] == "*"){
                        value = std::stoi(tokens[i+1]) * std::stoi(tokens[i-1]);
                        std::cout << value;
        }
        
    }
    
    // THERE IS GLITCH WITH + and -
    if(std::find(tokens.begin(), tokens.end(), "*") == tokens.end() && std::find(tokens.begin(), tokens.end(), "/") == tokens.end()){
        for(int i = 0; i < tokens.size(); i++){
        if(tokens[i] == "+"){
                if(!tokens[i+1].empty() && !tokens[i-1].empty()){
                    value = std::atoi(tokens[i-1].c_str()) + std::atoi(tokens[i+1].c_str());
                    tokens.erase(tokens.begin()+i+1);
                    tokens.erase(tokens.begin()+i);
                    tokens[i-1] = static_cast<std::string>(std::to_string(value));
                    //std::cout << tokens[i-1] << '\n';
                }
        }
       if(tokens[i] == "-"){
                        if(!tokens[i-1].empty()){
                            value = std::stoi(tokens[i-1]) - std::stoi(tokens[i+1]);
                            tokens.erase(tokens.begin()+i+1);
                            tokens.erase(tokens.begin()+i);
                            std::cout << value;
                            tokens[i-1] = static_cast<std::string>(std::to_string(value));
                        }else{
                            tokens.insert(tokens.begin(), "0");
                        }
                }
            }
    }
    
    
        return value;
}

void check(char** textptr, std::string& token) // to rewrite this śmietnik
{
            
    if(**textptr == '\0') 
    {
        tokens.emplace_back(token);
    }
    switch(**textptr)
    {
        case '+':
            tokens.emplace_back("+");
            token.clear();
            break;
        case '-':
            tokens.emplace_back("-");
            token.clear();
            break;
        case '*':
            tokens.emplace_back("*");
            token.clear();
            break;
        case '/':
            tokens.emplace_back("/");
            token.clear();
            break;
        case '0':
            token += '0';
            if(*(*textptr+1) == '+' || *(*textptr+1) == '-' || *(*textptr+1) == '*' || *(*textptr+1) == '/')
            {
                tokens.emplace_back(token);
                token.clear();
            }
            break;
        case '1':
            token += '1';
            if(*(*textptr+1) == '+' || *(*textptr+1) == '-' || *(*textptr+1) == '*' || *(*textptr+1) == '/')
            {
                tokens.emplace_back(token);
            }
                
            break;
        case '2':
            token += '2';
            if(*(*textptr+1) == '+' || *(*textptr+1) == '-' || *(*textptr+1) == '*' || *(*textptr+1) == '/')
            {
                tokens.emplace_back(token);
            }
            break;
        case '3':
            token += '3';
            if(*(*textptr+1) == '+' || *(*textptr+1) == '-' || *(*textptr+1) == '*' || *(*textptr+1) == '/')
            {
                tokens.emplace_back(token);
            }
            break;
        case '4':
            token += '4';
            if(*(*textptr+1) == '+' || *(*textptr+1) == '-' || *(*textptr+1) == '*' || *(*textptr+1) == '/')
            {
                tokens.emplace_back(token);
            }
            break;
        case '5':
            token += '5';
            if(*(*textptr+1) == '+' || *(*textptr+1) == '-' || *(*textptr+1) == '*' || *(*textptr+1) == '/')
            {
                tokens.emplace_back(token);
            }
            break;
        case '6':
            token += '6';
            if(*(*textptr+1) == '+' || *(*textptr+1) == '-' || *(*textptr+1) == '*' || *(*textptr+1) == '/')
            {
                tokens.emplace_back(token);
            }
            break;
        case '7':
            token += '7';
            if(*(*textptr+1) == '+' || *(*textptr+1) == '-' || *(*textptr+1) == '*' || *(*textptr+1) == '/')
            {
                tokens.emplace_back(token);
            }
            break;
        case '8':
            token += '8';
            if(*(*textptr+1) == '+' || *(*textptr+1) == '-' || *(*textptr+1) == '*' || *(*textptr+1) == '/')
            {
                tokens.emplace_back(token);
            }
            break;
        case '9':
            token += '9';
            if(*(*textptr+1) == '+' || *(*textptr+1) == '-' || *(*textptr+1) == '*' || *(*textptr+1) == '/')
            {
                tokens.emplace_back(token);
            }
            break;
        
            
    }
}

int main()
{
    //std::string code = "88 * 3 + 4 / 2 + 800";
    std::string code = "";
    char* textptr = &code[0];
    std::string token = "";
    while(true){
        std::cout << ">> ";
        std::cin >> code;
        textptr = &code[0];
        while(true){
            if(*textptr == '\0') //check dupy
            {
                check(&textptr, token);
                break;
            }
            check(&textptr, token);
            advance(&textptr);
        }
        
        while(tokens.size() != 1){
            std::cout << '{';
            for(const auto& val : tokens)
                std::cout << val;
            std::cout << '}';
            parse(tokens);
            std::cout << '\n';
            
        }
            
        
        for(const auto& val : tokens)
            std::cout << val;
            
        std::cout << '\n';
    
        tokens.clear();
        token.clear();
    }
 
    return 0;
}