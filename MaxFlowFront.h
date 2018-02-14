//////////////////////////////////////////////////////
//              �����(�ر�ǰ��) v1.0               //
///////////////////Documentation//////////////////////
//                                                  //
// 1. SZ:       ģ�������ȷ������ͼ��ģ;         //
// 2. init:     ����һ����Сһ���Ŀյ�������;       //
// 3. insert:   �����������һ����;                 //
// 4. maxFlow:  ���ָ��Դ-��������ֵ;            // 
//                                                  //
//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////

#include <algorithm>
#include <vector>
#include <list>
#include <deque>
using namespace std;

struct Edge {
    int     v,  w,  f,  c;
    Edge() {}
    Edge( int v, int w, int c, int f = 0 ) : v(v), w(w), c(c), f(f) {}
    int     next( int vv ) { return vv == v ? w : v; }
    int     remain( int vv ) { return vv == v ? c-f : f; }
    void    increase( int vv, int val ) { vv == v ? f += val : f -= val; }
};

template<int SZ, int BUF_SZ = SZ*SZ> 
class MaxFlow {
    
    int     size,   edges;
    vector<Edge*>   V[SZ+1];
    Edge    buf[BUF_SZ];
    // ����߶ȣ����������� 
    int     h[SZ+1],    e[SZ+1];
    // ��չ���� 
    list<int>   L;
    
    void initialize( int s, int t ) {
        memset( h, 0, sizeof( h ) );
        memset( e, 0, sizeof( e ) );
        h[s] = size;
        for( int i = 0; i < edges; ++i )
            buf[i].f = 0;
        L.clear();
        for( int i = 0; i <= size; ++i )
            if( i != s && i != t && !V[i].empty() )
                L.push_back( i );
        for( int i = 0; i < V[s].size(); ++i ) {
            if( V[s][i] -> remain( s ) ) {
                int v = V[s][i] -> next( s );
                e[v] = V[s][i] -> remain( s );
                e[s] -= e[v];
                V[s][i] -> increase( s, e[v] );
            }
        }
    }
    
    void discharge( int v ) {
        while( e[v] > 0 ) {
            for( int i = 0; i < V[v].size(); ++i ) {
                if( V[v][i] -> remain( v ) &&
                    h[v] == h[V[v][i] -> next( v )] + 1 )
                    push( v, V[v][i] );
                if( e[v] == 0 ) break;
            }
            if( e[v] )  relabel( v );
        }
    }
    
    void push( int v, Edge* edge ) {
        int flow = min( edge -> remain( v ), e[v] ); 
        int w = edge -> next( v );
        edge -> increase( v, flow );
        e[v] -= flow;
        e[w] += flow;
    }
    
    void relabel( int v ) {
        int height = INT_MAX;
        for( int i = 0; i < V[v].size(); ++i ) {
            int w = V[v][i] -> next( v );
            if( V[v][i] -> remain( v ) )
                height = min( h[w] + 1, height );
        }
        if( height != INT_MAX )
            h[v] = height;
    }
    
public:
    
    void init( int sz ) {
        for( int i = 0; i <= size; ++i )
            V[i].clear();
        size = sz;
        edges = 0;
    }
    
    void insert( int v, int w, int c ) {
        buf[edges++] = Edge( v, w, c );
        V[v].push_back( buf + edges - 1 );
        V[w].push_back( buf + edges - 1 );
    } 
        
    int maxFlow( int s, int t ) {
        initialize( s, t );
        list<int>::iterator now = L.begin();
        while( now != L.end() ) {
            int oldHeight = h[*now];
            discharge( *now );
            if( h[*now] > oldHeight ) {
                L.splice( L.begin(), L, now );
                now = L.begin();
            }
            ++now;
        }
        return  e[t];
    }
    
};

//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////
