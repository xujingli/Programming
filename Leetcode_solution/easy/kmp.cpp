/**�ô���ο� ���ݽṹ��C���԰棩 ��ε�� ��ΰ�� ������
 * @filename      kmp.cc
 * @Synopsis      KMP algorithm 
 * @author       XIU
 * @version      1
 * @date         2016-04-21
 */
// �˴��������õ����飬�������ַ������Ǵ��±�1��ʼ

#include<iostream>
#include<string.h>

using namespace std;

/* ============================================================================*/
/**
 * @Synopsis      the next index data of the model string s_mode
 *
 * @Param         s_mode: the string
 * @Param         next  : the next array
 * @Param         len   : the length of the string
 */
/* ============================================================================*/
void get_next( string s_mode, int *next, int len )
{
    int i = 1;
    int j = 0;
    next[1] = 0;

    //cout << len << endl;
    while( i<len )
    {
        if( j==0 || s_mode[i] == s_mode[j] )
        {
            ++i;
            ++j;
            if( i>len ) break;
            next[i] = j;
            if( j>len ) break;
            //�������������next�㷨��nextval����
            /*
            if( s_mode[i] != s_mode[j]) 
                next[i] = j;
            else next[i] = next[j];
            */
        }
        else
        {
            j = next[j];
        }
    }
    for( int i=1; i<len; i++ )
    {
        cout << next[i] << " ";
    }

    cout << endl; 

}

/* ============================================================================*/
/**
 * @Synopsis      ����ģʽ��s_mode�е�next������s_model������ s_primary�е�pos���ַ�֮���λ��
 *
 * @Param         s_primary
 * @Param         s_mode
 * @Param         pos
 * @Param         next
 *
 * @Returns       
 */
/* ============================================================================*/
int Index_KMP( string s_primary, string s_mode, int pos, int *next )
{
    int i = pos;
    int j = 1;

    int len_p = s_primary.size();
    int len_m = s_mode.size();

    while( i < len_p && j < len_m )
    {

        if( j == 0 || s_primary[i] == s_mode[j] )
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }

    if( j >= len_m )
        return i - len_m;
    else
        return 0;
}

/* ============================================================================*/
/**
 * @Synopsis      output function to check the result
 *
 * @Param         s_primary
 * @Param         s_mode
 * @Param         len
 * @Param         next
 * @Param         index
 */
/* ============================================================================*/
void output( string s_primary, string s_mode, int len, int *next, int index )
{
    cout << "s_primary = " << s_primary << endl;
    cout << "s_mode = " << s_mode << endl;

    for( int i=1; i<len; i++ )
    {
        cout << next[i] << " ";
    }

    cout << endl; 

    cout << "index = " << index << endl;

}
int main()
{
    string s_primary = " acabaabaabcacaabc";
    string s_mode    = " abaabcac";
    int len = s_mode.size() ;

    int *next = new int[len];

    get_next( s_mode, next, len );

    int tmp = Index_KMP( s_primary, s_mode, 1, next );

    output( s_primary, s_mode, len, next, tmp );


    delete [] next;
    return 0;
}
