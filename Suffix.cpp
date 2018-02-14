/////////////////////////////////////////////////
//        �������ʽ��׺����׺ʵ�� v1.0        //
/////////////////////////////////////////////////
//  1. ���㷨����һ����׺�������ʽ�ַ���;     //
//  2. ����һ���ȼ۵ĺ�׺���ʽ�ַ���;         //
//  3. �����пո��Զ�����;                     //
//  4. �����Ԫ�Կո�ֽ�,����Ϊ���ֻ���ĸ;    //
//  5. ��׺���ʽ�ɹ��ַ�����ʶ���������;     //
/////////////////////////////////////////////////
//          2008 CopyRight(c) by elf           //
/////////////////////////////////////////////////

#include <iostream> 
#include <string>
#include <stack>
#include <cctype>
using namespace std;

string postfix( const string& exp ) {
    
//    exp += ' ';             // Sentinel
    
    char token;             // exp �е��ַ�
    stack<char> opStack;    // �����ջ
    string  postfixExp;     // ��׺���ʽ
    
    for( int i = 0; i < exp.length(); ++i ) {
        
        token = exp[i];

        switch( token ) {
            
            case ' ':
            break;
            
            case '(':
                opStack.push( token );
            break;
            
            case ')':
                while( opStack.top() != '(' ) {
                    postfixExp += opStack.top();
                    postfixExp += ' ';
                    opStack.pop();
                }
                opStack.pop();
            break;

            case '+': case '-': case '*': case '/': case '%':
                while( 1 ) {
                    if( opStack.empty()     ||
                        opStack.top() == '('  ||
                        ( token == '*' || token == '/' || token == '%' ) &&
                        ( opStack.top() == '+' || opStack.top() == '-' ) ) {
                        opStack.push( token );
                        break;
                    }
                    else {
                        postfixExp += opStack.top();
                        postfixExp += ' ';
                        opStack.pop();
                    }
                }
            break;

            default:        // ��������ǲ�����
                postfixExp += token;
                while( isalnum( exp[i + 1] ) )
                    postfixExp += exp[++i];
                postfixExp += ' ';

        }
        
    }
        
    while( !opStack.empty() ) {
        if( opStack.top() != '(' ) {
            postfixExp += opStack.top();
            postfixExp += ' ';
        }
        opStack.pop();
    }

        
    return  postfixExp;
    
}

// ��ʾ���� stdin ����һ���������ʽ��������׺��ʾ 
int main() {
    
    string s;
    while( getline( cin, s ) )
        cout << postfix( s ) << endl;
    
}
