#include <iostream>
using namespace std;

int main()
{
    char a[500];
    char word_longest[500];
    char current_word[500];
    int max = 0;
    
    cin.getline(a, 500);
    
    for ( int i = 0, j = 0; a[i] != '\0'; i++ )
    {
        if ( a[i] != ' ' && a[i] != '.')
        {
            current_word[j] = a[i];
            j++;
            continue;
        }
        if ( a[i] == ' ' || a[i] == '.')
        {
            if ( j > max )
            {
                max = j;
                for ( int k = 0; k < j; k++ )
                {
                    word_longest[k] = current_word[k];
                }
            }
            
            j = 0;
        }
    }
    
    for ( int k = 0; k < max; k++ )
        cout << word_longest[k];
    
    cout << endl;
    
    return 0;
}