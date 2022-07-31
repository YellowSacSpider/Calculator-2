#include <iostream>
#include <vector>

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
void parse(std::vector<std::string>& tokens)
{
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
            tokens.emplace_back(token);
            token = '+';
            tokens.emplace_back(token);
            token.clear();
            break;
        case '-':
            tokens.emplace_back(token);
            token = '-';
            tokens.emplace_back(token);
            token.clear();
            break;
        case '*':
            tokens.emplace_back(token);
            token = '*';
            tokens.emplace_back(token);
            token.clear();
            break;
        case '/':
            tokens.emplace_back(token);
            token = '/';
            tokens.emplace_back(token);
            token.clear();
            break;
        case '0':
            token += '0';
            break;
        case '1':
            token += '1';
            break;
        case '2':
            token += '2';
            break;
        case '3':
            token += '3';
            break;
        case '4':
            token += '4';
            break;
        case '5':
            token += '5';
            break;
        case '6':
            token += '6';
            break;
        case '7':
            token += '7';
            break;
        case '8':
            token += '8';
            break;
        case '9':
            token += '9';
            break;
        
            
    }
}

int main()
{
    std::string code = "88 * 3 + 5 / 20 + 800";
    char* textptr = &code[0];
    std::string token = "";
    while(true){
        if(*textptr == '\0') //check dupy
        {
            check(&textptr, token);
            break;
        }
        check(&textptr, token);
        advance(&textptr);
    }
    std::cout << tokens[8];
 
    return 0;
}