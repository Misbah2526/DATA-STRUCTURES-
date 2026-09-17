#include <iostream>
using namespace std;

int main()
{
    int a[50], n, x, value;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter values: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];


    // 1. Insert at END
    cout << "Enter value to insert at end: ";
    cin >> value;

    a[n] = value;
    n++;


    // 2. Insert at START
    cout << "Enter value to insert at start: ";
    cin >> value;

    for(int i = n; i > 0; i--)
        a[i] = a[i - 1];

    a[0] = value;
    n++;


    // 3. Insert AFTER a specific value
    cout << "Enter value after which you want to insert: ";
    cin >> x;

    cout << "Enter new value: ";
    cin >> value;

    for(int i = 0; i < n; i++)
    {
        if(a[i] == x)
        {
            for(int j = n; j > i + 1; j--)
                a[j] = a[j - 1];

            a[i + 1] = value;
            n++;
            break;
        }
    }


    // 4. Insert BEFORE a specific value
    cout << "Enter value before which you want to insert: ";
    cin >> x;

    cout << "Enter new value: ";
    cin >> value;

    for(int i = 0; i < n; i++)
    {
        if(a[i] == x)
        {
            for(int j = n; j > i; j--)
                a[j] = a[j - 1];

            a[i] = value;
            n++;
            break;
        }
    }


    // 5. Display
    cout << "Array List: ";

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;


    // 6. Delete from END
    n--;


    // 7. Delete from START
    for(int i = 0; i < n - 1; i++)
        a[i] = a[i + 1];

    n--;


    // 8. Delete specific value
    cout << "Enter value to delete: ";
    cin >> x;

    for(int i = 0; i < n; i++)
    {
        if(a[i] == x)
        {
            for(int j = i; j < n - 1; j++)
                a[j] = a[j + 1];

            n--;
            break;
        }
    }


    // Final List
    cout << "Final List: ";

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}