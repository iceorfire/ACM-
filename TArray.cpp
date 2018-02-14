//////////////////////////////////////////////////////
//                    ��״���� v1.0                 //
///////////////////Documentation//////////////////////
//                                                  //
// ά��һ�����У�֧�� logn ���޸ĺ� logn �Ĳ��ֺ�   //
//                                                  //
// 1. resize():   �޸����г��Ȳ�ȫ������Ϊ 0;       //
// 2. change():   �޸�����ĳ��λ�õ�ֵ;             //
// 3. alter():    ����ĳ��λ��Ԫ�ص�ֵ;             // 
// 4. getsum():   ��ȡ���е�ǰ n ���;              // 
// 5. getpart():  ��ȡ����һ������ҿ�����Ĳ��ֺ�; // 
//                                                  //
//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////

#include <iostream>
using namespace std;

template<int SZ>
class TArray {
    
    int     sum[SZ + 2];
    int     val[SZ + 2];
    int     size;

    static int lowbit( int x ) { return  x & ( x ^ ( x - 1 ) ); }

public:
       
    void resize( int sz ) {
        memset( this, 0, sizeof( *this ) );
        size = sz + 1;
    }
    
    void alter( int pos, int num ) {
        val[++pos] += num;
        while( pos <= size ) {
            sum[pos] += num;
            pos += lowbit( pos );
        }
    }
    
    void change( int pos, int num ) {
        num -= val[pos + 1];
        alter( pos, num ); 
    }

    int getsum( int pos ) const {
        int ans = 0;
        for( ++pos; pos > 0; pos -= lowbit( pos ) )
            ans += sum[pos];
        return  ans;
    }
    
    int getpart( int left, int right ) {
        return  getsum( right ) - getsum( left );
    } 

};

//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////

int main() {
    
    TArray<10>  array;
    
    array.resize( 10 );

    for( int i = 0; i < 10; ++i )
        array.change( i, i ); 
        
    for( int i = 0; i < 10; ++i )
        cout << array.getsum( i ) << endl; 

    array.change( 2, 10 );
    
    for( int i = 0; i < 10; ++i )
        cout << array.getsum( i ) << endl; 
    
    system( "pause" ); 
    
    
} 
